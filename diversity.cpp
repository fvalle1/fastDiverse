#include <boost/python.hpp>

#include "reader.h"

BOOST_PYTHON_MODULE(pydiversity)
{
    using namespace boost::python;

    def("diversity", loadFile<long>);
}