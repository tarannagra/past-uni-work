# Compiling tutorial!

It's unsure if you will be compiling the code yourself, if not, this is a small showcase on how to do so.
If this is you, Taran. You should know better, you already know this. If not, welcome and enjoy this tutorial!

## Standard
```bash
g++ your_file_here.cpp
```
This is the basic way to compile a C++ file.

## Specifying output
```bash
g++ your_file_here.cpp -o your_executeable_here
```
This makes a file called `your_executeable_here`.

## Specifying C++ version
```bash
g++ your_file_here.cpp --std=c++<version_number_here> 
# Example compiling for C++14 which the university requires.
g++ your_file_here.cpp --std=c++14
```

## Everything at once
```bash
g++ your_file_here.cpp -o your_executeable_here --std=c++14
```

## Running the file
Assuming your file is called `your_executeable_here` you run the file with the following:
```bash
./your_executeable_here # linux/mac

# Windows:

.\your_executeable_here.exe # powershell
your_executeable_here.exe # cmd
```

