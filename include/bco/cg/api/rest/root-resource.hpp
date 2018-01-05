#ifndef ROOT_RESOURCE_HPP
#define ROOT_RESOURCE_HPP

#include <cppcms/application.h>  
#include <cppcms/service.h>

namespace bco {

  /**
   * Topmost (root) resource.
   */
  class RootResource : public cppcms::application {
  public:

    RootResource(cppcms::service &service);

    /**
     * Application status. Returns JSON according to the JSend format.
     * @see <a href="https://labs.omniti.com/labs/jsend">JSend</a>
     */
    void status();
  };
}

#endif
