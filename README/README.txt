Easies method to run program
- Open the bin folder and click on Final_Project.exe

Harder Method if you want to compile yourself
1. Download wxWidgets and build its source code
2. Open the visual studio solution in the folder
3. Under Property Pages in the C/C++ section in the Additional Include Directories you have to add
   2 lines. 1. the filepath to wxWidgets/include/msvc, and 2. wxWidgets/include
4. Under property Pages in the Linker section in the Additional Library Directories you have to add
   1 line which is the file path to wxWidgets/lib/vc_lib
