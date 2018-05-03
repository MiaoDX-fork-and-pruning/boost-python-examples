char const* greet()
{
   return "hello, world";
}

/*
#include <boost/python.hpp>

BOOST_PYTHON_MODULE(hello)
{
    using namespace boost::python;
    def("greet", greet);
}
*/

#include <pybind11/pybind11.h>

PYBIND11_MODULE(hello, m)
{
	m.def("greet", &greet);
    m.def ( "greet2", greet );
}