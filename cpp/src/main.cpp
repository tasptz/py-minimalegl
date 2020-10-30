#define GL_GLEXT_PROTOTYPES
#include <GL/glcorearb.h>

#include <iostream>

#include "minimalegl.h"

int main(int argc, char *argv[])
{
    try {
        auto t = megl::init(0);
        std::cout << "EGL " << std::get<0>(t) << "." << std::get<1>(t) << std::endl;

        int ma = -1;
        int mi = -1;
        glGetIntegerv(GL_MAJOR_VERSION, &ma);
        glGetIntegerv(GL_MINOR_VERSION, &mi);
        std::cout << "GL " << ma << "." << mi << std::endl;

        int n = -1;
        glGetIntegerv(GL_NUM_EXTENSIONS, &n);
        std::cout << "GL extensions " << n << std::endl;

        megl::destroy();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}