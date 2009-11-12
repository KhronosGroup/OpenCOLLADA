###############################################################################
#    Copyright (c) 2008 NetAllied Systems GmbH
#
#    This file is part of COLLADAMaya.
#
#    Portions of the code are:
#    Copyright (c) 2005-2007 Feeling Software Inc.
#    Copyright (c) 2005-2007 Sony Computer Entertainment America
#    Copyright (c) 2004-2005 Alias Systems Corp.
#
#    Licensed under the MIT Open Source License,
#    for details please see LICENSE file or the website
#    http://www.opensource.org/licenses/mit-license.php
###############################################################################

# NOTE: this include is specific to a maya version
# when you want to build this plugin for maya 2008 and 2009
# you have to reset MAYA_LOCATION
include $(MAYA_LOCATION)/devkit/plug-ins/buildconfig

# override compiler if gcc 4.1.2 is installed as default
#CC = gcc
#C++ = g++

# define variables
ARCH = `uname -i`
OS = linux

OUTFILE = COLLADAMaya

OBJ_DIR_OPENCOLLADA = obj/$(OS)_$(ARCH)_openCOLLADA
OBJ_DIR_2008 = obj/$(OS)_$(ARCH)_maya2008
BIN_DIR_2008 = bin/$(OS)_$(ARCH)_maya2008
OBJ_DIR_2009 = obj/$(OS)_$(ARCH)_maya2009
BIN_DIR_2009 = bin/$(OS)_$(ARCH)_maya2009

OPENCOLLADA_INCLUDES = -I../COLLADABaseUtils/include \
                       -I../COLLADABaseUtils/include/Math \
                       -I../COLLADAFramework/include \
                       -I../GeneratedSaxParser/include \
                       -I../COLLADASaxFrameworkLoader/include \
                       -I../COLLADAStreamWriter/include \
                       -I../Externals/UTF/include \
                       -I$(HOME)/include/boost-1_38 \
                       -I$(HOME)/include/libxml2

OPENCOLLADA_SRC_DIRS = ../COLLADABaseUtils/src \
                       ../COLLADABaseUtils/src/Math \
                       ../COLLADAFramework/src \
                       ../GeneratedSaxParser/src \
                       ../COLLADASaxFrameworkLoader/src \
                       ../COLLADAStreamWriter/src

MAYA_PLUGIN_INCLUDES = $(OPENCOLLADA_INCLUDES) \
                       -Iinclude \
                       -I../Externals/MayaDataModel/include/ \
                       -I$(MAYA_LOCATION)/devkit/include \
                       -I$(MAYA_LOCATION)/devkit/plug-ins
MAYA_PLUGIN_SRC_DIR = src
MAYA_PLUGIN_LIBS = -L$(HOME)/lib \
                   -lxml2 \
                   -lboost_regex-gcc41-mt \
                   -lboost_system-gcc41-mt \
                   -lboost_filesystem-gcc41-mt

printUsage:
	@echo use target maya2008 or maya2009
	@echo set MAYA_LOCATION accordingly

mkdirs:
	mkdir -p $(OBJ_DIR_OPENCOLLADA)
	mkdir -p $(OBJ_DIR_2008)
	mkdir -p $(BIN_DIR_2008)
	mkdir -p $(OBJ_DIR_2009)
	mkdir -p $(BIN_DIR_2009)

generateVersionHeader:
	sh generateVersionHeader.sh

openCOLLADA: mkdirs
	# build UTF
	$(CC) -c $(CFLAGS) -I../Externals/UTF/include -o $(OBJ_DIR_OPENCOLLADA)/ConvertUTF.o ../Externals/UTF/src/ConvertUTF.c

	# build openCOLLADA
	for i in $(OPENCOLLADA_SRC_DIRS); do \
		  for j in $$i/*.cpp; do \
			echo $$j; \
			$(C++) -c $(OPENCOLLADA_INCLUDES) $(C++FLAGS) -o $(OBJ_DIR_OPENCOLLADA)/`basename $$j .cpp`.o $$j; \
		done \
	done

compileMaya2008:
	# use includes and flags from imported maya build config file
	for i in $(MAYA_PLUGIN_SRC_DIR)/*.cpp; do \
		echo $$i; \
		$(C++) -c $(INCLUDES) $(C++FLAGS) $(MAYA_PLUGIN_INCLUDES) -o $(OBJ_DIR_2008)/`basename $$i .cpp`.o $$i; \
	done

linkMaya2008:
	$(LD) $(LIBS) $(MAYA_PLUGIN_LIBS) -o $(BIN_DIR_2008)/$(OUTFILE).$(EXT) $(OBJ_DIR_OPENCOLLADA)/*.o $(OBJ_DIR_2008)/*.o

maya2008: openCOLLADA generateVersionHeader compileMaya2008 linkMaya2008

compileMaya2009:
	# use includes and flags from imported maya build config file
	for i in $(MAYA_PLUGIN_SRC_DIR)/*.cpp; do \
		echo $$i; \
		$(C++) -c $(INCLUDES) $(C++FLAGS) $(MAYA_PLUGIN_INCLUDES) -o $(OBJ_DIR_2009)/`basename $$i .cpp`.o $$i; \
	done

linkMaya2009:
	$(LD) $(LIBS) $(MAYA_PLUGIN_LIBS) -o $(BIN_DIR_2009)/$(OUTFILE).$(EXT) $(OBJ_DIR_OPENCOLLADA)/*.o $(OBJ_DIR_2009)/*.o

maya2009: openCOLLADA generateVersionHeader compileMaya2009 linkMaya2009

clean:
	rm -rf $(OBJ_DIR_OPENCOLLADA)
	rm -rf $(OBJ_DIR_2008)
	rm -rf $(BIN_DIR_2008)
	rm -rf $(OBJ_DIR_2009)
	rm -rf $(BIN_DIR_2009)
