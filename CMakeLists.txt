cmake_minimum_required(VERSION 3.0.0)

project(AnalogueClock)
set(SRC
    main.cpp
	Application.cpp
	Draw.cpp
	Clock.cpp
)
add_executable(${PROJECT_NAME} ${SRC})
