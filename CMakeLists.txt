cmake_minimum_required(VERSION 3.9)
project(async VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

set(CMAKE_CXX_STANDARD 14)
find_package(Boost)
include_directories(${Boost_INCLUDE_DIR})

 
add_library(bulk commandblock.cpp observers.cpp interpreter.cpp bulkhandler.cpp)
add_library(libasync SHARED async.cpp async.h)

target_link_libraries(libasync bulk)

include(GNUInstallDirs)
set_target_properties(libasync PROPERTIES PUBLIC_HEADER async.h)
install(TARGETS libasync LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT ivanbasurman88@yandex.ru)

include(CPack)
