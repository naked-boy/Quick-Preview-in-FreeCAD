##########################################################################
###Added by Deng Junxi on 2018-Feb-3
cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)
project(QuickPreview)
include(AddFileDependencies)
include("D:/what i did/FreeCAD/FreeCAD-master/cMake/FreeCadMacros.cmake")
find_package(Qt4)# REQUIRED
SET(CMAKE_INSTALL_LIBDIR lib CACHE PATH "Output directory for libraries")
SET(CMAKE_SOURCE_DIR "D:/what i did/FreeCAD/FreeCAD-master")
SET(CMAKE_BINARY_DIR "D:/what i did/FreeCAD/FreeCAD-master Build/src")
SET(QuickPreview "D:/what i did/FreeCAD/FreeCAD-master/src/Mod/QuickPreview")
OPTION(BUILD_GUI "Build FreeCAD Gui. Otherwise you have only the command line and the Python import module." ON)
###
##########################################################################

add_subdirectory(App)
if(BUILD_GUI)
    add_subdirectory(Gui)
endif(BUILD_GUI)

install(
    FILES
        Init.py
        InitGui.py
    DESTINATION
        Mod/QuickPreview
)
