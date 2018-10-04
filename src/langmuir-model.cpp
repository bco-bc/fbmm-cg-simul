
#include "bco/cg/simulators/langmuir-model.hpp"
#include <boost/foreach.hpp>


namespace bco {

    Results LangmuirModel::compute(const Parameters &parameters) {
	
        // Gather parameters
	int num_cycles /*= parameters.get<int>("simulator.parameters.num_tubes")*/;
	int num_plates /*= parameters.get<int>("simulator.parameters.num_cycles")*/;

	for (auto& param : parameters.get_child("simulator.parameters"))
	{
	    if (param.second.get<std::string>("name") == "num_cycles")
	    {
		num_cycles = param.second.get<float>("value");
		
	    }
	    if (param.second.get<std::string>("name") == "num_plates")
	    {
		num_plates = param.second.get<float>("value");
	    }
	}

	std::vector<std::pair<float, float> > output(num_plates);

	for (int cycle = 0; cycle < num_cycles; cycle++)
	{
	    for (int plate = 0; plate < num_plates; plate++)
	    {
		for (auto& compound : parameters.get_child("compounds"))
		{
		    float coeff = compound.second.get<float>("distribution");
		}
	    }
	}
	// for (int plate=0; plate < nb_plates; plate++) {
	//     for (unsigned int i = 0; i < coeffs.size(); i++) {
	//         coeff = coeffs.at(i);
	//         r_max = (coeff*nb_cycles)/(coeff+1);
	// 	fraction_vector.at(plate) += std::round(((coeff+1)*exp(-pow(r_max-plate,2)*pow(coeff+1,2)/(2.0*nb_cycles*coeff)/sqrt(2.0*M_PI*coeff)))*responses.at(i));
	//     }
	// }

	Results results;
	results.data = output;
	return results;
    }

}
