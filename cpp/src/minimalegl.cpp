#include <EGL/egl.h>

#include <stdexcept>
#include <sstream>
#include <tuple>

static const EGLint configAttribs[] = {
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_STENCIL_SIZE, 8,
        EGL_DEPTH_SIZE, 24,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_BIT,
        EGL_NONE
};

static EGLDisplay eglDpy = nullptr;
static EGLContext eglCtx = nullptr;

void checkEglError() {
    auto e = eglGetError();
    if (e != EGL_SUCCESS) {
        std::ostringstream oss;
        oss << "EGL error " << e;
        throw std::runtime_error(oss.str());
    }
}

namespace megl {

std::tuple<int, int> init() {
    // 1. Initialize EGL
    eglDpy = eglGetDisplay(EGL_DEFAULT_DISPLAY);

    EGLint major, minor;
    eglInitialize(eglDpy, &major, &minor);

    // 2. Select an appropriate configuration
    EGLint numConfigs;
    EGLConfig eglCfg;
    eglChooseConfig(eglDpy, configAttribs, &eglCfg, 1, &numConfigs);

    // 3. Bind the API
    eglBindAPI(EGL_OPENGL_API);

    // 4. Create a context and make it current
    eglCtx = eglCreateContext(eglDpy, eglCfg, EGL_NO_CONTEXT, NULL);
    eglMakeCurrent(eglDpy, EGL_NO_SURFACE, EGL_NO_SURFACE, eglCtx);

    // 5. EGL setup done, check for errors
    checkEglError();

    int ma = -1;
    int mi = -1;
    eglQueryContext(eglDpy, eglCtx, EGL_CONTEXT_MAJOR_VERSION, &ma);
    eglQueryContext(eglDpy, eglCtx, EGL_CONTEXT_MINOR_VERSION, &mi);

    return std::make_tuple(ma, mi);
}

void destroy() {
    // 6. Terminate EGL when finished
    if (eglCtx) {
        eglDestroyContext(eglDpy, eglCtx);
        eglCtx = nullptr;
    }

    if (eglDpy) {
        eglTerminate(eglDpy);
        eglDpy = nullptr;
    }
}

}