add_library (arabic SHARED arabic.cpp)

install (TARGETS arabic DESTINATION ${CMAKE_PREFIX_PATH}/lib)
