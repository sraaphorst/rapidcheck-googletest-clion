# RapidCheck + Google Test Environment

This is simply a bare-bones test environment for using RapidCheck and Google Test
for future projects.

Note that RapidCheck, I believe, requires LLVM and not GCC. Thus, the first step
should be:

1. `brew install llvm`
2. Set up the cmake options to:
```
-DCMAKE_BUILD_TYPE=debug -DCMAKE_C_COMPILER=/usr/local/opt/llvm/bin/clang -DCMAKE_CXX_COMPILER=/usr/local/opt/llvm/bin/clang++
```
