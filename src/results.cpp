#include "bco/cg/api/results.hpp"

namespace bco {

  cppcms::json::value Results::toJson()
  {
    cppcms::json::value json;
    json["results"]["pressure"] = "1";
    json["results"]["temperature"] = "273";
    return json;
  }
}
