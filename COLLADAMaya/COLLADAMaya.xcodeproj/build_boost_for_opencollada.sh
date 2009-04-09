#!/bin/bash

#force build of jam
./configure --show-libraries

#build
./tools/jam/src/bin.linuxx86_64/bjam \
--prefix=$HOME \
--with-regex \
--with-system \
--with-filesystem \
variant=release \
link=static \
install
