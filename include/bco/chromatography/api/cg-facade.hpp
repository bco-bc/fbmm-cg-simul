#ifndef CG_FACADE_HPP
#define CG_FACADE_HPP

namespace bco {

  /**
   * Main entrance into the simulator.
   */
  struct CgFacade {
    
    /**
     * Completes a calculation.
     */
    virtual void execute() = 0;
    
  };
  
}

#endif
