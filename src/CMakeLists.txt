#*******************************************************************************
# Define libraries
#*******************************************************************************

# MyTinySTL
add_library(MyTinySTL INTERFACE)

target_include_directories(MyTinySTL
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
