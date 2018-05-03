#include "Python.h"

struct OutOfSteakException {};

void translateException( const OutOfSteakException& x) {
    PyErr_SetString(PyExc_UserWarning, "The meat is gone, go for the cheese....");
};

void someFunction() {
    throw OutOfSteakException();
};


#include <pybind11/pybind11.h>
namespace py = pybind11;

PYBIND11_MODULE ( myexceptions, m )
{
    // register_exception_translator<OutOfSteakException>(translateException); // boost.python

    // THIS is somewhat not straight forward compared with boost.python one
    py::register_exception_translator ( []( std::exception_ptr p ) {
        try {
            if ( p ) std::rethrow_exception ( p );
        }
        catch ( const OutOfSteakException &e ) {
            // Set MyException as the active python error
            translateException ( e );
        }
    } );

    m.def ( "someFunction", someFunction );
}