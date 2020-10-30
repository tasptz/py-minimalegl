#pragma once

#include <tuple>

namespace megl {

std::tuple<int, int> init(int device);
void destroy();

}