#ifndef RESULTS_HPP
#define RESULTS_HPP

#include <cppcms/json.h>

namespace bco {

    /**
     * Holds results of a calculation carried out by simulator.
     */
    struct Results {
	std::string xlabel = "Time";
	std::string ylabel = "Concentration";
	std::vector<std::pair<float, float>> data;
	
	/**
	 * Returns JSON representation.
	 * @return JSON.
	 */
	cppcms::json::value toJson();
    };
}

#endif
