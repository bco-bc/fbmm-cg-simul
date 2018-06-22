#include "bco/cg/cg.hpp"
#include <iostream>
#include <fstream>

using namespace bco;

/* 
 *Implements Unit test for the Craig Apparatus Simulator 
 */


int main(int argc, char** argv)
{
    std::ofstream outfile("test-results.txt");
    
    std::cout << "Chromatography test no 1" << std::endl;
    std::vector<double> coefs{0.25, 1.5, 5.0};
    std::vector<double> fraction_vector = craigApparatus(50, 20, coefs);
    for (auto elem : fraction_vector) {
	std::cout << elem << ", ";
	outfile << elem << ",";
    }
    
    std::cout << "\n";
    outfile << std::endl;

    outfile.close();
}
