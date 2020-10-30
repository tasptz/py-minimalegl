import os

from . import pyminimalegl

major, minor = pyminimalegl.init(int(os.environ.get('EGL_DEVICE', 0)))

import atexit
atexit.register(pyminimalegl.destroy)
