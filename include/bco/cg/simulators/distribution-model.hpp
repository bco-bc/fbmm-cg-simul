#ifndef DISTRIBUTIONMODEL_HPP
#define DISTRIBUTIONMODEL_HPP

#include "simulator-factory.hpp"


namespace bco {

    /**
     * Simulator Implementation for Distribution Model (Craig Apparatus)
     */
    class DistributionModel: virtual public AbstractSimulator
    {
    public:
        DistributionModel() = default;
	virtual ~DistributionModel() = default;

	/**
	 * Returns struct
	 * @returns Results
	 */
        virtual Results compute(const Parameters &parameters) override;

    private:
        static bool registered_;
	static Parameters parameters_;

	/**
	 * Returns the binomial coefficient C(n,k)
	 * @returns double
	 */
	double binomialCoeff(int n, int k);			
    };
    
    bool DistributionModel::registered_ =
	SimulatorFactory::Register<DistributionModel>("distribution",
						      "I'm Craig Distribution Model simulator",
						      "({\"simulator\":\"distribution\"})");
}

#endif
