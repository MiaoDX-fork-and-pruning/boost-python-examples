
pybind11_add_module(ctor ctor.cpp)
#PYTHON_ADD_MODULE(ctor ctor.cpp)
FILE(COPY ctor.py DESTINATION .)
ADD_TEST(NAME 03-Constructors COMMAND ${PYTHON_EXECUTABLE} ctor.py)
