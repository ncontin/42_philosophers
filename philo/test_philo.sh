#!/bin/bash

echo "Testing basic functionality"
./philo 5 800 200 200

echo "Testing death scenario"
./philo 5 200 800 200

echo "Testing with meal limit"
./philo 5 800 200 200 7

echo "Testing edge case: 1 philosopher"
./philo 1 800 200 200

echo "Running Helgrind check"
valgrind --tool=helgrind ./philo 4 410 200 200
