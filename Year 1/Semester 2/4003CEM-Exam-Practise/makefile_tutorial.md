# My Makefile usage

I have a [Makefile](Makefile), it's usage is quite simple. I made it because it's easier for me to compile without having to type out the entire god damn command. Even though that's fun for me. Don't @ me, I know it's weird; like my love for OOP.

## Usage
It has 3 commands for automation and can be added to have more if needed. For my needs, 3 is enough.

### Build
```bash
make build file="filename.cpp" execute="executeable_name" 
```
The filename and executeable name has to be the "" or it will not count it as an argument!

### Build and run... and clear
```bash
make runb file="filename.cpp" execute="executeable_name" # .exe if needed
```
This makes and runs the file and compiles into what is in the execute flag.

### Clean
```bash
make clean # removes *.exe
```
This removes all .exe files for Windows.

#### Made by [Taran Nagra](https://github.com/tarannagra/)