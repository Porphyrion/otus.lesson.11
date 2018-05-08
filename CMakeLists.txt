cmake_minimum_required(VERSION 3.9)
project(Async VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost)
find_package(Threads)
include_directories(${Boost_INCLUDE_DIR})


# add_library(bulk commandblock.cpp observers.cpp interpreter.cpp bulkhandler.cpp)
# set_property(TARGET bulk PROPERTY POSITION_INDEPENDENT_CODE ON)
add_library(async SHARED async.h async.cpp bulk.h commandblock.cpp observers.cpp interpreter.cpp bulkhandler.cpp)
set_target_properties(async  PROPERTIES # bulk
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	COMPILE_OPTION -Wpedantic -Wall -Wextra
	)

target_link_libraries(async
	# bulk
	${CMAKE_THREAD_LIBS_INIT}
)

include(GNUInstallDirs)
set_target_properties(async PROPERTIES PUBLIC_HEADER async.h)
# set_target_properties(async PROPERTIES PRIVATE_HEADER bulk.h)
install(TARGETS async LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} ) # PRIVATE_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT ivanbasurman88@yandex.ru)

include(CPack)
