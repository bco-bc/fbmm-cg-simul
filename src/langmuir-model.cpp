
#include "bco/cg/simulators/langmuir-model.hpp"
#include <boost/foreach.hpp>


namespace bco {

    Results LangmuirModel::compute(const Parameters &parameters) {

	// BOOST_FOREACH(boost::property_tree::ptree::value_type &v,
	// 	      parameters.get_child("parameters.compounds"))
        // {
        //     assert(v.first.empty()); array elements have no names
        //     std::cout << v.second.data() << std::endl;
	// }
	
	// int nb_plates = 1000;
	// int nb_cycles = 500;
	// std::vector<double> coeffs{0.9, 1.6, 1.2, 1.0, 0.9};
	// std::vector<double> responses{0.1, 1.2, 1.0, 0.9, 0.8};
	
	// double r_max, coeff;
	
	// for (int plate=0; plate < nb_plates; plate++) {
	//     for (unsigned int i = 0; i < coeffs.size(); i++) {
	//         coeff = coeffs.at(i);
	//         r_max = (coeff*nb_cycles)/(coeff+1);
	// 	fraction_vector.at(plate) += std::round(((coeff+1)*exp(-pow(r_max-plate,2)*pow(coeff+1,2)/(2.0*nb_cycles*coeff)/sqrt(2.0*M_PI*coeff)))*responses.at(i));
	//     }
	// }

	std::vector<double> fraction_vector(100, 0.0);
	Results results;
	results.data = fraction_vector;
	return results;
    }

}
