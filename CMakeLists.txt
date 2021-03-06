cmake_minimum_required(VERSION 3.5)

project(Qt_Component VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        component/StartUI/start_ui.cpp component/StartUI/start_ui.h component/StartUI/start_ui.ui resource.qrc component/ScalableMenu/scalable_menu.cpp component/ScalableMenu/scalable_menu.h component/ScalableMenu/scalable_menu.ui component/test.cpp component/test.h component/test.ui component/SysInfo/memory/memory.cpp component/SysInfo/memory/memory.h component/SysInfo/memory/sys_memory.ui component/SysInfo/cpu/cpu.cpp component/SysInfo/cpu/cpu.h component/SysInfo/cpu/sys_cpu.ui component/SysInfo/cpu/model/cpu_thread.cpp component/SysInfo/cpu/model/cpu_thread.h component/SysInfo/memory/model/memory_thread.cpp component/SysInfo/memory/model/memory_thread.h)

if (${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Qt_Component
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            )
else ()
    if (ANDROID)
        add_library(Qt_Component SHARED
                ${PROJECT_SOURCES}
                )
    else ()
        add_executable(Qt_Component
                ${PROJECT_SOURCES}
                )
    endif ()
endif ()

target_link_libraries(Qt_Component PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Qt_Component PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        )

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Qt_Component)
endif ()
