#include <sstream>
#include <string>
#include <vector>

class Example {
public:
    Example() {}
    void add(const std::string& s)
    {
        mS.push_back(s);
    }

    std::vector<std::string>::iterator begin()
    {
        return mS.begin();
    }
    std::vector<std::string>::iterator end()
    {
        return mS.end();
    }

private:
    std::vector<std::string> mS;
};

#include <pybind11/pybind11.h>
namespace py = pybind11;

PYBIND11_MODULE ( iterators, m )
{
    py::class_<Example> ( m, "Example" )
        .def ( py::init<> () ) // THIS IS MUST

/*
        // OK if the mS is public
        .def ( "strings", []( const Example &e ) { return py::make_iterator ( e.mS.begin (), e.mS.end () ); },
            py::keep_alive<0, 1> ()  // Essential: keep object alive while iterator exists
        )
*/

    .def ( "strings", []( Example &e ) { return py::make_iterator ( e.begin(), e.end () ); },
    py::keep_alive<0, 1> ()  //Essential: keep object alive while iterator exists
    )

    .def("add", &Example::add)
    ;
}

/*
#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(iterators)
{
    class_<Example>("Example")
        .def("strings", range(&Example::begin, &Example::end))
        .def("add", &Example::add)
    ;
}	
*/

