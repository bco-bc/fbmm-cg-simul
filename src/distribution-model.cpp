
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
	int num_tubes /*= parameters.get<int>("simulator.parameters.num_tubes")*/;
	int num_cycles /*= parameters.get<int>("simulator.parameters.num_cycles")*/;

	for (auto& param : parameters.get_child("simulator.parameters"))
	{
	    if (param.second.get<std::string>("name") == "num_cycles")
	    {
		num_cycles = param.second.get<float>("value");
		
	    }
	    if (param.second.get<std::string>("name") == "num_tubes")
	    {
		num_tubes = param.second.get<float>("value");
	    }
	}

	std::vector<std::pair<float, float> > output(num_tubes,
						     std::pair<float,float>(0.0, 0.0));
	
	for (int cycle; cycle < num_cycles; cycle++)
	{
	    for (int tube = 0; tube < num_tubes; tube++)
	    {
		float binome = this->binomialCoeff(cycle, tube);
		for (auto& compound : parameters.get_child("compounds"))
		{
		
		    float coeff = compound.second.get<float>("distribution");
		    
		    output.at(tube).first = tube;
		    output.at(tube).second = roundf(binome*1000.0*pow(coeff, tube)/pow(coeff+1, cycle))/1000.0;
		}
	    }
	}
	float sum = 0.0;
	for (auto& tube : output)
	{
	    sum += tube.second;
	}
	std::cout << sum << std::endl;
	Results results;
	results.data = output;
	return results;
    }
    
}
