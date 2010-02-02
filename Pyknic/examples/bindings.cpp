// This file has been generated by Py++.

#include "boost/python.hpp"

#include "/home/xin/code/pyknic/Pyknic/examples/examples.h"

namespace bp = boost::python;

struct Base_wrapper : Pyknic::Base, bp::wrapper< Pyknic::Base > {

    Base_wrapper(Pyknic::Base const & arg )
    : Pyknic::Base( arg )
      , bp::wrapper< Pyknic::Base >(){
        // copy constructor
        
    }

    Base_wrapper()
    : Pyknic::Base()
      , bp::wrapper< Pyknic::Base >(){
        // null constructor
        
    }

    virtual int f(  ) {
        if( bp::override func_f = this->get_override( "f" ) )
            return func_f(  );
        else
            return this->Pyknic::Base::f(  );
    }
    
    
    int default_f(  ) {
        return Pyknic::Base::f( );
    }

};

BOOST_PYTHON_MODULE(_examples){
    bp::class_< Base_wrapper >( "Base" )    
        .def( 
            "f"
            , &::Pyknic::Base::f
            , &Base_wrapper::default_f );

    bp::class_< Pyknic::World >( "World", bp::init< std::string const & >(( bp::arg("country") )) )    
        .def( 
            "greet"
            , &::Pyknic::World::greet );

    bp::implicitly_convertible< std::string const &, Pyknic::World >();
}