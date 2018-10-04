#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/assign/list_inserter.hpp>

namespace bco {

    using Parameters = boost::property_tree::ptree;

    // template<class C>
    // class call_put
    // {
    // 	C& c_;
    // public:
    // 	call_put(C& c) : c_(c) {}
    // 	template<typename T, typename V>
    // 	void operator () (const T& key, const V& value)
    // 	    {
    // 		c_.put(key, value);
    // 	    }
    // };

    // template<class C>
    // inline boost::assign::list_inserter<call_put<C> >
    // putu(C& c)
    // {
    // 	return boost::assign::make_list_inserter(call_put<C>(c));
    // }
    
}

#endif
