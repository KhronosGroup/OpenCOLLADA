import os

IGNORE = (
    "/COLLADAMax/",
    "/COLLADAMaya/",
    "/G3DWarehouseBrowser/",
    "/dae2ma/",
    "/dae2ogre/",
    "/dae23ds_lib3ds/",
    "/dae23ds/",
    "/common/libftoa/include/unitTest/",
    "/common/libftoa/include/performanceTest/",
    
    # externals
    "/Externals/zziplib/",
    "/Externals/zlib/",
    "/Externals/expat/",
    "/Externals/MayaDataModel/",
    "/Externals/Cg/",
    "/Externals/LibXML/",

    # specific source files
    "common/libftoa/include/itoaUnitTest.h",
    "dae2ogre/template/template.h",
    "COLLADABaseUtils/template/template.h",
    "COLLADAFramework/template/template.h",
    "COLLADAMax/template/template.h",
    "COLLADAMaya/template/template.h",
    "COLLADASaxFrameworkLoader/template/template.h",
    "COLLADAStreamWriter/template/template.h",
    "GeneratedSaxParser/template/template.h",
    "dae23ds/template/template.h",
    "dae2ma/template/template.h",

    "COLLADABaseUtils/template/template.cpp",
    "COLLADAFramework/template/template.cpp",
    "COLLADASaxFrameworkLoader/template/template.cpp",
    "COLLADAStreamWriter/template/template.cpp",
    "GeneratedSaxParser/template/template.cpp",
    "common/libBuffer/src/performanceTest/main.cpp",
    "common/libBuffer/src/performanceTest/performanceTest.cpp",
    "common/libBuffer/src/unitTest/main.cpp",
    "common/libftoa/src/itoaUnitTest.cpp",
    "common/libftoa/src/performanceTest/main.cpp",
    "common/libftoa/src/performanceTest/performanceTest.cpp",
    "common/libftoa/src/unitTest/dtoaUnitTest.cpp",
    "common/libftoa/src/unitTest/ftoaUnitTest.cpp",
    "common/libftoa/src/unitTest/main.cpp",
    )

UTF8_CHECK = False

SOURCE_DIR = os.path.normpath(os.path.abspath(os.path.normpath(os.path.join(os.path.dirname(__file__), ".."))))
