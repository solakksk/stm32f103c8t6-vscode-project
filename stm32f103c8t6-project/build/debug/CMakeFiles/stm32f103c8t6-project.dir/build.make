# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/build/debug

# Include any dependencies generated for this target.
include CMakeFiles/stm32f103c8t6-project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stm32f103c8t6-project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stm32f103c8t6-project.dir/flags.make

CMakeFiles/stm32f103c8t6-project.dir/Src/main.c.obj: CMakeFiles/stm32f103c8t6-project.dir/flags.make
CMakeFiles/stm32f103c8t6-project.dir/Src/main.c.obj: ../../Src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/stm32f103c8t6-project.dir/Src/main.c.obj"
	/opt/st/stm32cubeclt_1.15.1/GNU-tools-for-STM32/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/stm32f103c8t6-project.dir/Src/main.c.obj   -c /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/Src/main.c

CMakeFiles/stm32f103c8t6-project.dir/Src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/stm32f103c8t6-project.dir/Src/main.c.i"
	/opt/st/stm32cubeclt_1.15.1/GNU-tools-for-STM32/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/Src/main.c > CMakeFiles/stm32f103c8t6-project.dir/Src/main.c.i

CMakeFiles/stm32f103c8t6-project.dir/Src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/stm32f103c8t6-project.dir/Src/main.c.s"
	/opt/st/stm32cubeclt_1.15.1/GNU-tools-for-STM32/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/Src/main.c -o CMakeFiles/stm32f103c8t6-project.dir/Src/main.c.s

CMakeFiles/stm32f103c8t6-project.dir/Src/syscall.c.obj: CMakeFiles/stm32f103c8t6-project.dir/flags.make
CMakeFiles/stm32f103c8t6-project.dir/Src/syscall.c.obj: ../../Src/syscall.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/stm32f103c8t6-project.dir/Src/syscall.c.obj"
	/opt/st/stm32cubeclt_1.15.1/GNU-tools-for-STM32/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/stm32f103c8t6-project.dir/Src/syscall.c.obj   -c /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/Src/syscall.c

CMakeFiles/stm32f103c8t6-project.dir/Src/syscall.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/stm32f103c8t6-project.dir/Src/syscall.c.i"
	/opt/st/stm32cubeclt_1.15.1/GNU-tools-for-STM32/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/Src/syscall.c > CMakeFiles/stm32f103c8t6-project.dir/Src/syscall.c.i

CMakeFiles/stm32f103c8t6-project.dir/Src/syscall.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/stm32f103c8t6-project.dir/Src/syscall.c.s"
	/opt/st/stm32cubeclt_1.15.1/GNU-tools-for-STM32/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/Src/syscall.c -o CMakeFiles/stm32f103c8t6-project.dir/Src/syscall.c.s

CMakeFiles/stm32f103c8t6-project.dir/Src/sysmem.c.obj: CMakeFiles/stm32f103c8t6-project.dir/flags.make
CMakeFiles/stm32f103c8t6-project.dir/Src/sysmem.c.obj: ../../Src/sysmem.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/stm32f103c8t6-project.dir/Src/sysmem.c.obj"
	/opt/st/stm32cubeclt_1.15.1/GNU-tools-for-STM32/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/stm32f103c8t6-project.dir/Src/sysmem.c.obj   -c /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/Src/sysmem.c

CMakeFiles/stm32f103c8t6-project.dir/Src/sysmem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/stm32f103c8t6-project.dir/Src/sysmem.c.i"
	/opt/st/stm32cubeclt_1.15.1/GNU-tools-for-STM32/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/Src/sysmem.c > CMakeFiles/stm32f103c8t6-project.dir/Src/sysmem.c.i

CMakeFiles/stm32f103c8t6-project.dir/Src/sysmem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/stm32f103c8t6-project.dir/Src/sysmem.c.s"
	/opt/st/stm32cubeclt_1.15.1/GNU-tools-for-STM32/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/Src/sysmem.c -o CMakeFiles/stm32f103c8t6-project.dir/Src/sysmem.c.s

CMakeFiles/stm32f103c8t6-project.dir/Startup/startup_stm32f103c8tx.s.obj: CMakeFiles/stm32f103c8t6-project.dir/flags.make
CMakeFiles/stm32f103c8t6-project.dir/Startup/startup_stm32f103c8tx.s.obj: ../../Startup/startup_stm32f103c8tx.s
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building ASM object CMakeFiles/stm32f103c8t6-project.dir/Startup/startup_stm32f103c8tx.s.obj"
	/opt/st/stm32cubeclt_1.15.1/GNU-tools-for-STM32/bin/arm-none-eabi-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/stm32f103c8t6-project.dir/Startup/startup_stm32f103c8tx.s.obj -c /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/Startup/startup_stm32f103c8tx.s

# Object files for target stm32f103c8t6-project
stm32f103c8t6__project_OBJECTS = \
"CMakeFiles/stm32f103c8t6-project.dir/Src/main.c.obj" \
"CMakeFiles/stm32f103c8t6-project.dir/Src/syscall.c.obj" \
"CMakeFiles/stm32f103c8t6-project.dir/Src/sysmem.c.obj" \
"CMakeFiles/stm32f103c8t6-project.dir/Startup/startup_stm32f103c8tx.s.obj"

# External object files for target stm32f103c8t6-project
stm32f103c8t6__project_EXTERNAL_OBJECTS =

stm32f103c8t6-project.elf: CMakeFiles/stm32f103c8t6-project.dir/Src/main.c.obj
stm32f103c8t6-project.elf: CMakeFiles/stm32f103c8t6-project.dir/Src/syscall.c.obj
stm32f103c8t6-project.elf: CMakeFiles/stm32f103c8t6-project.dir/Src/sysmem.c.obj
stm32f103c8t6-project.elf: CMakeFiles/stm32f103c8t6-project.dir/Startup/startup_stm32f103c8tx.s.obj
stm32f103c8t6-project.elf: CMakeFiles/stm32f103c8t6-project.dir/build.make
stm32f103c8t6-project.elf: CMakeFiles/stm32f103c8t6-project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable stm32f103c8t6-project.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stm32f103c8t6-project.dir/link.txt --verbose=$(VERBOSE)
	/opt/st/stm32cubeclt_1.15.1/GNU-tools-for-STM32/bin/arm-none-eabi-size /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/build/debug/stm32f103c8t6-project.elf
	/opt/st/stm32cubeclt_1.15.1/GNU-tools-for-STM32/bin/arm-none-eabi-objcopy -O ihex /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/build/debug/stm32f103c8t6-project.elf stm32f103c8t6-project.hex
	/opt/st/stm32cubeclt_1.15.1/GNU-tools-for-STM32/bin/arm-none-eabi-objcopy -O binary /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/build/debug/stm32f103c8t6-project.elf stm32f103c8t6-project.bin

# Rule to build all files generated by this target.
CMakeFiles/stm32f103c8t6-project.dir/build: stm32f103c8t6-project.elf

.PHONY : CMakeFiles/stm32f103c8t6-project.dir/build

CMakeFiles/stm32f103c8t6-project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stm32f103c8t6-project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stm32f103c8t6-project.dir/clean

CMakeFiles/stm32f103c8t6-project.dir/depend:
	cd /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/build/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/build/debug /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/build/debug /workspaces/stm32f103c8t6-vscode-project/stm32f103c8t6-project/build/debug/CMakeFiles/stm32f103c8t6-project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stm32f103c8t6-project.dir/depend

