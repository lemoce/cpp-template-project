cmake_minimum_required (VERSION 2.8)
project (roman)

add_subdirectory (src)

enable_testing ()

set(Boost_USE_STATIC_LIBS ON)
find_package (Boost COMPONENTS unit_test_framework REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/src)

file (GLOB TEST_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} test/*.cpp)

foreach (testSrc ${TEST_SRC})
	get_filename_component (testName ${testSrc} NAME_WE)

	add_executable (${testName} ${testSrc})
	target_link_libraries (${testName} ${Boost_LIBRARIES} arabic)

	set_target_properties (${testName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/testBin)

	add_test (NAME ${testName}
		 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/testBin
		 COMMAND ${CMAKE_CURRENT_BINARY_DIR}/testBin/${testName} )

endforeach (testSrc)
