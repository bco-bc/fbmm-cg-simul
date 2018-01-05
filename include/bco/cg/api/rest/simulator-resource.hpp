#ifndef SIMULATOR_RESOURCE_HPP
#define SIMULATOR_RESOURCE_HPP

#include <cppcms/application.h>  
#include <cppcms/service.h>

namespace bco {

  // Forward declarations.
  class SimulatorFacade;

  /**
   * REST Resource for calculations at "/simulator" (relative to topmost application).
   */
  class SimulatorResource : public cppcms::application {
  public:

    SimulatorResource(cppcms::service &service,
		      const std::shared_ptr<SimulatorFacade>& simulatorFacade);

    /**
     * Completes a calculation.
     */
    void compute();

  private:

    std::shared_ptr<SimulatorFacade> simulatorFacade_;
    
  };
}

#endif
