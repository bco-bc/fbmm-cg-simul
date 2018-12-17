
#include "bco/cg/simulators/langmuir-model.hpp"
#include <boost/foreach.hpp>


namespace bco {

    Results LangmuirModel::compute(const Parameters &parameters) {
	
        // Gather parameters
	int num_plates = 1000;
	int num_cycles = 100;
	std::vector<std::pair<float, float> > compounds;
	Results results;
	
	// Global simulator parameters
	for (auto& param : parameters.get_child("simulator.parameters")) {
	    if (param.second.get<std::string>("name") == "num_cycles") {
		num_cycles = param.second.get<int>("value"); // default : num_cycles = 100
		
	    }
	    if (param.second.get<std::string>("name") == "num_tubes") {
		num_plates = param.second.get<int>("value"); // default : num_plates = 1000
	    }
	}

	// Compounds parameters setup	
	for (auto& compound : parameters.get_child("compounds")) {
	    float distribution = compound.second.get<float>("distribution");
	    float response = compound.second.get<float>("response");
	    compounds.push_back(std::pair<float, float>(distribution, response));
	}
	
	std::vector<std::pair<float, float> > output;
	if (compounds.empty()) {
	    throw("No compounds distribution parameters");
	    results.data = output;
	    return results;
	}

	std::vector<std::vector<float> > fractionVector(compounds.size(), std::vector<float>(num_plates, 0.0));
	
	for (int cycle = 0; cycle < num_cycles; cycle++) {
	    float sum = 0.0;
	    for (unsigned int i = 0; i < compounds.size(); i++) {
		float distribution = compounds.at(i).first;
		float response = compounds.at(i).second;
		float r_max = num_cycles*distribution/(distribution+1);
		for (int plate = 0; plate < num_plates; plate++) {		    
		    float factor = (distribution+1.0)/sqrt(2.0*M_PI*num_cycles*distribution);
		    float exponent = -pow(r_max-plate,2)*pow(distribution+1, 2)/(2.0*cycle*distribution);
		    float fraction = factor/*exp(plate)*/;
		    fractionVector.at(i).at(plate) = fraction;
		}
		sum += response*fractionVector.at(i).back();
	    }
	    output.push_back(std::pair<float, float>(cycle, sum));
	}

	results.data = output;
	return results;
    }

}
