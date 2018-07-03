#ifndef SIMULATOR_FACADE_HPP
#define SIMULATOR_FACADE_HPP

#include "bco/cg/api/results.hpp"
#include "bco/cg/cg.hpp"

namespace bco {  

  /**
   * Simplified interface to simulator.
   */
    class SimulatorFacade {

    /**
     * Performs a calculation.
     * @return Calculation results.
     */
    public:
	Results compute();

    private:
	//std::shared_ptr<Simulator> simulator_;
  };
  
}

#endif
