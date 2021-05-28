cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_64/lib/cmake")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)


set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Charts Qt5::Gui Qt5::Widgets)

add_executable(${PROJECT_NAME} main.cpp
        Validators/admin_input_validator.cpp
        Validators/admin_input_validator.h
        UI/UI.h
        UI/UI.cpp
        Tests/tests.cpp
        Tests/tests.h
        Service/AdminService.cpp
        Service/AdminService.h
        Service/UserService.cpp
        Service/UserService.h
        Repository/CSVWatchList.cpp
        Repository/CSVWatchList.h
        Repository/FileRepository.cpp
        Repository/FileRepository.h
        Repository/HTMLWatchList.cpp
        Repository/HTMLWatchList.h
        Repository/WatchListRepository.cpp
        Repository/WatchListRepository.h
        Exception/repository_exception.cpp
        Exception/repository_exception.h
        Exception/validation_exception.cpp
        Exception/validation_exception.h
        Domain/tutorial.cpp
        Domain/tutorial.h
        GUI/QtMenu.cpp
        GUI/QtMenu.h GUI/AdminGUI.cpp GUI/AdminGUI.h GUI/UserGUI.cpp GUI/UserGUI.h manager/Manager.cpp manager/Manager.h GUI/PersistenceGUI.cpp GUI/PersistenceGUI.h GUI/ChartGUI.cpp GUI/ChartGUI.h Service/AdminServiceUndoRedo.cpp Service/AdminServiceUndoRedo.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
if (WIN32)
    set(DEBUG_SUFFIX)
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB ${REQUIRED_LIBS})
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt${QT_VERSION}${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
