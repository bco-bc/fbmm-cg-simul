
#include "bco/cg/api/facade/simulator-facade.hpp"
#include "bco/cg/simulators/simulator-factory.hpp"

namespace bco {

    Results SimulatorFacade::compute(const Parameters& parameters)
    {
	auto simulator = SimulatorFactory::Create(parameters.get("simulator.name", "distribution"));
	Results results = simulator->compute(parameters);
	return results;
    }

    std::string SimulatorFacade::getParameters(const std::string& name)
    {
	return SimulatorFactory::GetMap()[name].defaultParameters;
    }

    std::vector<std::pair<std::string, std::string> > SimulatorFacade::getSimulatorList()
    {
	std::vector<std::pair<std::string, std::string> > list;
	for (auto& elem : SimulatorFactory::GetMap())
	{
	    list.push_back(std::pair<std::string, std::string>(elem.first,
							       elem.second.description));
	}
	return list;
    }
}
