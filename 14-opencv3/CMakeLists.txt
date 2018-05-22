#project( OPENCV3 )
#cmake_minimum_required( VERSION 2.8 )

# find_package( OpenCV REQUIRED )
include( $ENV{OpenCV3_DIR}/OpenCVConfig.cmake )

message( STATUS "OpenCV library status:" )
message( STATUS "    version: ${OpenCV_VERSION}" )
message( STATUS "    libraries: ${OpenCV_LIBS}" )
message( STATUS "    include path: ${OpenCV_INCLUDE_DIRS}" )

include_directories( ${OpenCV_INCLUDE_DIRS} )


#pybind11_add_module(classes_cv classes_cv.cpp)

set(LIBNAME classes_cv)
add_library(${LIBNAME} MODULE classes_cv.cpp)
target_link_libraries(${LIBNAME} PRIVATE pybind11::module ${OpenCV_LIBS})

if( MSVC )
set_target_properties(${LIBNAME} PROPERTIES
    SUFFIX ".pyd"
)
else()
set_target_properties(${LIBNAME} PROPERTIES
    SUFFIX ".so"
)
endif()