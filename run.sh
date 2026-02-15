#!/bin/bash
# Works both on macos and linux OS's
OS=$(uname)
if [ "$OS" = "Linux" ]; then
    echo "Running Linux compatible executable..."
    cd bins && ./main_linux
    mv model_output.json ../ && cd .. && mv model_output.json codex_res/
elif [ "$OS" = "Darwin" ]; then
    echo "Running macOS compatible executable..."
    cd bins && ./main_darwin
    mv model_output.json ../ && cd .. && mv model_output.json codex_res/
else
    echo "$OS"
    echo "Error : Unsupported platform"
fi
