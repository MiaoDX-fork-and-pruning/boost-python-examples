
// #include <boost/python.hpp>
// #include <boost/python/list.hpp>
// #include <boost/python/extract.hpp>

#include "opencv2/core.hpp"
#include <iostream>

using namespace cv;
using namespace std;

#include <sstream>
#include <string>
#include <vector>

#include <pybind11/pybind11.h>
namespace py = pybind11;

struct World
{

    void init_cv_mat(int row, int col)
    {
        cv_mat = Mat ( row, col, CV_64F );
        randu ( cv_mat, Scalar::all ( 0 ), Scalar::all ( 255 ) );
        cout << cv_mat << endl;
    }

    vector<Point2f> pylist2vec( py::list pylist )
    {
        long l = py::len ( pylist );
        vector<Point2f> vec_p;
        vec_p.reserve ( l / 2 );

        for ( long i = 0; i<l/2; ++i ) {         
            double x = py::cast<double> ( pylist[i * 2] );
            double y = py::cast<double> ( pylist[i * 2+1] );
            vec_p.push_back ( Point2f ( x, y ) );
        }

        
        //cout << vec_p << endl;
        return vec_p;
    }

    py::list transform(py::list list1, py::list list2)
    {
        auto vec_p1 = pylist2vec ( list1 );
        auto vec_p2 = pylist2vec ( list2 );
        cout << vec_p1 << endl;
        cout << vec_p2 << endl;

        auto vec_l1 = cv_mat_vec ( Mat ( vec_p1 ) );
        auto vec_l2 = cv_mat_vec ( Mat ( vec_p2 ) );

        py::list two_pylist;
        two_pylist.append ( vec_l1 );
        two_pylist.append ( vec_l2 );

        return two_pylist;
    }



    vector<double> getVector ( const Mat &_t1f )
    {
        Mat t1f;
        _t1f.convertTo ( t1f, CV_64F );
        return (vector<double>)(t1f.reshape ( 1, 1 ));
    }

    py::list cv_mat_vec (const Mat& mat)
    {
        py::list vec_l;

        for(auto e : getVector ( mat ) )
        {
            vec_l.append ( e );
        }

        return vec_l;
    }

    py::list cv_mat_vec_self ()
    {
        return cv_mat_vec(cv_mat);
    }

    Mat cv_mat;
};


PYBIND11_MODULE ( classes_cv, m )
{
    py::class_<World> ( m, "World" )
        .def ( py::init<> () ) // THIS IS MUST
        .def ( "init_cv_mat", &World::init_cv_mat, py::arg ( "row" ) = 1, py::arg ( "col" ) = 1 )
        .def ( "cv_mat_vec_self", &World::cv_mat_vec_self )
        .def ( "transform", &World::transform, py::arg ( "list1" ) = 1, py::arg ( "list2" ) = 1 )
    ;
}