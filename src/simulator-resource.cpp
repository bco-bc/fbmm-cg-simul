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
	
	mapper().root("/simulator");
	BOOSTER_INFO("SimulatorResource") << "Mapped to /simulator relative to root resource.";
    }

    void SimulatorResource::getSimulators()
    {
	cppcms::json::value simulator;
	cppcms::json::array array;
        
	for (auto& elem : simulatorFacade_->getSimulatorList())
	{
	    simulator["name"] = elem.first;
	    simulator["description"]= elem.second;
	    array.push_back(simulator);
	}
	
	response().content_type("application/json");
	response().out() << array;
    }

    void SimulatorResource::getParameters(std::string name)
    {

	std::string stg = simulatorFacade_->getParameters(name);
	cppcms::json::value json;
	json["simulator"] = name;
	json["compounds"] = "plop";
	response().content_type("application/json");
	response().out() << stg;
    }
    
    void SimulatorResource::compute(std::string name)
    {	
	// Input part
        std::pair<void *, size_t> post_data = request().raw_post_data();
	std::stringstream ss(std::string(reinterpret_cast<char const *>(post_data.first),
					  post_data.second));
	cppcms::json::value inputs;
	if (!inputs.load(ss, true))
	{
	    throw("Invalid JSON");
	}
	
	Parameters parameters;
	try {
	    std::stringstream ss1;
	    ss1 << inputs;
	    boost::property_tree::read_json(ss1, parameters);
	}
	catch(std::exception & e)
	{
	    throw("Could not read JSON");
	}
	
	// Compute part
	Results results = simulatorFacade_->compute(parameters);

	cppcms::json::value json;
	json["status"] = "success";
	json["simulator"] = results.name;
	json["data"] = results.toJson();
	response().content_type("application/json");
	response().out() << json;
    }

};
