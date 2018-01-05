#include "bco/cg/api/rest/simulator-resource.hpp"
#include "bco/cg/api/rest/root-resource.hpp"
#include <cppcms/service.h>
#include <cppcms/applications_pool.h>
#include <cppcms/json.h>
#include <booster/log.h>
#include <iostream>
#include <stdexcept>

using namespace bco;

int main(int argc, char** argv)
{
  const std::string appName = "cg-simulator";
  
  try {
    // Initialize.
    cppcms::service service(argc, argv);

    // Log some information.
    cppcms::json::value settings = service.settings();
    cppcms::json::value port = settings["service"]["port"];
    BOOSTER_INFO(appName.c_str()) << "Listening to port " << port;

    // Start.
    service.applications_pool().mount(cppcms::applications_factory<RootResource>());
    service.run();
  } catch (const std::exception& exception) {
    BOOSTER_ERROR(appName.c_str()) << exception.what();
  }
}
