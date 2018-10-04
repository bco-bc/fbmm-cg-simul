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
	\"description\" : \" \",	        \
	\"name\" : \"distribution\",		\
	\"parameters\":[{			\
            \"name\": \"num_tubes\",			\
            \"description\": \"Number of tubes (avoid more than 20 as \
it need to calculate bionamial coefficient)\",		\
            \"value\" : 20				\
	},{						\
            \"name\" : \"num_cycles\",			\
            \"description\": \"Number of cycles (Extraction and transfert)\", \
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
