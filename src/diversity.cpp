#include <boost/python.hpp>

#include "reader.h"

BOOST_PYTHON_FUNCTION_OVERLOADS(loadFile_overloads, loadFile<long>, 1, 3)

BOOST_PYTHON_MODULE(pydiversity)
{
    namespace bp = boost::python;
    using namespace bp;

    def("diversity", loadFile<long>, loadFile_overloads(bp::args("file", "nThreads", "verbose")));
}