project(SmartCalc)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS PrintSupport REQUIRED)

add_executable(${PROJECT_NAME}
main.cc
${MODEL_SOURCES}
${VIEW_SOURCES}
${CONTROLLER_SOURCES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::PrintSupport)
target_include_directories(${PROJECT_NAME} PUBLIC ${HEADERS_RELATIVE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)