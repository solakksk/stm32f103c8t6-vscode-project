# This is converter generated file, and shall not be touched by user
#
# Use CMakeLists.txt to apply user changes
cmake_minimum_required(VERSION 3.16)

# Core MCU flags, CPU, instruction set and FPU setup
set(cpu_PARAMS ${cpu_PARAMS}
    -mthumb

    # Other parameters
    # -mcpu, -mfloat, -mfloat-abi, ...
    -mcpu=cortex-m3
	
)

# Linker script
set(linker_script_SRC ${linker_script_SRC}
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32f103c8tx_FLASH.ld
)

# Sources
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/bsp/src bsp_SRCS)
set(sources_SRCS ${sources_SRCS}
    
	${CMAKE_CURRENT_SOURCE_DIR}/Src/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/core_cm3.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/system_stm32f10x.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/stm32f10x_it.c
	${CMAKE_CURRENT_SOURCE_DIR}/Src/syscall.c
	${CMAKE_CURRENT_SOURCE_DIR}/Src/sysmem.c
	#${CMAKE_CURRENT_SOURCE_DIR}/Startup/startup_stm32f103c8tx.s
    ${CMAKE_CURRENT_SOURCE_DIR}/Startup/startup_stm32f10x_md.s
    ${bsp_SRCS}
)

# Include directories
set(include_c_DIRS ${include_c_DIRS}
    
	${CMAKE_CURRENT_SOURCE_DIR}/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/bsp/inc
)
set(include_cxx_DIRS ${include_cxx_DIRS}
    
)
set(include_asm_DIRS ${include_asm_DIRS}
    
)

# Symbols definition
set(symbols_c_SYMB ${symbols_c_SYMB}

)
set(symbols_cxx_SYMB ${symbols_cxx_SYMB}
    
)
set(symbols_asm_SYMB ${symbols_asm_SYMB}
    
)

# Link directories
set(link_DIRS ${link_DIRS}
    
)

# Link libraries
set(link_LIBS ${link_LIBS}
    
)

# Compiler options
set(compiler_OPTS ${compiler_OPTS})

# Linker options
set(linker_OPTS ${linker_OPTS})
