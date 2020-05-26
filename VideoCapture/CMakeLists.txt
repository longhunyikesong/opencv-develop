cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(videocapture)

#find_package(OpenCV REQUIRED)

set(INCLUDE_DIRS /usr/local/include/opencv4)
set(LINK_DIRS /usr/local/lib)

include_directories(${INCLUDE_DIRS})
link_directories(${LINK_DIRS})

set(OpenCV_LIBS opencv_core opencv_highgui opencv_videoio opencv_imgproc)

add_executable(videocapture main.cpp)
target_link_libraries(videocapture PRIVATE ${OpenCV_LIBS})
