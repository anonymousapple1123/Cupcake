#!/bin/bash
# Works both on macos and linux OS's
# Adding infinite chatting ability with no context;
verbose=false # debug flag

while getopts "vn" opt; do
    case "$opt" in
        v) verbose=true;;
        *) echo "Usage: $0 [-v]"; exit 1;;
    esac
done

while true; do
    OS=$(uname)
    if [ "$OS" = "Linux" ]; then
        echo "Running Linux compatible executable..."
        ./bins/main_linux
        mv model_output.json codex_res/ response.txt parsed_files/
    elif [ "$OS" = "Darwin" ]; then
        if [ "$verbose" = true ]; then
            echo "Running macOS compatible executable..."
        fi

        if [ "$verbose" = true ]; then
            ./bins/main_darwin --verbose
        else
            ./bins/main_darwin
        fi
        # Outputting model output to terminal {temporary solution}
        cat response.txt
        mv model_output.json codex_res/ && mv response.txt parsed_files/
    else
        echo "$OS"
        echo "Error : Unsupported platform"
    fi
done
