#include "bco/cg/results.hpp"

namespace bco {

    cppcms::json::value Results::toJson()
    {
	cppcms::json::value json;
        json["xlabel"] = xlabel;
	json["ylabel"] = ylabel;
	cppcms::json::array pairlist;
	cppcms::json::value point;
	for (auto& pair : data)
	{
	    point["x"] = pair.first;
	    point["y"] = pair.second;
	    pairlist.push_back(point);
	}
	json["data"] = pairlist;    
	return json;
    }
}
