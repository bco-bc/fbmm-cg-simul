#ifndef CG_HPP
#define CG_HPP

#include <vector>
#include <string>

/**
 * Biocenter Oulu
 */
namespace bco {
    
    class SimulatorFactory
    {
    public:
	static SimulatorFactory *make_simulator(std::string );
	virtual void simulate() = 0;
	
    };

    class CraigApparatus: public SimulatorFactory
    {
    public:
	void simulate();
    };

    class HPLC: public SimulatorFactory
    {
    public:
	void simulate();
    };
    
    int binomialCoeff(int n, int k);
    std::vector<double> craigApparatus(unsigned int nb_tubes, unsigned int nb_cycles,
				       std::vector<double> dist_coefs);
    
}

#endif
