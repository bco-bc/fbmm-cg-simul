#ifndef ABSTRACTSIMULATOR_HPP
#define ABSTRACTSIMULATOR_HPP

#include "bco/cg/parameters.hpp"
#include "bco/cg/results.hpp"

namespace bco {

    class CountercurrentExtraction;
    class vanDeemter;
    
    /**
     * Simulator Interface
     */
    class AbstractSimulator
    {
    public:
	AbstractSimulator() = default;
	virtual ~AbstractSimulator() = default;
	
	/**
	 * Returns struct
	 * @return Results
	 */
	virtual Results compute(const Parameters &parameters) = 0;
    };
}

#endif
