
#include <iostream>
#include <fstream>

#include "bco/cg/api/facade/simulator-facade.hpp"
#include "bco/cg/simulators/simulator-factory.hpp"

using namespace bco;

template<typename T>
void print_vector(const std::vector<T> &vector)
{
    std::cout << "(";
    for (auto &elem : vector)
    {
	std::cout << elem << ", ";
    }
    std::cout << ")\n";
}

int main(int argc, char** argv)
{
    std::cout << "CHROMATOGRAPHY TESTS" << std::endl;

    // SimulatorFacade facade;

    // for (auto& elem : facade.getSimulatorList())
    // {
    // 	std::cout << " - " << elem << "\n";
    // }
    // facade.compute();
    // facade.getParameters("countercurrent")
	;
    std::cout << "END TEST" << std::endl;
}
