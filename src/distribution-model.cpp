
#include "bco/cg/simulators/distribution-model.hpp"

namespace bco {

    double DistributionModel::binomialCoeff(int n, int k) {
	double res = 1;
 
	// Since C(n, k) = C(n, n-k)
	if ( k > n - k )
	    k = n - k;
 
	// Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
	for (int i = 0; i < k; ++i)
	{
	    res *= (n - i);
	    res /= (i + 1);
	}
 
	return res;
    }
    
    Results DistributionModel::compute(const Parameters &parameters)
    {
        // int nb_tubes = 20;
	// int nb_cycles = 5;
	// std::vector<double> coeffs{/*0.5/*,*/ 3.5};
	// std::vector<double> fraction_vector(nb_tubes, 0.0);
	// double binome;

	// for (int tube = 0; tube < nb_tubes; tube++) {
	//     binome = this->binomialCoeff(nb_cycles, tube);
	//     for (auto coeff : coeffs ) {
	// 	fraction_vector.at(tube) += std::round(binome*(pow(coeff, tube)/pow(coeff+1.0, nb_cycles)));
	//     }
	// }

	std::vector<double> fraction_vector(100, 0.0);
	Results results;
	results.data = fraction_vector;
	return results;
    }
    
}
