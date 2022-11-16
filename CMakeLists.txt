cmake_minimum_required(VERSION 3.10)

set(project_name wx)

project(${project_name})

set(CMAKE_CXX_STANDARD 11)

if(CMAKE_SYSTEM_NAME MATCHES "Linux") 
    message("Linux Platform is supported")
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
    message("Windows Platform is supported")
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    message("Darwin Platform is supported")
    set(CMAKE_AUTOMOC ON)
    # set(MACOSX_BUNDLE_ICON_FILE logo)
    # set(r3_ICON ../r3.ico)
    # set_source_files_properties(${r3_ICON} PROPERTIES 
    #     MACOSX_PACKAGE_LOCATION "Resouces"
    # )
else()
    message("Unknow Platform is not supported")
endif()

find_package(wxWidgets REQUIRED COMPONENTS net core base gl)
include(${wxWidgets_USE_FILE})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(spdlog REQUIRED)

## add executables
add_executable(${project_name}
    src/Tetris.cpp
    src/Board.cpp
    src/Shape.cpp
    src/burning.cpp
    src/widget.cpp
    src/shapes.cpp
    src/gradient.cpp
    src/Regions.cpp
    src/pen.cpp
    src/point.cpp
    src/text.cpp
    src/line.cpp
    src/textdrop.cpp
    src/scrolledwindow.cpp
    src/Notebook.cpp
    src/Listbox.cpp
    src/Slider.cpp
    src/statictext.cpp
    src/staticline.cpp
    src/togglebutton.cpp
    src/bitmapbutton.cpp
    src/checkbox.cpp
    src/customdialog.cpp
    src/fontdialog.cpp
    src/openfile.cpp
    src/Messages.cpp
    src/ident.cpp
    src/veto.cpp
    src/propagate.cpp
    src/move.cpp
    src/button2.cpp
    src/flexgridsizer.cpp
    src/gridsizer.cpp
    src/gotoclass.cpp
    src/align.cpp
    src/border.cpp
    src/sizer.cpp
    src/absolute.cpp
    src/toolbars.cpp
    # src/toolbar.cpp
    src/menu.cpp
    src/Communicate.cpp
    src/Panels.cpp
    src/button.cpp
    src/icon.cpp
    src/frame.cpp
    src/app.cpp
    src/main.cpp
    )
target_link_libraries(${project_name} 
    ${OPENGL_LIBRARIES}
    ${OPENGL_gl_LIBRARY}
    ${OPENGL_glu_LIBRARY}
    ${wxWidgets_LIBRARIES}
    spdlog::spdlog)
