stm32f103c8t6 template project  
use [stm32cubeCLT](https://www.st.com/en/development-tools/stm32cubeclt.html) and [STM32 VS Code Extension](https://marketplace.visualstudio.com/items?itemName=stmicroelectronics.stm32-vscode-extension) build project.  
this project depends on the make build system so you need to install cmake and vscode cmake tools extension.  
config settings.json to add cross compilation toolchain path
~~~json
    "STM32VSCodeExtension.cubeCLT.path": "<stm32cubeclt path>"
~~~
run STM32VSCodeExtension generate project folder  
upload and add CMSIS core files to your project
~~~
<project folder>/Inc/stm32f10x.h
<project folder>/Inc/system_stm32f10x.h
<project folder>/Src/system_stm32f10x.c
<project folder>/Inc/core_cm3.h
<project folder>/Src/core_cm3.c
~~~
config your `project folder`/cmake/gcc-arm-none-eabi.cmake
~~~cmake
set(TOOLCHAIN_PREFIX		<stm32cubeclt path>/GNU-tools-for-STM32/bin/arm-none-eabi-)
~~~
config your `project folder`/cmake/vscode_generated.cmake
~~~cmake
set(sources_SRCS ${sources_SRCS}
	${CMAKE_CURRENT_SOURCE_DIR}/Src/main.c
	${CMAKE_CURRENT_SOURCE_DIR}/Src/core_cm3.c
	${CMAKE_CURRENT_SOURCE_DIR}/Src/system_stm32f10x.c
	${CMAKE_CURRENT_SOURCE_DIR}/Src/syscall.c
	${CMAKE_CURRENT_SOURCE_DIR}/Src/sysmem.c
	${CMAKE_CURRENT_SOURCE_DIR}/Startup/startup_stm32f103c8tx.s
)
set(include_c_DIRS ${include_c_DIRS}
	${CMAKE_CURRENT_SOURCE_DIR}/Inc
)
~~~
if cmake version not support toolchain(stm32cubeclt) you may need add the cmake parameter to settings.json
~~~json
    "cmake.configureArgs": [
        "-DCMAKE_C_COMPILER=/opt/st/stm32cubeclt_1.15.1/GNU-tools-for-STM32/bin/arm-none-eabi-gcc",
        "-DCMAKE_CXX_COMPILER=/opt/st/stm32cubeclt_1.15.1/GNU-tools-for-STM32/bin/arm-none-eabi-g++"
    ]
~~~
