#include "bco/cg/api/rest/simulator-resource.hpp"
#include "bco/cg/api/facade/simulator-facade.hpp"
#include <cppcms/url_dispatcher.h>  
#include <cppcms/url_mapper.h>
#include <cppcms/http_response.h>
#include <cppcms/http_request.h>
#include <cppcms/json.h>
#include <booster/log.h>


namespace bco {

    SimulatorResource::SimulatorResource(cppcms::service &service,
					 const std::shared_ptr<SimulatorFacade>& simulatorFacade) :
	cppcms::application(service), simulatorFacade_(simulatorFacade)
    {
	
	dispatcher().map("GET","", &SimulatorResource::getSimulators, this);

	dispatcher().map("GET","/(\\w+)", &SimulatorResource::getParameters, this, 1);	

	dispatcher().map("POST", "/(\\w+)", &SimulatorResource::compute, this, 1);
	
	mapper().root("/simulators");
	BOOSTER_INFO("SimulatorResource") << "Mapped to /simulators relative to root resource.";
    }

    void SimulatorResource::getSimulators()
    {
	cppcms::json::value simulator;
	cppcms::json::array array;
        
	for (auto& elem : simulatorFacade_->getSimulatorList())
	{
	    simulator["name"] = elem.first;
	    simulator["description"] = elem.second;
	    array.push_back(simulator);
	}
	
	response().content_type("application/json");
	response().out() << array;
    }

    void SimulatorResource::getParameters(std::string name)
    {

	std::string stg = simulatorFacade_->getParameters(name);
	response().content_type("application/json");
	response().out() << stg;
    }
    
    void SimulatorResource::compute(std::string name)
    {	
	// Request JSON
        std::pair<void *, size_t> post_data = request().raw_post_data();
	std::stringstream ss(std::string(reinterpret_cast<char const *>(post_data.first),
					  post_data.second));
	// Loading JSON
	cppcms::json::value json;
	if (!json.load(ss, true))
	{
	    throw("Invalid JSON");
	}

	// Convertion JSON to Parameters
	Parameters parameters;
	try {
	    std::stringstream ss1;
	    ss1 << json;
	    boost::property_tree::read_json(ss1, parameters);
	}
	catch(std::exception & e)
	{
	    throw("Could not read JSON");
	}

	if (name != parameters.get<std::string>("simulator.name"))
	{
	    throw("JSON simulator "+
		  parameters.get<std::string>("simulator.name")
		  +" does not match url name"+name);
	}
	
	// Compute 
	Results results = simulatorFacade_->compute(parameters);

	// Output JSON
	json["results"] = results.toJson();
	response().content_type("application/json");
	response().out() << json;
    }

};
