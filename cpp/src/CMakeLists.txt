function(link_opengl target)
    target_link_libraries(${target} PRIVATE EGL OpenGL)
    target_link_directories(${target} BEFORE PRIVATE $ENV{EGL_LIBRARY_PATH})
    target_include_directories(${target} SYSTEM BEFORE PUBLIC "${CMAKE_SOURCE_DIR}/cpp/include")
endfunction()

add_executable(main main.cpp minimalegl.h minimalegl.cpp)
link_opengl(main)

if(WITH_PYTHON)
    pybind11_add_module(pyminimalegl MODULE pyminimalegl.cpp minimalegl.h minimalegl.cpp)
    link_opengl(pyminimalegl)
    install(TARGETS pyminimalegl
        RUNTIME DESTINATION "py/minimalegl"
        LIBRARY DESTINATION "py/minimalegl")
endif()