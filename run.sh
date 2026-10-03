#!/bin/bash
# Works both on macos and linux OS's
# Adding infinite chatting ability with no context;
flag=true # debug flag
while true; do
    OS=$(uname)
    if [ "$OS" = "Linux" ]; then
        echo "Running Linux compatible executable..."
        ./bins/main_linux
        mv model_output.json codex_res/ response.txt parsed_files/
    elif [ "$OS" = "Darwin" ]; then
        if [ "$flag" = true ]; then
            echo "Running macOS compatible executable..."
        fi
        ./bins/main_darwin
        # Outputting model output to terminal {temporary solution}
        cat response.txt
        mv model_output.json codex_res/ && mv response.txt parsed_files/
    else
        echo "$OS"
        echo "Error : Unsupported platform"
    fi
done
