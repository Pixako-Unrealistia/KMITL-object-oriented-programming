cmake_minimum_required(VERSION 3.10)

project(nse_html)

add_executable(html_test html_test.cpp nse/html.cpp)

set(TARGETS html_test)

set_target_properties(
    ${TARGETS}
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO)

foreach(T ${TARGETS})
    if (MSVC)
        target_compile_options(${T} PRIVATE /Wall /WX)
    else()
        target_compile_options(${T} PRIVATE -Wall -Wextra)
    endif()
endforeach()
