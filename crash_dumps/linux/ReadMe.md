#how to?
Inside Linux filesystem:

1/
```
cd ~
mkdir crash_demo
cd crash_demo
```
2/ 
```
ulimit -c unlimited
sudo sysctl -w kernel.core_pattern=core
```
Verify:
```
cat /proc/sys/kernel/core_pattern
```
Should print:
```
core
```

3/ Rebuild & Run
```
g++ -g crash.cpp -o crash
./crash
```
Now check:
```
ls -lh
```
You should see something like:
```
core
```

Size should NOT be 0 bytes.
It should be several MB.

4/ Now Open It
```
gdb ./crash core
```
Inside gdb:
```
bt
```
Now it should work.