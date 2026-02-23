#!/bin/bash
# Works both on macos and linux OS's
OS=$(uname)
if [ "$OS" = "Linux" ]; then
    echo "Running Linux compatible executable..."
    ./bins/main_linux
    mv model_output.json codex_res/ && mv response.txt parsed_files/
elif [ "$OS" = "Darwin" ]; then
    echo "Running macOS compatible executable..."
    ./bins/main_darwin
    mv model_output.json codex_res/ && mv response.txt parsed_files/
else
    echo "$OS"
    echo "Error : Unsupported platform"
fi
