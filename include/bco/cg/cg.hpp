#ifndef CG_HPP
#define CG_HPP

#include <vector>
#include <string>
#include <map>
#include <cppcms/json.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

/**
 * Biocenter Oulu
 */
namespace bco {

    double binomialCoeff(int n, int k);
    
    using ptree = boost::property_tree::ptree;
    
    template <typename T>
    std::vector<T> as_vector(ptree const& pt, ptree::key_type const& key)
    {
	std::vector<T> r;
	for (auto& item : pt.get_child(key))
	    r.push_back(item.second.get_value<T>());
	return r;
    }
    
    class Simulator
    {
    public:
	static Simulator *make_simulator(int choice);
	virtual std::vector<double> simulate(ptree &inputs) = 0;
    };

    class CraigApparatus: public Simulator
    {
    public:
	std::vector<double> simulate(ptree &inputs);
    protected:
	double binomialCoeff(int n, int k);
    };

    class VanDeemter: public Simulator
    {
    public:
	std::vector<double> simulate(ptree &inputs);
    };

    class HPLC: public Simulator
    {
    public:
	std::vector<double> simulate(ptree &inputs);
    };
    
    std::vector<double> craigApparatus(unsigned int nb_tubes,
				       unsigned int nb_cycles,
				       std::vector<double> &dist_coefs);
    
    std::vector<double> vanDeemter(unsigned int nb_tubes,
				   unsigned int nb_cycles,
				   std::vector<double> &dist_coefs,
				   std::vector<double> &reponse_factor);
}

#endif
