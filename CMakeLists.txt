cmake_minimum_required(VERSION 3.9)
project(async)

set(CMAKE_CXX_STANDARD 14)

#add_library(bulk commandblock.cpp observers.cpp interpreter.cpp bulkhandler.cpp)
#add_library(async SHARED async.cpp async.h)


add_executable(async_cli main.cpp)
#target_link_libraries(async bulk)
# target_link_libraries(async_cli  async)
#include(GNUInstallDirs)
#set_target_properties(async PROPERTIES PUBLIC_HEADER async.h)
# set_target_properties(async PROPERTIES PRIVATE_HEADER bulk.h)
#install(TARGETS async LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

#set(CPACK_GENERATOR OSXX11)

#set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
#set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
#set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

#set(CPACK_PACKAGE_CONTACT ivanbasurman88@yandex.ru)

#include(CPack)
