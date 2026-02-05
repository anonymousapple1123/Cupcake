#!/bin/bash
# Works both on macos and linux oses
OS=$(uname)
if [ "$OS" = "Linux" ]; then
    echo "Running Linux compatible executable..."
    cd bins && ./main_linux
elif [ "$OS" = "Darwin" ]; then
    echo "Running macOS compatible executable..."
    cd bins && ./main_darwin
else
    echo "$OS"
fi
