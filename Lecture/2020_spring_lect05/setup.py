from distutils.core import setup
from Cython.Build import cythonize

setup(
    name = "My module app",
    ext_modules = cythonize('my_module.pyx'),
)
