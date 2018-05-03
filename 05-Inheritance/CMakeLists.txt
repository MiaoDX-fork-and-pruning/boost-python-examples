
pybind11_add_module(inheritance inheritance.cpp)
# PYTHON_ADD_MODULE(inheritance inheritance.cpp)
FILE(COPY inheritance.py DESTINATION .)
ADD_TEST(NAME 05-Inheritance COMMAND ${PYTHON_EXECUTABLE} inheritance.py)

