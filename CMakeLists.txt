#python modules
if(UNIX)
    set( BOOST_PYTHONLIB python39)
else()
    set( BOOST_PYTHONLIB python3)
endif()

# Check the architecture and set CMAKE_LIBRARY_ARCHITECTURE accordingly
if(UNIX)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(CMAKE_LIBRARY_ARCHITECTURE "x86_64-linux-gnu")
    endif()
endif()

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

find_package(Boost 1.65.0 COMPONENTS ${BOOST_PYTHONLIB} python REQUIRED)

find_package(PythonLibs 3.9 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")
message(STATUS "Python_INCLUDE_DIRS: ${PYTHON_INCLUDE_DIRS}")
message(STATUS "Python_LIBRARIES: ${PYTHON__LIBRARY}")

include_directories(${CMAKE_SOURCE_DIR})

# Build our library
add_library(mydiversity SHARED ${CMAKE_SOURCE_DIR}/diversity.cpp)

# Define the wrapper library that wraps our library
add_library(pydiversity SHARED
        diversity.cpp
        ${CMAKE_SOURCE_DIR}/reader.cpp)
# don't prepend wrapper library name with lib
set_target_properties(pydiversity PROPERTIES PREFIX "" )
# must be .so (not .dylib)
set_target_properties(pydiversity PROPERTIES SUFFIX ".so")

target_link_libraries(pydiversity ${PYTHON_LIBRARIES} ${Boost_LIBRARIES} mydiversity)