### Ray Tracing V2

To Clone:

`git clone --recurse-submodules git@github.com:antonizyla/raytrace2.git`

To run: 

1. `git clone --recurse-submodules git@github.com:antonizyla/raytrace2.git` Clone Including git submodules

2. `cd raytrace2` 

3. `mdkir build && cd build` Create Build Directory

4. `cmake .. && make` Compile Executable

5. `./src/raytrace2_run`
Run Executable

Use `cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..` substitute for step 4 if using lsp editor 
