#!/bin/bash
verbose=false
while getopts "vn" opt; do
    case "$opt" in
        v) verbose=true;;
        *) echo "Usage: $0 [-v]"; exit 1;;
    esac
done
$verbose && echo "Verbose enabled"
OS=$(uname)
# Compile the C++ files
if [ "$verbose" = true ]; then
    echo "*** Clean Build Started ***"
    echo "Compiling..."
fi
g++ -c main.cpp
#g++ -c core/llm_talker.cpp
#g++ -c core/file_parser.cpp

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed. Exiting."
    exit 1
fi

# Link the object files to create the executable
if [ "$OS" = "Linux" ]; then
    g++ main.o -o main_linux
    cp main_linux bins/
elif [ "$OS" = "Darwin" ]; then
    g++ main.o -o main_darwin
    cp main_darwin bins/
fi

# Check if linking was successful
if [ $? -ne 0 ]; then
    echo "**Linking failed** Exiting..."
    exit 1
fi

# Run the executable and log errors
echo "Running the program..."
if [ "$OS" = "Linux" ]; then
    ./main_linux 2> auto_error.log
elif [ "$OS" = "Darwin" ]; then
    ./main_darwin 2> auto_error.log
fi

mv auto_error.log error_logs/
mv model_output.json codex_res/
mv response.txt parsed_files/

# Clean up the generated files
if [[ "$verbose" = true ]]; then
    echo "Cleaning up..."
fi
rm main.o
#rm llm_talker.o file_parser.o
if [ "$OS" = "Linux" ]; then
    rm main_linux
elif [ "$OS" = "Darwin" ]; then
    rm main_darwin
fi

if [[ "$verbose" = true ]]; then
    echo "*** Clean Build Completed ***"
fi
