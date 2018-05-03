

pybind11_add_module(hello hello.cpp)


#PYTHON_ADD_MODULE(hello hello.cpp)
#FILE(COPY hello.py DESTINATION .)
#FILE(COPY hello.py DESTINATION Release)
#ADD_TEST(NAME 01-HelloWorld COMMAND ${PYTHON_EXECUTABLE} Release/hello.py)
