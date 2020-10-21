import platform
assert platform.system() == 'Linux'

from skbuild import setup

setup(
    name='minimalegl',
    version='1.0.0',
    package_dir={'minimalegl': 'py/minimalegl'},
    packages=['minimalegl'],
    cmake_args=['-DWITH_PYTHON=1']
)
