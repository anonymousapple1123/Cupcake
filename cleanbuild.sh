#!/bin/bash
OS=$(uname)
# Compile the C++ files
echo "** Clean Build Started **"
echo "Compiling..."
g++ -c main.cpp
cd core
g++ -c llm_talker.cpp
mv llm_talker.o ../
cd ..

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed. Exiting."
    exit 1
fi

# Link the object files to create the executable
if [ "$OS" = "Linux" ]; then
    g++ main.o llm_talker.o -o main_linux
    cp main_linux bins/
elif [ "$OS" = "Darwin" ]; then
    g++ main.o llm_talker.o -o main_darwin
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

# Clean up the generated files
echo "Cleaning up..."
rm main.o llm_talker.o
if [ "$OS" = "Linux" ]; then
    rm main_linux
elif [ "$OS" = "Darwin" ]; then
    rm main_darwin
fi
echo "** Clean Build Completed **"
