#ifndef SIMULATOR_FACADE_HPP
#define SIMULATOR_FACADE_HPP

#include "bco/cg/results.hpp"
#include "bco/cg/parameters.hpp"

namespace bco {  

  /**
   * Simplified interface to simulator.
   */
    class SimulatorFacade {

    /**!
     * Performs a calculation.
     * @return Calculation results.
     */
    public:
	Results compute(const Parameters& parameters);
	std::string getParameters(const std::string& name);
	std::vector<std::pair<std::string, std::string> > getSimulatorList();
	
  };
  
}

#endif
