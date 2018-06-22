#include "bco/cg/cg.hpp"
#include <cmath>
#include <bits/stdc++.h>

namespace bco {

    SimulatorFactory* SimulatorFactory::make_simulator(std::string choice) {
	
    }
    
    int binomialCoeff(int n, int k)
    {
	int C[k+1];
	memset(C, 0, sizeof(C));
 
	C[0] = 1;  // nC0 is 1
 
	for (int i = 1; i <= n; i++)
	{
	    // Compute next row of pascal triangle using
	    // the previous row
	    for (int j = std::min(i, k); j > 0; j--) {
		C[j] = C[j] + C[j-1];
	    }
	}
	return C[k];
    }
    
    std::vector<double> craigApparatus(unsigned int nb_tubes, unsigned int nb_cycles,
				       std::vector<double> dist_coefs)
    {
	// Check the number of tube and cycle != 0	
	std::vector<double> fraction_vector(nb_tubes, 0.0);	
	for (unsigned int tube=0; tube<nb_tubes; tube++) {
	    double binome = bco::binomialCoeff(nb_cycles, tube);
	    for (double coeff : dist_coefs) {
		fraction_vector.at(tube) += binome*pow(coeff, tube)/pow(coeff+1, nb_cycles);
	    }
	}
	
	return fraction_vector;	
    }
   
}
