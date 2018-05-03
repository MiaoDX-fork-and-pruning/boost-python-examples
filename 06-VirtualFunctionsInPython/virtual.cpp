#include <iostream>
#include <string>

class Base 
{
public:
    virtual std::string name() const { return "Base"; }
    virtual ~Base() {}
};

void identify(Base *b)
{
    std::cout << b->name() << " called." << std::endl;
}


#include <pybind11/pybind11.h>
namespace py = pybind11;


struct BaseWrap : Base
{
    using Base::Base;
    std::string name() const override
    {
        PYBIND11_OVERLOAD (
            std::string,
            Base,
            name,
            
        );
    }
    /*
    std::string default_name() const
    {
        return this->Base::name();
    }
    */
};



PYBIND11_MODULE ( virtual, m )
{
    /*
    py::class_<Base> ( m, "Base" )
        .def ( py::init<> () )
        .def ( "name", &Base::name )
        ;
    */
    
    // NOTE the sequence of Base and BaseWrap, it is odd ..
    py::class_<Base, BaseWrap > ( m, "Base" )
        .def ( py::init<> () )
        .def("name", &Base::name)
        ;
    
    m.def("identify", identify);    
}

/*
#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(virtual)
{
    class_<BaseWrap, boost::noncopyable>("Base")
        .def("name", &Base::name, &BaseWrap::default_name)
    ;

    def("identify", identify);
}	
*/