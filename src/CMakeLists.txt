cmake_minimum_required(VERSION 3.16)

project(PI_P_App VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(OpenCV_DIR /usr/local/Cellar/opencv/4.8.1_4/lib/cmake/opencv4)

find_package( OpenCV REQUIRED )
find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

include_directories( ${OpenCV_INCLUDE_DIRS} )

qt_add_executable(appPI_P_App
    main.cpp
    customimage.h customimage.cpp
    imageprovider.h imageprovider.cpp
    Tools.h Tools.cpp
    Image_Processing_Cfg.h
    Image_Processing.h Image_Processing.cpp
    imageprocessor.h imageprocessor.cpp
    imageprocessingstep.h imageprocessingstep.cpp
    imageprocessingstepvalue.h imageprocessingstepvalue.cpp
    imageprocessinglist.h imageprocessinglist.cpp
    windowbinarizationstep.h windowbinarizationstep.cpp
    binarizationstep.h binarizationstep.cpp
    blurstep.h blurstep.cpp
    luminositystep.h luminositystep.cpp
    normalizationstep.h normalizationstep.cpp
    noisereductionstep.h noisereductionstep.cpp
    morphologicalstep.h morphologicalstep.cpp
)

qt_add_qml_module(appPI_P_App
    URI PI_P_App
    VERSION 1.0
    QML_FILES main.qml ImageProcessingStep.qml
)

set_target_properties(appPI_P_App PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(appPI_P_App
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(appPI_P_App
    PRIVATE ${OpenCV_LIBS} Qt6::Quick)
