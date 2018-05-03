
// #include <boost/python.hpp>
// #include <boost/python/list.hpp>
// #include <boost/python/extract.hpp>



#include <sstream>
#include <string>
#include <vector>

#include <pybind11/pybind11.h>
namespace py = pybind11;

struct World
{
    void set(std::string msg) { mMsg = msg; }
    void many(py::list msgs) {        
        long l = py::len(msgs);
        std::stringstream ss;
        for (long i = 0; i<l; ++i) {
            if (i>0) ss << ", ";
            // std::string s = boost::python::extract<std::string>(msgs[i]);
            std::string s = py::cast<std::string>(msgs[i]);
            ss << s;
        }
        mMsg = ss.str();
    }
    std::string greet() { return mMsg; }
    std::string mMsg;
};


PYBIND11_MODULE ( classes, m )
{
    py::class_<World> (m, "World" )
    .def ( py::init<> () ) // THIS IS MUST
    .def ( "greet", &World::greet )
    .def ( "set", &World::set )
    .def ( "many", &World::many )
    ;
}