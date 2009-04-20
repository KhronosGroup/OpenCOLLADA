#!/bin/bash

OUT_FILE=include/COLLADAMayaVersionInfo.h

echo "#ifndef __COLLADAMAYA_VERSIONINFO_H__" > $OUT_FILE
echo "#define __COLLADAMAYA_VERSIONINFO_H__" >> $OUT_FILE
echo "" >> $OUT_FILE
echo "#include \"COLLADAMayaPrerequisites.h\"" >> $OUT_FILE
echo "" >> $OUT_FILE
echo "namespace COLLADAMaya" >> $OUT_FILE
echo "{" >> $OUT_FILE
echo "    const String CURRENT_REVISION = \"`svnversion`\";" >> $OUT_FILE
echo "    const String CURRENT_PLATFORM = \"`uname -s`\";" >> $OUT_FILE
#    const String CURRENT_CONFIGURATION = "ReleaseConsole2008"; 
echo "}" >> $OUT_FILE
echo "" >> $OUT_FILE
echo "#endif // __COLLADAMAYA_VERSIONINFO_H__" >> $OUT_FILE
echo "" >> $OUT_FILE
