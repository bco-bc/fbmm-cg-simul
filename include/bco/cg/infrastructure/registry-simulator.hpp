#ifndef REGISTRY_HPP
#define REGISTRY_HPP

#include <memory>

namespace bco {

  // Forward declarations.
  class SimulatorFactory;

  /**
   * Provides access to various components.
   */
  struct RegistrySimulatorFactory {

    /**
     * Returns instance.
     * @return SimulatorFactory.
     */
    static std::shared_ptr<SimulatorFactory> simulatorFactory();
  };
}

#endif
