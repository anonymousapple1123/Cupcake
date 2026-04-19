#!/usr/bin/env python3
"""
Setup script for building the C++ performance extension module.
"""

from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup, Extension
import os
import sys
from pathlib import Path

# Define the extension module
ext_modules = [
    Pybind11Extension(
        "core_performance",
        sources=[
            "core_cpp/text_streamer.cpp",
        ],
        include_dirs=[
            "core_cpp/",
        ],
        cxx_std=17,
        define_macros=[("VERSION_INFO", '"dev"')],
    ),
]

class BuildExt(build_ext):
    """Custom build extension to handle compiler-specific optimizations."""
    
    def build_extensions(self):
        # Add compiler-specific optimization flags
        if self.compiler.compiler_type == 'msvc':
            # MSVC optimizations
            for ext in self.extensions:
                ext.extra_compile_args.extend(['/O2', '/GL'])
                ext.extra_link_args.extend(['/LTCG'])
        else:
            # GCC/Clang optimizations
            for ext in self.extensions:
                ext.extra_compile_args.extend([
                    '-O3', 
                    '-march=native',
                    '-mtune=native',
                    '-ffast-math'
                ])
        
        super().build_extensions()

if __name__ == "__main__":
    setup(
        name="core_performance",
        ext_modules=ext_modules,
        cmdclass={"build_ext": BuildExt},
        zip_safe=False,
        python_requires=">=3.8",
    )
