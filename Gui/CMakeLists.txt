
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
    ${Boost_INCLUDE_DIRS}
    ${COIN3D_INCLUDE_DIRS}
    ${ZLIB_INCLUDE_DIR}
    ${PYTHON_INCLUDE_DIRS}
    ${XercesC_INCLUDE_DIRS}
)

set(QuickPreviewGui_LIBS
    QuickPreview
    FreeCADGui
)

if (BUILD_QT5)
    qt5_add_resources(QuickPreview_QRC_SRCS Resources/QuickPreview.qrc)
else()
    qt4_add_resources(QuickPreview_QRC_SRCS Resources/QuickPreview.qrc)
endif()

SET(QuickPreviewGui_SRCS
    ${QuickPreview_QRC_SRCS}
    AppQuickPreviewGui.cpp
    Command.cpp
    PreCompiled.cpp
    PreCompiled.h
    Workbench.cpp
    Workbench.h
)

add_library(QuickPreviewGui SHARED ${QuickPreviewGui_SRCS})
target_link_libraries(QuickPreviewGui ${QuickPreviewGui_LIBS})
#/src/Mod/QuickPreview
fc_target_copy_resource(QuickPreviewGui 
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}/src/Mod/QuickPreview
    InitGui.py)

SET_BIN_DIR(QuickPreviewGui QuickPreviewGui /Mod/QuickPreview)
SET_PYTHON_PREFIX_SUFFIX(QuickPreviewGui)
    
install(TARGETS QuickPreviewGui DESTINATION ${CMAKE_INSTALL_LIBDIR})
