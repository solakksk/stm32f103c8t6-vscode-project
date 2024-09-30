add_library(stdp STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/misc.c)
target_include_directories(stdp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)