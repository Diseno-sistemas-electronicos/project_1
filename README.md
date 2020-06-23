# Project 1
## Dependencies
```sh
sudo apt install python3-pip ninja-build
sudo pip3 install meson
```
## Installing System C
This will install System C 2.3.4.
```
git clone https://github.com/accellera-official/systemc
git checkout release
cd systemc
mkdir build && cd build
export CXX=g++
../autoreconf
../configure --with-unix-layout --prefix=/usr/local/ --enable-debug
make -j$(nproc)
sudo make install
```

## Building the examples
```
meson build
ninja -C build
```
And then run the executables inside the build folder.

## Common Errors

### undefined reference to `sc_main'
The error
```
undefined reference to `sc_main'
```
means that every test bench (tb) must have a starting point called sc_main. The main function.