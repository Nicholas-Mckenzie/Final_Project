Easies method to run program
- Open the bin folder and click on Final_Project.exe

Harder Method if you want to compile yourself
1. Download wxWidgets and build its source code if needed you only need the x86 versions
2. Open the visual studio solution in the folder
3. Make sure that the platform is x86
4. Open the Properties Manager and change to All Configurations and Win32
5. Under Property Pages in the C/C++ section in the Additional Include Directories remove the two lines
   dependencies/wxWidgets/include/msvc and
   dependencies/wxWidgets/include 
6. Then in the same location you have to add 2 lines.
   1. the filepath to your wxWidgets/include/msvc, and 2. wxWidgets/include
7. Under property Pages in the Linker general section in the Additional Library Directories delete the line
   dependencies/wxWidgets/lib/vc_lib
8. Then in the same location you have to add 1 line
   which is the file path to your wxWidgets/lib/vc_lib
