#include "bco/cg/cg.hpp"
#include <iostream>
#include <fstream>

using namespace bco;

/* 
 *Implements Unit test for the Craig Apparatus Simulator 
 */


int main(int argc, char** argv)
{
    std::cout << "Chromatography test" << std::endl;    

    ptree config;
    boost::property_tree::read_json("../tests/inputs.json", config);
    
    Simulator* simulator = Simulator::make_simulator(0);
    
    std::vector<double> fraction_vector;

    std::ofstream outfile("test-results.txt");
    fraction_vector = simulator->simulate(config);
    for (auto elem : fraction_vector) {
	outfile << elem << ",";
    }
    outfile << std::endl;
    outfile.close();
}
