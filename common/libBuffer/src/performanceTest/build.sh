
OPTIONS="-O3 -Wall"

INCLUDES="-I../../include -I../../include/performanceTest -I../../../libftoa/include"

BUFFERFILES="main.cpp performanceTest.cpp ../CommonBuffer.cpp ../CommonFWriteBufferFlusher.cpp ../CommonCharacterBuffer.cpp ../CommonStreamBufferFlusher.cpp "

FTOAFILES="../../../libftoa/src/Commondtoa.cpp ../../../libftoa/src/Commonftoa.cpp"

FILES=$BUFFERFILES$FTOAFILES

OUTPUTFILE="-o performanceTest"



g++ $OPTIONS $INCLUDES $FILES $OUTPUTFILE