@echo off
clang-tidy bad_code.cpp -- -std=c++17 >clang_tidy_output.txt
clang-format -i *.cpp *.h
clang-tidy bad_code.cpp -fix -- -std=c++17
echo Style fix complete.
pause
