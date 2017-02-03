set current_dir=%~dp0
set cmake_temp_dir=cmake_temp_msvc2013
rd /Q /S %cmake_temp_dir%
mkdir %cmake_temp_dir%
cd %cmake_temp_dir%
cmake -G "Visual Studio 12 2013 Win64" ..\
cd %current_dir%