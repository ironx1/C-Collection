set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
add_executable(test ./test.c)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    add_library(Collections SHARED IMPORTED)
    set_target_properties(Collections PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/bin/libCollections.so)
    target_link_libraries(test Collections)
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
    target_link_libraries(test Collections)
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    # Set options for macOS
else()
    message(FATAL_ERROR "Unsupported operating system: ${CMAKE_SYSTEM_NAME}")
endif()