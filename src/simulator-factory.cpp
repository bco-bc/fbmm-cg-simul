
#include "bco/cg/simulators/simulator-factory.hpp"

namespace bco {

    std::map<std::string, SimulatorImplInfo> SimulatorFactory::simulator_map;
    
    std::unique_ptr<AbstractSimulator> SimulatorFactory::Create(const std::string& name)
    {
	    auto it = simulator_map.find(name);
	    return it == simulator_map.end() ? nullptr : (it->second.createFunc)();
    }

    std::string SimulatorFactory::Info(const std::string& name)
    {
	    auto it = simulator_map.find(name);
	    return it == simulator_map.end() ? nullptr : (it->second.description);
    }

    std::map<std::string, SimulatorImplInfo> SimulatorFactory::GetMap()
    {
	    return simulator_map;
    }
}
