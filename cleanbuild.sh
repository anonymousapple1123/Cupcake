#!/bin/bash

# Compile the C++ files
echo "Compiling files..."
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
g++ main.o llm_talker.o -o testrun_1

# Check if linking was successful
if [ $? -ne 0 ]; then
    echo "Linking failed. Exiting."
    exit 1
fi

# Run the executable and log errors
echo "Running the program..."
./testrun_1 2> auto_error.log
mv auto_error.log error_logs/

# Clean up the generated files
echo "Cleaning up..."
rm main.o llm_talker.o testrun_1
echo "Cleanup done."
