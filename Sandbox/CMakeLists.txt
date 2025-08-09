project(Sandbox)

# Source files
file(GLOB_RECURSE SANDBOX_SRC CONFIGURE_DEPENDS "src/*.cpp")

add_executable(Sandbox ${SANDBOX_SRC})

# Links
target_link_libraries(Sandbox PRIVATE Innate)

# Includes
target_include_directories(Sandbox PRIVATE
    "${CMAKE_SOURCE_DIR}/Innate/src"
    "${CMAKE_SOURCE_DIR}/Innate"
    "${CMAKE_SOURCE_DIR}/Innate/vendor/spdlog/include"
)

# Defines
if(WIN32)
	if(CMAKE_SIZEOF_VOID_P EQUAL 8)
		target_compile_definitions(Sandbox PUBLIC IN_PLATFORM_WINDOWS)
	endif()
elseif(UNIX AND NOT APPLE)
	target_compile_definitions(Sandbox PUBLIC IN_PLATFORM_LINUX)
else()
	message(FATAL_ERROR "Unsupported platform!")
endif()
#target_compile_definitions(Sandbox PUBLIC IN_PLATFORM_WINDOWS IN_PLATFORM_LINUX)
#target_compile_definitions(Sandbox PRIVATE IN_CLIENT)

if(PRODUCTION_BUILD)
    target_compile_definitions(Sandbox PUBLIC
        PRODUCTION_BUILD=1
        DEVELOPMENT_BUILD=0
        RESOURCES_PATH="./resources/"
    )
else()
    target_compile_definitions(Sandbox PUBLIC
        PRODUCTION_BUILD=0
        DEVELOPMENT_BUILD=1
        RESOURCES_PATH="${CMAKE_SOURCE_DIR}/resources/"
    )
endif()

# Platform-specific
if(MSVC)
    target_compile_options(Sandbox PRIVATE /utf-8 /arch:AVX2 /UUNICODE /U_UNICODE)
    # "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"  -   WINDOWS subsystem suppresses the console window. mainCRTStartup still expects a main() function (not WinMain()), which is a mismatch for the WINDOWS subsystem
    # "/SUBSYSTEM:CONSOLE /ENTRY:mainCRTStartup"  -   This matches your use of main() in EntryPoint.h and brings up a console window
    set_target_properties(Sandbox PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE /ENTRY:mainCRTStartup")
endif()

# Output folders
set_target_properties(Sandbox PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}/$<CONFIG>/Sandbox"
    ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}/$<CONFIG>/Sandbox"
    LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}/$<CONFIG>/Sandbox"
)

# Copy DLL post-build (only works if Innate is a SHARED library)
add_custom_command(TARGET Sandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:Innate>"
        "$<TARGET_FILE_DIR:Sandbox>"
)
