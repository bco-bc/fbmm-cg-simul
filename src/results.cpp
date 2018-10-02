#include "bco/cg/results.hpp"

namespace bco {

  cppcms::json::value Results::toJson()
  {
    cppcms::json::value json;
    json["results"]["data"] = data;
    return json;
  }
}
