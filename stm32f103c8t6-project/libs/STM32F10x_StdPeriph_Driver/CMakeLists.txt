aux_source_directory(src stdp_SRCS)
message(STATUS "stdp source list：${stdp_SRCS}")
add_library(stdp STATIC ${stdp_SRCS})
target_include_directories(stdp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_compile_options(stdp PRIVATE -include stm32f10x_ASSERT.h)
target_compile_options(stdp PRIVATE
    ${cpu_PARAMS}
    ${compiler_OPTS}
    -Wall
    -Wextra
    -Wpedantic
    -Wno-unused-parameter
    $<$<COMPILE_LANGUAGE:C>: >
    $<$<COMPILE_LANGUAGE:CXX>:

    # -Wno-volatile
    # -Wold-style-cast
    # -Wuseless-cast
    # -Wsuggest-override
    >
    $<$<COMPILE_LANGUAGE:ASM>:-x assembler-with-cpp -MMD -MP>
    $<$<CONFIG:Debug>:-Og -g3 -ggdb>
    $<$<CONFIG:Release>:-Og -g0>
)