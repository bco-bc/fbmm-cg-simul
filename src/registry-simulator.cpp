#include "bco/cg/infrastructure/registry-simulators.hpp"
#include "bco/cg/api/simulators/simulator.hpp"

namespace bco {  

  // Initialize all with nullptr.
  static std::shared_ptr<SimulatorFactory> simulatorFactory_(nullptr);

  std::shared_ptr<SimulatorFactory> RegistrySimulatorFactory::simulatorFactory()
  {
    if ( simulatorFactory_.get() == nullptr ) {
      simulatorFactory_ = std::make_shared<SimulatorFactory>();
    }
    return simulatorFactory_;
  }

}
