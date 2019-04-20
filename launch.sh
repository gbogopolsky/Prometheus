#!/bin/bash

# A script to meson build the project, run it and execute the visualisation Python script.

meson build
cd build
ninja
./sfml-app
cd ..
python3 display.py
