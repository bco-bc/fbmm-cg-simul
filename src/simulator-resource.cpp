#include "bco/cg/api/rest/simulator-resource.hpp"

#include <cppcms/url_dispatcher.h>  
#include <cppcms/url_mapper.h>
#include <cppcms/http_response.h>  
#include <booster/log.h>

namespace bco {

  SimulatorResource::SimulatorResource(cppcms::service &service) : cppcms::application(service)
  {
    dispatcher().assign("", &SimulatorResource::compute, this);  
    mapper().assign("");
    
    mapper().root("/simulator");
    BOOSTER_INFO("SimulatorResource") << "Mapped to /simulator relative to root resource.";
  }

  void SimulatorResource::compute()
  {
    cppcms::json::value json;
    json["status"] = "success";
    json["data"]["something"] = "0.11";
    response().content_type("application/json");
    response().out() << json;
  }
};
