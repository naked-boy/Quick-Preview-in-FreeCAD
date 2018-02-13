
include_directories(
    ${Boost_INCLUDE_DIRS}
    ${OCC_INCLUDE_DIR}
    ${PYTHON_INCLUDE_DIRS}
    ${ZLIB_INCLUDE_DIR}
    ${XercesC_INCLUDE_DIRS}
)

set(QuickPreview_LIBS
    FreeCADApp
)

SET(QuickPreview_SRCS
    AppQuickPreview.cpp
    PreCompiled.cpp
    PreCompiled.h
)

add_library(QuickPreview SHARED ${QuickPreview_SRCS})
target_link_libraries(QuickPreview ${QuickPreview_LIBS})

message("${CMAKE_SOURCE_DIR}")
message("${CMAKE_BINARY_DIR}/src/Mod/QuickPreview")

#/src/Mod/QuickPreview
fc_target_copy_resource(QuickPreview 
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}/src/Mod/QuickPreview
    Init.py)

SET_BIN_DIR(QuickPreview QuickPreview /Mod/QuickPreview)
SET_PYTHON_PREFIX_SUFFIX(QuickPreview)

install(TARGETS QuickPreview DESTINATION ${CMAKE_INSTALL_LIBDIR})
