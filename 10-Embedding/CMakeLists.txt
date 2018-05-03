INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_DIRS})

#PYBIND11_ADD_MODULE(mymodule mymodule.cpp)
ADD_EXECUTABLE(embedding mymodule.cpp embedding.cpp)
#TARGET_LINK_LIBRARIES(embedding pybind11::embed ${PYTHON_LIBRARIES})
TARGET_LINK_LIBRARIES(embedding pybind11::embed)

# PYTHON_ADD_MODULE(mymodule mymodule.cpp)
# ADD_EXECUTABLE(embedding mymodule.cpp embedding.cpp)
# TARGET_LINK_LIBRARIES(embedding ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

FILE(COPY embedding.py DESTINATION .)
SET( ENV{PYTHONPATH} . )
ADD_TEST(NAME 10-Embedding COMMAND embedding)

