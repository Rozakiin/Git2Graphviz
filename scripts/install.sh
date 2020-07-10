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
./b2 --prefix=../../ install && 
cd ../../ &&
./bin/b2 --show-libraries && #(to test correct installation of b2 might not needed)
./bin/b2 --with-program_options --with-graph --build-type=complete &&
cd "$pwd"
exit 0