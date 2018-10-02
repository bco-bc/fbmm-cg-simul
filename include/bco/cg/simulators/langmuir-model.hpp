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
    
    bool LangmuirModel::registered_ =
	SimulatorFactory::Register<LangmuirModel>
	("langmuir",
	 "I'm Langmuir Isotherm Absorption Model simulator",
	 "{\"simulator\" : \"langmuir\"}");
}

#endif
