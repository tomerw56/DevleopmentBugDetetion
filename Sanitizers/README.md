# Build via wsl
### ASAN
```
rm -rf build
cmake -S . -B build -DENABLE_ASAN=ON
cmake --build build
./build/asan_demo
```
### BSAN
```
rm -rf build
cmake -S . -B build -DENABLE_UBSAN=ON
cmake --build build
./build/ubsan_demo
```
### TSAN
```
rm -rf build
cmake -S . -B build -DENABLE_TSAN=ON
cmake --build build
./build/tsan_demo
```