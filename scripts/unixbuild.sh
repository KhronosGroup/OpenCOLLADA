#!/bin/bash
export DIR=$1
cd `dirname $0`;
if test -z $1 ; then 
   export DIR=$PWD/../installed-opencollada
fi
if test -z $NUM_PROCS; then
   export NUM_PROCS=-j2
fi
echo installing static libraries to ${DIR}/lib/ with $NUM_PROCS processors

mkdir -p ${DIR}/lib

export SCRIPTPATH=$PWD

               cd ../Externals/LibXML &&
               sh ./autogen.sh CFLAGS=-fPIC CXXFLAGS=-fPIC LDFLAGS=-fPIC --disable-shared --enable-static --without-iconv --prefix=${DIR} &&
               ( (make  CFLAGS=-fPIC CXXFLAGS=-fPIC LDFLAGS=-fPIC  $NUM_PROCS && make install) || cp .libs/lib* ${DIR}/lib/) &&
               cd ../.. &&
               cd Externals/pcre/scripts &&
               ruby $SCRIPTPATH/vcproj2cmake.rb pcre.vcproj &&
               cmake . -DCMAKE_CXX_COMPILER=`which g++` -DCMAKE_C_COMPILER=`which gcc` -DCMAKE_CXX_FLAGS="-fPIC  -g2" -DCMAKE_C_FLAGS="-fPIC  -g2" -DCMAKE_SHARED_LINKER_FLAGS="-fPIC" -DCMAKE_MODULE_LINKER_FLAGS="-fPIC" &&
               make $NUM_PROCS &&
               cd ../../.. &&
               cd Externals/MathMLSolver/scripts &&
               ruby $SCRIPTPATH/vcproj2cmake.rb MathMLSolver.vcproj &&
#               cat CMakeLists.txt | sed -e "s/-DWIN32/-DGENERATEDSAXPARSER_XMLPARSER_LIBXML -DGENERATEDSAXPARSER_VALIDATION -DPCRE_STATIC/" > CMakeLists.bak &&
#               cat CMakeLists.bak | sed -e "s/\\/ast/\\/AST/" > CMakeLists.txt &&
#               ln -sf $PWD/../include/MathMLSymbolTable.h $PWD/../include/AST/MathMLSymboltable.h &&
               cmake . -DCMAKE_CXX_COMPILER=`which g++` -DCMAKE_C_COMPILER=`which gcc` -DCMAKE_CXX_FLAGS="-fPIC  -g2"  -DCMAKE_C_FLAGS="-fPIC  -g2" -DCMAKE_SHARED_LINKER_FLAGS="-fPIC" -DCMAKE_MODULE_LINKER_FLAGS="-fPIC" &&
               make $NUM_PROCS &&
               cd ../../.. &&
               cd Externals/UTF &&
               gcc -g  -c src/ConvertUTF.c -Iinclude/
               ar cru libConvertUTF.a ConvertUTF.o
               cd ../.. &&
               cd GeneratedSaxParser/scripts &&
               ruby $SCRIPTPATH/vcproj2cmake.rb GeneratedSaxParser.vcproj &&
               echo include_directories\(../../Externals/UTF/include ../../Externals/LibXML/include ../../Externals/pcre/include ../../Externals/MathMLSolver/include/ ../../Externals/MathMLSolver/include/AST ../../COLLADAFramework/include ../../COLLADABaseUtils/include ../../GeneratedSaxParser/include ../include ../include/generated15 ../include/generated14 ../include/Math \) >> CMakeLists.txt &&
               echo add_definitions\( -DGENERATEDSAXPARSER_XMLPARSER_LIBXML  -DGENERATEDSAXPARSER_VALIDATION -DPCRE_STATIC \) >> CMakeLists.txt &&
               echo add_library\(GeneratedSaxParser STATIC \$\{SOURCES\}\) >> CMakeLists.txt &&
               cmake . -DCMAKE_CXX_COMPILER=`which g++` -DCMAKE_C_COMPILER=`which gcc` -DCMAKE_CXX_FLAGS="-fPIC  -g2"  -DCMAKE_C_FLAGS="-fPIC  -g2" -DCMAKE_SHARED_LINKER_FLAGS="-fPIC" -DCMAKE_MODULE_LINKER_FLAGS="-fPIC" &&
               make $NUM_PROCS &&
               cd ../.. &&
               cd COLLADASaxFrameworkLoader/scripts &&
               ruby $SCRIPTPATH/vcproj2cmake.rb COLLADASaxFrameworkLoader.vcproj &&
               echo include_directories\(../../Externals/UTF/include ../../Externals/LibXML/include ../../Externals/pcre/include ../../Externals/MathMLSolver/include/ ../../Externals/MathMLSolver/include/AST ../../COLLADAFramework/include ../../COLLADABaseUtils/include ../../GeneratedSaxParser/include ../include ../include/generated15 ../include/generated14 ../include/Math \) >> CMakeLists.txt &&
               echo add_definitions\( -DGENERATEDSAXPARSER_XMLPARSER_LIBXML  -DGENERATEDSAXPARSER_VALIDATION -DPCRE_STATIC \) >> CMakeLists.txt &&
               echo add_library\(COLLADASaxFrameworkLoader STATIC \$\{SOURCES\}\) >> CMakeLists.txt &&
               cmake . -DCMAKE_CXX_COMPILER=`which g++` -DCMAKE_C_COMPILER=`which gcc` -DCMAKE_CXX_FLAGS="-fPIC  -g2" -DCMAKE_C_FLAGS="-fPIC  -g2" -DCMAKE_SHARED_LINKER_FLAGS="-fPIC" -DCMAKE_MODULE_LINKER_FLAGS="-fPIC" &&
               make $NUM_PROCS &&
               cd ../.. &&
               cd COLLADABaseUtils/scripts &&
               ruby $SCRIPTPATH/vcproj2cmake.rb COLLADABaseUtils.vcproj &&
               cat CMakeLists.txt | sed -e "s/-DWIN32/-DGENERATEDSAXPARSER_XMLPARSER_LIBXML -DGENERATEDSAXPARSER_VALIDATION -DPCRE_STATIC/" > CMakeLists.bak &&
               mv CMakeLists.bak CMakeLists.txt &&
               cmake . -DCMAKE_CXX_COMPILER=`which g++` -DCMAKE_C_COMPILER=`which gcc` -DCMAKE_CXX_FLAGS="-fPIC  -g2" -DCMAKE_C_FLAGS="-fPIC  -g2" -DCMAKE_SHARED_LINKER_FLAGS="-fPIC" -DCMAKE_MODULE_LINKER_FLAGS="-fPIC" &&
               make $NUM_PROCS &&
               cd ../.. &&
               cd COLLADAFramework/scripts &&
               ruby $SCRIPTPATH/vcproj2cmake.rb COLLADAFramework.vcproj &&
               cat CMakeLists.txt | sed -e "s/-DWIN32/-DGENERATEDSAXPARSER_XMLPARSER_LIBXML -DGENERATEDSAXPARSER_VALIDATION -DPCRE_STATIC/" > CMakeLists.bak &&
               mv CMakeLists.bak CMakeLists.txt &&
               cmake . -DCMAKE_CXX_COMPILER=`which g++` -DCMAKE_C_COMPILER=`which gcc` -DCMAKE_CXX_FLAGS="-fPIC  -g2" -DCMAKE_C_FLAGS="-fPIC  -g2" -DCMAKE_SHARED_LINKER_FLAGS="-fPIC" -DCMAKE_MODULE_LINKER_FLAGS="-fPIC" &&
               make $NUM_PROCS &&
               cd ../.. &&
               find GeneratedSaxParser COLLADA* Externals -name *.a -exec cp {} ${DIR}/lib/ \; &&
echo installed static libraries to ${DIR}/lib/

