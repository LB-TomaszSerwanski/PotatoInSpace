
if(NOT PROJECT_NAME)
    cmake_minimum_required(VERSION 3.20)
    include(cmake/CompilerSettings.cmake)
    project(PotatoInSpace
        LANGUAGES C CXX
        VERSION 1.0.0.0
    )
    include(cmake/EngineFinder.cmake OPTIONAL)
    find_package(o3de REQUIRED)
    o3de_initialize()
endif()
