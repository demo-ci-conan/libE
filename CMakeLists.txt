cmake_minimum_required(VERSION 2.8.12)
project(demo-ci-conan)

include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(SOURCES src/libE.cpp)
file(GLOB HEADERS include/libE/*)

add_library(libE ${SOURCES} ${HEADERS})
set_target_properties(libE PROPERTIES CXX_STANDARD 17)
target_link_libraries(libE PRIVATE CONAN_PKG::libB CONAN_PKG::libG CONAN_PKG::libI)

target_include_directories(
    libC PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(TARGETS libE
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(FILES ${HEADERS}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/libE
        PERMISSIONS OWNER_WRITE OWNER_READ GROUP_READ WORLD_READ)
