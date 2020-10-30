# EGL Context
For general info see [EGL Eye: OpenGL Visualization without an X Server](https://devblogs.nvidia.com/egl-eye-opengl-visualization-without-x-server/).

# Headers
Headers are downloaded from
 * https://www.khronos.org/registry/EGL/
 * https://www.khronos.org/registry/OpenGL/index_gl.php#headers

# Build
Export the corresponding path for your system
```
git submodule update --init --recursive
pip install -r requirements.txt
export EGL_LIBRARY_PATH=/usr/lib
python setup.py build
```
# Package
```
python setup.py bdist_wheel
```
# Install
```
pip install dist/*.whl
```
# Example
In case of success, executing `` `find . -type f -name main` ``
(don't miss the backticks), should result in something like
```
EGL 4.6
GL 4.6
GL extensions 389
```
Running `example.py` should give something similar to
```
OpenGL 4.6
```
# Usage
With [PyOpenGL](http://pyopengl.sourceforge.net/):
```
import os
os.environ['PYOPENGL_PLATFORM'] = 'egl'
from OpenGL.GL import *
```
If there are multiple GPUs, select one by exporting its index, e.g.
```
export EGL_DEVICE=1
```