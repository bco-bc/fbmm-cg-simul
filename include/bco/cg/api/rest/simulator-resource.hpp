#ifndef SIMULATOR_RESOURCE_HPP
#define SIMULATOR_RESOURCE_HPP

#include <cppcms/application.h>  
#include <cppcms/service.h>

namespace bco {

  /**
   * REST Resource for calculations at "/simulator" (relative to topmost application).
   */
  class SimulatorResource : public cppcms::application {
  public:

    SimulatorResource(cppcms::service &service);

    /**
     * Completes a calculation.
     */
    void compute();
    
  };
}

#endif
