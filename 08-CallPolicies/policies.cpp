#include <sstream>
#include <string>

class Example {
    Example(std::string n) : mName(n) {}
    ~Example () {}; // we should do manual destructor in cpp, see [singleton](http://pybind11.readthedocs.io/en/stable/advanced/classes.html#non-public-destructors)
    std::string mName;
public:
    std::string name() const { return mName; }
    static Example* factory()
    {
        return new Example("factory");
    }
    static Example* singleton()
    {
        static Example instance = Example("singleton");
        return &instance;
    }
};


#include <pybind11/pybind11.h>
namespace py = pybind11;

PYBIND11_MODULE ( policies, m )
{
    py::class_<Example, std::unique_ptr<Example, py::nodelete>>(m, "Example")
        .def("__str__", &Example::name)
        .def_static("factory", &Example::factory) // even we use def_static, it seems that it has same result compared with def
        .def_static("singleton", &Example::singleton)
    ;
}