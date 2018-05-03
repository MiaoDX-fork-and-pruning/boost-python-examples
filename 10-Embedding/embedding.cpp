
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
namespace py = pybind11;

#include <iostream>
//#include <frameobject.h>
#include "mymodule.hpp"



// #include <boost/python.hpp>
// using namespace boost::python;
/*
#if PY_MAJOR_VERSION >= 3
#   define INIT_MODULE PyInit_mymodule
    extern "C" PyObject* INIT_MODULE();
#else
#   define INIT_MODULE initmymodule
    extern "C" void INIT_MODULE();
#endif
*/

int main(int argc, char** argv)
{
    try {
        //PyImport_AppendInittab((char*)"mymodule", INIT_MODULE);
        //Py_Initialize();

        //py::scoped_interpreter guard{};

        py::module main_module = py::module::import("__main__");
        py::dict main_namespace = py::cast<py::dict>(main_module.attr("__dict__"));
        py::module mymodule = py::module::import ("mymodule");

        main_namespace["precreated_object"] = Base("created on C++ side");
        py::eval_file ("embedding.py", main_namespace, main_namespace);
    } catch (py::error_already_set& e) {
        PyErr_PrintEx(0);
        return 1;
    }
    return 0;
}
