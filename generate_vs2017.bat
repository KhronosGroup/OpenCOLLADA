set current_dir=%~dp0
set cmake_temp_dir=cmake_temp_msvc2017
rd /Q /S %cmake_temp_dir%
mkdir %cmake_temp_dir%
cd %cmake_temp_dir%
cmake -G "Visual Studio 15 2017 Win64" ..\
cd %current_dir%