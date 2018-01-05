#include "bco/cg/infrastructure/registry.hpp"
#include "bco/cg/api/facade/simulator-facade.hpp"

namespace bco {  

  // Initialize all with nullptr.
  static std::shared_ptr<SimulatorFacade> simulatorFacade_(nullptr);

  std::shared_ptr<SimulatorFacade> Registry::simulatorFacade()
  {
    if ( simulatorFacade_.get() == nullptr ) {
      simulatorFacade_ = std::make_shared<SimulatorFacade>();
    }
    return simulatorFacade_;
  }

}
