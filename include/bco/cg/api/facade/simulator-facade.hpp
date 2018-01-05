#ifndef SIMULATOR_FACADE_HPP
#define SIMULATOR_FACADE_HPP

#include "bco/cg/api/results.hpp"

namespace bco {  

  /**
   * Simplified interface to simulator.
   */
  struct SimulatorFacade {

    /**
     * Performs a calculation.
     * @return Calculation results.
     */
    Results compute();
    
  };
  
}

#endif
