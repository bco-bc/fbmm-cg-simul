#include "bco/cg/cg.hpp"
#include <cmath>
#include <bits/stdc++.h>


namespace bco {

    double binomialCoeff(int n, int k)
    {
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
    
    Simulator* Simulator::make_simulator(int choice) {
	switch (choice) {
	case 0: return new CraigApparatus;
	case 1: return new VanDeemter;
	default: return new CraigApparatus;
	}
    }

    double CraigApparatus::binomialCoeff(int n, int k) {
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
    
    std::vector<double> CraigApparatus::simulate(ptree &inputs) {
	
	unsigned int nb_tubes = inputs.get<unsigned int>("nb_tubes");
	unsigned int nb_cycles = inputs.get<unsigned int>("nb_cycles");
	std::vector<double> coeffs = as_vector<double>(inputs, "distribution_coeffs");
	
	std::vector<double> fraction_vector(nb_tubes, 0.0);
	
	for (unsigned int tube=0; tube<nb_tubes; tube++) {
	    double binome = this->binomialCoeff(nb_cycles, tube);
	    for (ptree::value_type &coeffs : inputs.get_child("distribution_coeffs")) {
		double coeff = coeffs.second.get_value<double>();
		fraction_vector.at(tube) += binome*pow(coeff, tube)/pow(coeff+1, nb_cycles);
	    }
	}
	
	return fraction_vector;
    }
    
    std::vector<double> VanDeemter::simulate(ptree &inputs) {
	
	unsigned int nb_tubes = inputs.get<unsigned int>("nb_tubes");
	unsigned int nb_cycles = inputs.get<unsigned int>("nb_cycles");
	std::vector<double> coeffs = as_vector<double>(inputs, "distribution_coeffs");
	std::vector<double> responses = as_vector<double>(inputs, "response_factors");
	
	std::vector<double> fraction_vector(nb_tubes, 0.0);
	
	for (unsigned int tube=0; tube<nb_tubes; tube++) {
	    for (unsigned int i = 0; i < coeffs.size(); i++) {
		double coeff = coeffs.at(i);
		double r_max = (coeff*nb_cycles)/(coeff+1);
		fraction_vector.at(tube) += ((coeff+1)*exp(-pow(r_max-tube,2)*pow(coeff+1,2)/(2.0*nb_cycles*coeff)/sqrt(2.0*M_PI*coeff)))*responses.at(i);
	    }
	}
	
	return fraction_vector;
    }

    std::vector<double> HPLC::simulate(ptree &inputs) {
	return std::vector<double>(3, 1.0); 
    }
}
