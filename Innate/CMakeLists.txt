project(Innate)

# Source files
file(GLOB_RECURSE INNATE_SRC CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/**.cpp"
)
# Only .cpp files should be compiled
#    "${CMAKE_CURRENT_SOURCE_DIR}/src/Innate/*.h"

# DLLS
add_library(Innate SHARED ${INNATE_SRC})

# Include paths
target_include_directories(Innate PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Innate
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
)

#target_link_libraries(Innate PRIVATE spdlog)

# Preprocessor defines
if(WIN32)
	if(CMAKE_SIZEOF_VOID_P EQUAL 8)
		target_compile_definitions(Innate PUBLIC IN_PLATFORM_WINDOWS IN_BUILD_DLL)
	endif()
elseif(UNIX AND NOT APPLE)
	target_compile_definitions(Innate PUBLIC IN_PLATFORM_LINUX IN_LINUX_SHARE)
else()
	message(FATAL_ERROR "Unsupported platform")
endif()
#target_compile_definitions(Innate PUBLIC IN_PLATFORM_WINDOWS IN_BUILD_DLL)

if(PRODUCTION_BUILD)
    target_compile_definitions(Innate PUBLIC
        PRODUCTION_BUILD=1
        DEVELOPMENT_BUILD=0
        RESOURCES_PATH="./resources/"
    )
else()
    target_compile_definitions(Innate PUBLIC
        PRODUCTION_BUILD=0
        DEVELOPMENT_BUILD=1
        RESOURCES_PATH="${CMAKE_SOURCE_DIR}/resources/"
    )
endif()

# Platform-specific
if(MSVC)
    target_compile_options(Innate PRIVATE /utf-8 /arch:AVX2 /UUNICODE /U_UNICODE)
    target_compile_definitions(Innate PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

# Output folders
set_target_properties(Innate PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}/$<CONFIG>/Innate"
    ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}/$<CONFIG>/Innate"
    LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}/$<CONFIG>/Innate"
    INTERPROCEDURAL_OPTIMIZATION_RELEASE ON
)
