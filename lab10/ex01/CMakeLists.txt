cmake_minimum_required(VERSION 3.10)

project(simple_calculator)

add_subdirectory(nse)

add_executable(args args.cpp)
add_executable(calc calc.cpp)
add_executable(calc_expr calc_expr.cpp)

target_link_libraries(calc_expr PRIVATE nse_html)

set(TARGETS args calc calc_expr)

#set(DATA_FILES "")

set_target_properties(
    ${TARGETS}
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO)

foreach(T IN LISTS TARGETS)
    if (MSVC)
        target_compile_options(${T} PRIVATE /Wall /WX)
    else()
        target_compile_options(${T} PRIVATE -Wall -Wextra)
    endif()
endforeach()

#[[
foreach(FN IN LISTS DATA_FILES)
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${FN}
        COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/${FN}
            ${CMAKE_CURRENT_BINARY_DIR}/${FN}
        DEPENDS ${FN})

    add_custom_target(
        data-${FN} ALL DEPENDS
        ${CMAKE_CURRENT_BINARY_DIR}/${FN})
endforeach()
]]
