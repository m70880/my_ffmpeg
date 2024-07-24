cmake_minimum_required(VERSION 3.10)
project(CrossPlatformFFmpeg)

# 设置 FFmpeg 的路径
set(FFMPEG_DIR /usr/local/Cellar/ffmpeg/7.0.1)

# 包含 FFmpeg 头文件
include_directories(${FFMPEG_DIR}/include)

# 链接 FFmpeg 库
link_directories(${FFMPEG_DIR}/lib)

# 查找 FFmpeg 库
find_library(AVFORMAT_LIBRARY avformat HINTS ${FFMPEG_DIR}/lib)
find_library(AVCODEC_LIBRARY avcodec HINTS ${FFMPEG_DIR}/lib)
find_library(AVUTIL_LIBRARY avutil HINTS ${FFMPEG_DIR}/lib)
find_library(SWSCALE_LIBRARY swscale HINTS ${FFMPEG_DIR}/lib)

# 添加可执行文件
add_executable(my_ffmpeg_app main.cpp)

# 链接 FFmpeg 库
target_link_libraries(my_ffmpeg_app ${AVFORMAT_LIBRARY} ${AVCODEC_LIBRARY} ${AVUTIL_LIBRARY} ${SWSCALE_LIBRARY})
