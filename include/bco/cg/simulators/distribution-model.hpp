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

  static std::string params ="{\
    \"simulator\" : {				\
	\"description\" : \" Distribution model: Based on the countercurrent extraction methods for liquid-liquid extraction. The distribution model mimics the design of the Craig Apparatus (Lyman C. Craig). It is a very crude model devised to illustrate the separation of substance with different distribution coefficients.\",	\
	\"name\" : \"distribution\",		\
	\"parameters\":[{			\
            \"name\": \"num_tubes\",			\
            \"description\": \"Number of tubes (<100, binomial coefficient can be expensive)\",		\
            \"value\" : 20				\
	},{						\
            \"name\" : \"num_cycles\",			\
            \"description\": \"Number of cycles (Extraction and transfert cycles)\", \
            \"value\": 10				\
	}],						\
	\"setup\": [\"distribution\"]			\
    },							\
    \"compounds\" : [{					\
	\"description\" : \"I'm A\",\
	\"distribution\" : 0.5,	    \
	\"name\":\"A\"		    \
    },{						\
	\"description\" : \"I'm B\",\
	\"distribution\": 3.5,	    \
	\"name\":\"B\"		    \
    }]				    \
    }";
  
    bool DistributionModel::registered_ =
	SimulatorFactory::Register<DistributionModel>("distribution",
						      "I'm Craig Distribution Model simulator", params);
}

#endif
