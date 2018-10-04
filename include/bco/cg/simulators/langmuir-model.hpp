#ifndef VANDEEMTER_HPP
#define VANDEEMTER_HPP

#include "simulator-factory.hpp" 


namespace bco {

    /**
     * Simulator Implementation of the Langmuir Isotherm Model for Plates Chromatography
     */
    class LangmuirModel: virtual public AbstractSimulator
    {
    public:
        LangmuirModel() = default;
	virtual ~LangmuirModel() = default;

	/**
	 * Return struct
	 * @return Results
	 */
        virtual Results compute(const Parameters &parameters) override;
	
    private:
	static bool registered_;	
    };

    static std::string params ="{\
    \"simulator\" : {				\
	\"description\" : \"plop\",		\
	\"name\" : \"langmuir\",		\
	\"parameters\":[{			\
            \"name\": \"num_plates\",			\
            \"description\": \"Number of plates\",	\
            \"value\" : 50				\
	},{						\
            \"name\" : \"num_cycles\",			\
            \"description\": \"Number of cycles\",	\
            \"value\": 20				\
	}],						\
	\"setup\": [\"distribution\", \"response\"]	\
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
  
    bool LangmuirModel::registered_ =
	SimulatorFactory::Register<LangmuirModel>
	("langmuir",
	 "I'm Langmuir Isotherm Absorption Model simulator",
	 params/*"{\"simulator\" : \"langmuir\"}"*/);
}

#endif
