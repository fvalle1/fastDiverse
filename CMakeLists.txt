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

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}
                    ${CMAKE_SOURCE_DIR}/include)

set(SOURCES_DIR ${CMAKE_SOURCE_DIR}/src)
set(SOURCES
    ${SOURCES_DIR}/reader.cpp
    ${SOURCES_DIR}/fileReader.cpp
    ${SOURCES_DIR}/monitor.cpp
    ${SOURCES_DIR}/mutex_wrapper.cpp
    )

# Build our library
add_library(libdiversity SHARED 
            ${SOURCES}
            )
# Define the wrapper library that wraps our library
add_library(pydiversity SHARED
        ${SOURCES_DIR}/diversity.cpp
        )
# don't prepend wrapper library name with lib
set_target_properties(pydiversity PROPERTIES PREFIX "" )
# must be .so (not .dylib)
set_target_properties(pydiversity PROPERTIES SUFFIX ".so")

target_link_libraries(pydiversity ${PYTHON_LIBRARIES} ${Boost_LIBRARIES} libdiversity)

add_executable(diversity
            main.cpp
            )

target_link_libraries(diversity PRIVATE Threads::Threads libdiversity)