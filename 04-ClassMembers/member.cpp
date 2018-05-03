#include <string>
#include <sstream>

class SomeClass
{
public:
    SomeClass(std::string n) : name(n), mNumber(0.0) {}

    std::string name;

    double getNumber() const { return mNumber; }
    void setNumber(double n)
    {
        if (n>3.141592654)
            n = -1;
        mNumber = n;
    }

private:
    double mNumber;
};


#include <pybind11/pybind11.h>
namespace py = pybind11;

PYBIND11_MODULE ( member, m )
{
    py::class_<SomeClass>(m, "SomeClass")
        .def(py::init<std::string> (), py::arg ( "" ) = "class_name" )
        .def_readwrite("name", & SomeClass::name)
        //.add_property("number", &SomeClass::getNumber, &SomeClass::setNumber)
        .def_property ("number", &SomeClass::getNumber, &SomeClass::setNumber )        
    ;
}