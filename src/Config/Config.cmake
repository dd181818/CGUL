include(CheckIncludeFileCXX)
include(CheckCXXCompilerFlag)

macro(check_feature VARIABLE FILE)
    try_compile(FEATURE_COMPILES ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/Config/${FILE}
        CMAKE_FLAGS "-DCMAKE_CXX_LINK_EXECUTABLE='echo a'" # this line stops cmake from linking on the try_compile call
        OUTPUT_VARIABLE OUTPUT
      )
    if(${FEATURE_COMPILES})
        set(${VARIABLE} ON)
    else()
        file(APPEND ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeError.log
          "Unable to compile config test script ${FILE}!"
          "The test file ${FILE} failed to compile:"
          "${OUTPUT}\n\n"
        )
    endif()
endmacro()

check_include_file_cxx(algorithm CPP_HEADER_ALGORITHM)
check_include_file_cxx(cctype CPP_HEADER_CCTYPE)
check_include_file_cxx(fstream CPP_HEADER_FSTREAM)
check_include_file_cxx(list CPP_HEADER_LIST)
check_include_file_cxx(map CPP_HEADER_MAP)
check_include_file_cxx(memory CPP_HEADER_MEMORY)
check_include_file_cxx(sstream CPP_HEADER_SSTREAM)
check_include_file_cxx(stdexcept CPP_HEADER_STDEXCEPT)
check_include_file_cxx(string CPP_HEADER_STRING)
check_include_file_cxx(thread CPP_HEADER_THREAD)
check_include_file_cxx(utility CPP_HEADER_UTILITY)
check_include_file_cxx(vector CPP_HEADER_VECTOR)

check_include_file_cxx(cstdint CPP_HEADER_CSTDINT)
check_include_file_cxx(stdint.h CPP_HEADER_STDINT_H)

check_feature(CPP_HAS_DOUBLE_REFERENCE double_reference.cpp)
check_feature(CPP_HAS_HYPERBOLIC_ARC hyperbolic_arc.cpp)
check_feature(CPP_HAS_MOVE_CONSTRUCTOR move_constructor.cpp)
check_feature(CPP_HAS_PTHREAD pthread.cpp)
check_feature(CPP_HAS_STATIC_ASSERT static_assert.cpp)
check_feature(CPP_HAS_STD_MOVE std_move.cpp)
check_feature(CPP_HAS_STD_REGEX std_regex.cpp)
check_feature(CPP_HAS_STD_THREAD std_thread.cpp)
check_feature(CPP_HAS_U8 u8.cpp)

check_feature(PCRE_HAS_FREE_STUDY pcre_free_study.cpp)

if(Jatta_REFRESH_LIBRARIES)
    unset(Jatta_USE_NETWORK CACHE)
    unset(Jatta_USE_OPENGL CACHE)
endif()
jatta_define_feature(Jatta_STATIC "Build a static library." OFF)
jatta_define_feature(Jatta_USE_NETWORK "Compile with networking features.")
jatta_define_feature(Jatta_USE_OPENGL "Compile with OpenGL support (requires glew)." glew)

set(Jatta_INLINE_DEFINE "" CACHE STRING "The inline to use for a function define.")
mark_as_advanced(Jatta_INLINE_DEFINE)
set(Jatta_INLINE_IMPLEMENT "inline" CACHE STRING "The inline to use for a function implementation.")
mark_as_advanced(Jatta_INLINE_IMPLEMENT)

# MinGW
if (MINGW)
    if(Jatta_USE_NETWORK)
        jatta_common_library(ws2_32)
    endif()
    if(Jatta_USE_OPENGL)
        jatta_common_library(opengl32)
    endif()
# Visual Studio
elseif(MSVC)
# MacOS
elseif(APPLE)
# Linux
else()
endif()