cmake_minimum_required(VERSION 3.0.0)
project(dirsystem VERSION 0.0.3)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()


add_library(dirsystem STATIC src/dirsystem.cpp src/app_dirs.cpp src/portable_app_dirs.cpp src/plain_dirs.cpp src/util.cpp)
# set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

target_include_directories(dirsystem PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})

option(DIRSYSTEM_BUILD_EXAMPLE "build example for dirsystem" ON)

if(${DIRSYSTEM_BUILD_EXAMPLE})
add_executable(example example/example.cpp)
target_link_libraries(example dirsystem)
endif()


include(CPack)
include(GNUInstallDirs)
install(TARGETS dirsystem
    EXPORT dirsystem
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION  ${CMAKE_INSTALL_BINDIR}
)
install(EXPORT dirsystem
    FILE dirsystemConfig.cmake
    NAMESPACE dirsystem::
    DESTINATION share/dirsystem
)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

endif()
