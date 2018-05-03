#include <sstream>
#include <string>

class NumberLike
{
public:
    NumberLike(int n = 0) : mN(n) {}
    NumberLike& operator+= (int i)
    {
        mN += i;
        return *this;
    }
    std::string str() const
    {
        std::stringstream s;
        s << mN;
        return s.str();
    }
    std::string repr() const
    {
        std::stringstream s;
        s << "NumberLike("<< mN << ")";
        return s.str();
    }
private:
    int mN;
};

NumberLike operator+(NumberLike n, int i)
{ 
    n += i;
    return n;
};


#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
namespace py = pybind11;

PYBIND11_MODULE ( operators, m )
{
    py::class_<NumberLike> ( m, "NumberLike" )
        .def ( py::init<int> (), py::arg ( "n" ) = 0 ) // there should be better ones
        //.def ( py::init<> ( NumberLike::NumberLike ))
        .def(py::self + int())
        .def("__str__", &NumberLike::str)
        .def("__repr__", &NumberLike::repr)
    ;
}