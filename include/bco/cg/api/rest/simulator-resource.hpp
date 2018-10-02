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
	 * Respond the list of simulator
	 */
	void getSimulators();

	/**
	 * Respond the parameters info of a selected simulator (by name) 
	 */
	void getParameters(std::string name);

	/**
	 * Completes a calculation.
	 */
	void compute(std::string name);

    private:
	std::shared_ptr<SimulatorFacade> simulatorFacade_;
    
    };
}

#endif
