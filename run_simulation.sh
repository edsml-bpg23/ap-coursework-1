#!/bin/bash

build_dir="build"

if [ ! -d "$build_dir" ]; then
    # if it doesn't exist, create it
    mkdir "$build_dir"
fi

cd "$build_dir"

# Run CMake and make to build the project
cmake ..
make

./ap_coursework_1

cd ../python
python main.py
