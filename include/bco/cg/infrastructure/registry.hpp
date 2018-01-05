#ifndef REGISTRY_HPP
#define REGISTRY_HPP

#include <memory>

namespace bco {

  // Forward declarations.
  class SimulatorFacade;

  /**
   * Provides access to various components.
   */
  struct Registry {

    /**
     * Returns instance.
     * @return SimulatorFacade.
     */
    static std::shared_ptr<SimulatorFacade> simulatorFacade();
  };
}

#endif
