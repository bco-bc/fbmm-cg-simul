#include "bco/cg/api/rest/root-resource.hpp"
#include "bco/cg/api/rest/simulator-resource.hpp"
#include "bco/cg/infrastructure/registry.hpp"
#include <cppcms/url_dispatcher.h>  
#include <cppcms/url_mapper.h>
#include <cppcms/http_response.h>
#include <cppcms/json.h>
#include <booster/log.h>


namespace bco {

  static cppcms::json::value version_ = "0.0";
  static cppcms::json::value copyright_ = "";

  RootResource::RootResource(cppcms::service &service) : cppcms::application(service)
  {
    cppcms::json::value settings = service.settings();
    version_ = settings["info"]["version"];
    copyright_ = settings["info"]["copyright"];

    std::shared_ptr<SimulatorFacade> simulatorFacade = Registry::simulatorFacade();
    attach(new SimulatorResource(service, simulatorFacade),  
	   "simulator", "/simulator{1}",   // mapping  
	   "/simulator(/(.*))?", 1);       // dispatching

    // default URL
    dispatcher().assign("", &RootResource::status, this);  
    mapper().assign("");
    
    mapper().root("/cgs");
    BOOSTER_INFO("RootResource") << "Mapped to /cgs";
  }

  void RootResource::status()    
  {
    cppcms::json::value json;
    json["status"] = "success";
    json["data"]["version"] = version_;
    json["data"]["copyright"] = copyright_;
    response().content_type("application/json; charset=utf-8");
    response().out() << json;
  }
}
