#include "bco/cg/api/rest/simulator-resource.hpp"
#include "bco/cg/api/facade/simulator-facade.hpp"
#include <cppcms/url_dispatcher.h>  
#include <cppcms/url_mapper.h>
#include <cppcms/http_response.h>  
#include <cppcms/json.h>
#include <booster/log.h>

namespace bco {

  SimulatorResource::SimulatorResource(cppcms::service &service,
				       const std::shared_ptr<SimulatorFacade>& simulatorFacade) :
    cppcms::application(service), simulatorFacade_(simulatorFacade)
  {
    dispatcher().assign("", &SimulatorResource::compute, this);  
    mapper().assign("");
    
    mapper().root("/simulator");
    BOOSTER_INFO("SimulatorResource") << "Mapped to /simulator relative to root resource.";
  }

  void SimulatorResource::compute()
  {
    Results results = simulatorFacade_->compute();
    cppcms::json::value json;
    json["status"] = "success";
    json["data"] = results.toJson();
    response().content_type("application/json");
    response().out() << json;
  }
};
