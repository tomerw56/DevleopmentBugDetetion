#how to?
install https://learn.microsoft.com/en-us/sysinternals/downloads/procdump

Open Developer Command Prompt for VS:
```
cl /Zi /EHsc crash.cpp
```

launch and create dump with
```
procdump -e -x . crash.exe
```

analyse dump with vs

for global_crash just ```cl /Zi global_crash.cpp dbghelp.lib``` and excute
