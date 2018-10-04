
#include "bco/cg/simulators/distribution-model.hpp"

#include <math.h>

namespace bco {

    double DistributionModel::binomialCoeff(int n, int k) {
	double res = 1;
	if ( k > n )
	{
	    res = 0;
	    return res;
	}
	
	// Since C(n, k) = C(n, n-k)
	if ( k > n - k )
	{
	    k = n - k;
	}
	
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
	// Gather parameters
	int num_tubes;
	int num_cycles;
	std::vector<float> coeffs;
	Results results;
	
	// Global simulator parameters
	for (auto& param : parameters.get_child("simulator.parameters"))
	{
	    if (param.second.get<std::string>("name") == "num_cycles")
	    {
		num_cycles = param.second.get("value", 10); // default : num_cycles = 10
		
	    }
	    if (param.second.get<std::string>("name") == "num_tubes")
	    {
		num_tubes = param.second.get("value", 20); // default : num_tubes = 20
	    }
	}
	std::vector<std::pair<float, float> > output(num_tubes,
						     std::pair<float,float>(0.0, 0.0));
	// Compounds parameters setup
	for (auto& compound : parameters.get_child("compounds"))
	{
	    coeffs.push_back(compound.second.get<float>("distribution"));
	}
	
	if (coeffs.empty())
	{
	    throw("No compounds distribution parameters");
	    results.data = output;
	    return results;
	}

	// Simulation loop
	std::vector <std::vector<float> > fractionVector(coeffs.size(),
							 std::vector<float>(num_tubes));	
 	for (int cycle; cycle < num_cycles; cycle++)
	{
	    for (int tube = 0; tube < num_tubes; tube++)
	    {
		float binome = this->binomialCoeff(cycle, tube);
		for (int i = 0; i < coeffs.size(); i++)
		{	    
		    fractionVector.at(i).at(tube) = roundf(binome*1000.0*pow(coeffs.at(i), tube)
							   /pow(coeffs.at(i)+1, cycle))/1000.0;
		}
	    }
	}

	// Summing different fractions
	for (int tube = 0; tube < num_tubes; tube++)
	{
	    output.at(tube).first = tube;
	    for (int compound = 0; compound < coeffs.size(); compound++)
	    {
		output.at(tube).second += fractionVector.at(compound).at(tube);
	    }
	}
	
	// output in different sets
	results.data = output;
	return results;
    }
    
}
