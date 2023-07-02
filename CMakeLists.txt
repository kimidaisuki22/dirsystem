cmake_minimum_required(VERSION 3.0.0)
project(dirsystem VERSION 0.0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()


add_library(dirsystem src/dirsystem.cpp src/app_dirs.cpp)

target_include_directories(dirsystem PUBLIC include)

if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})

# add_executable(example example/example.cpp)
# target_link_libraries(example dirsystem)

include(GNUInstallDirs)
install(TARGETS dirsystem)
install(DIRECTORY include DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
include(CPack)

endif()
