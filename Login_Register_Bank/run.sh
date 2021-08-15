
# !/bin/bash

# Program: Area_of_Rectangle
# Author: Marius Iacob

echo "**Compiled main.cpp"
g++ -c -Wall -o main.o main.cpp -std=c++17

echo "**Compiled function.cpp"
g++ -c -Wall -o function.o function.cpp -std=c++17

echo "**Link the object files using the gcc linker standard 2017"
g++ -o run.out -std=c++17 main.o function.o 

echo "**Run the program"
echo "=========================================================="
echo ""                                 # newline in .sh files
./run.out

echo "**The script file will terminate"

# Delete some un-needed files
rm *.o
rm *.out