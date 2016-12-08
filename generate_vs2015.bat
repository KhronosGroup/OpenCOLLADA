set current_dir=%~dp0
rd /Q /S cmake_temp
mkdir cmake_temp
cd cmake_temp
cmake -G "Visual Studio 14 2015 Win64" ..\
cd %current_dir%