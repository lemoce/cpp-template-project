add_library (arabic SHARED arabic.cpp)


if (WIN32)
   add_definitions (-DNLIBRARY_API_IMPORT)

   if (NOT EXISTS ${PROJECT_BINARY_DIR}/testBin/${CMAKE_CFG_INTDIR})
      add_custom_command(TARGET arabic POST_BUILD 
                                COMMAND ${CMAKE_COMMAND} -E make_directory
                                        ${PROJECT_BINARY_DIR}/testBin
                                COMMAND ${CMAKE_COMMAND} -E make_directory
                                        ${PROJECT_BINARY_DIR}/testBin/${CMAKE_CFG_INTDIR})
   endif (NOT EXISTS ${PROJECT_BINARY_DIR}/testBin/${CMAKE_CFG_INTDIR})
   add_custom_command(TARGET arabic POST_BUILD 
                             COMMAND ${CMAKE_COMMAND} -E copy_if_different
                                     ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/arabic.dll
                                     ${PROJECT_BINARY_DIR}/testBin/${CMAKE_CFG_INTDIR})
endif (WIN32)                          

install (TARGETS arabic DESTINATION ${CMAKE_PREFIX_PATH}/lib)
