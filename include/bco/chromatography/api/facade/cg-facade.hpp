#ifndef CG_FACADE_HPP
#define CG_FACADE_HPP

#include "../results.hpp"

namespace bco {  

  /**
   * Simplified interface to simulator.
   */
  class CgFacade {
    
    Results compute();
    
  };
  
}

#endif
