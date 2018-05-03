#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
namespace py = pybind11;

#include "mymodule.hpp"


PYBIND11_EMBEDDED_MODULE ( mymodule, m )
{
    py::class_<Base>(m, "Base")
        .def("__str__", &Base::name)
    ;
}

/*
#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(mymodule)
{
    class_<Base>("Base")
        .def("__str__", &Base::name)
    ;
}
*/