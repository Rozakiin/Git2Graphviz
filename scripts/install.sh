#!/bin/sh

# Install Boost
echo "Installing Boost... (EXPERIMENTAL)"
pwd=`pwd`
( cd "../lib/boost/tools/build" && ./bootstrap.sh )
if [ $? -ne 0 ]; then
    echo
    echo "Failed to install Boost." 1>&2
    exit 1
fi
cd "../lib/boost/tools/build" &&
./b2 --prefix=../../ install
cd ../../ &&
./bin/b2 --show-libraries  #(to test correct installation of b2 might not needed)
#./bin/b2 --build-dir=build/x86 address-model=32 --stagedir=./stage/x86 --build-type=complete --layout=versioned threading=multi --with-program_options --with-graph
./bin/b2 --build-type=complete --layout=tagged threading=multi --with-program_options --with-graph
cd "$pwd"
exit 0
