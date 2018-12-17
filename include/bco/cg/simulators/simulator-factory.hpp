#ifndef SIMULATORFACTORY_HPP
#define SIMULATORFACTORY_HPP

#include <memory>
#include <map>
#include <functional>

#include "bco/cg/simulators/abstract-simulator.hpp"

/**
 * Biocenter Oulu
 */
namespace bco {
    
    /**
     * Simulator Info struct 
     */
    struct SimulatorImplInfo {
	using CreateMethod = std::function<std::unique_ptr<AbstractSimulator>()>;
	CreateMethod createFunc;
	std::string description;
	std::string defaultParameters;
    };
    
    /**
     * Simulator Factory
     */
    class SimulatorFactory {
    public:	
        SimulatorFactory() = default;
	virtual ~SimulatorFactory() = default;

	/**
	 * Returns instance of Simulator.
	 * @return Simulator
	 */
	static std::unique_ptr<AbstractSimulator> Create(const std::string& name);

	/**
	 * Returns a string descibing the selected simulator.
	 * @return std::string
	 */
	static std::string Info(const std::string& name);

        /**
	 * Returns a map containing Simulator Implementation complete information.
	 * @return std::map<std::string, SimulatorImplInfo> 
	 */
	static std::map<std::string, SimulatorImplInfo> GetMap();
	
	/** 
	 * Self register function.
	 * @return std::function<std::unique_ptr<Simulator>() > >.
	 */
	template <typename T>
	static bool Register(const std::string name,
			     const std::string desc,
			     const std::string params) {
	    auto it = simulator_map.find(name);
	    if (it == simulator_map.end()) { 
	        simulator_map[name] = {[]() -> std::unique_ptr<AbstractSimulator> {
						       return std::make_unique<T>();},
				       desc,
				       params
		};
		return true;
	    }
	    return false;
	}
	
    private:
	static std::map<std::string, SimulatorImplInfo> simulator_map;
    };

}

#endif
