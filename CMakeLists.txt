find_package(Qt5 COMPONENTS Widgets Network REQUIRED)

add_executable(TcpVideoReceiver
    main.cpp
    mainwindow.cpp
    mainwindow.ui
)

target_link_libraries(TcpVideoReceiver Qt5::Widgets Qt5::Network)
