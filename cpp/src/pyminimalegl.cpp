#include <pybind11/pybind11.h>

#include "minimalegl.h"

PYBIND11_MODULE(pyminimalegl, m) {
    m.def("init", &megl::init, "Init egl context");
    m.def("destroy", &megl::destroy, "Destroy egl context");
}