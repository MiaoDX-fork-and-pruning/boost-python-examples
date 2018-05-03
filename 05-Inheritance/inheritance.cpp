#include <iostream>
#include <string>

class Base 
{
public:
    virtual std::string name() const { return "Base"; }
    virtual ~Base() {}
};

class Derived : public Base
{
public:
    virtual std::string name() const { return "Derived"; }
};

void fb(Base *b)
{
    std::cout << b->name() << " called." << std::endl;
}

void fd(Derived *d)
{
    std::cout << "Derived " << d->name() << " called." << std::endl;
}

Base* factory()
{
    return new Derived;
}

#include <pybind11/pybind11.h>
namespace py = pybind11;

PYBIND11_MODULE ( inheritance, m )
{
    py::class_<Base> ( m, "Base" )
        .def ( py::init<> () )
        .def ( "name", &Base::name )
        ;

    py::class_<Derived, Base > ( m, "Derived" )
        .def ( py::init<> () )
        ;

    m.def ( "fb", fb );
    m.def ( "fd", fd );
    // m.def ( "factory", factory, py::return_value_policy<manage_new_object> () );
    m.def ( "factory", factory);
}