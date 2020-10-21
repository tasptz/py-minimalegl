from . import pyminimalegl

major, minor = pyminimalegl.init()

import atexit
atexit.register(pyminimalegl.destroy)
