extern "C" {
    #include <libavformat/avformat.h>
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <video_file>\n", argv[0]);
        return -1;
    }

    const char *filename = argv[1];
    AVFormatContext *formatContext = nullptr;

    // 初始化 FFmpeg 库
    avformat_network_init();

    // 打开视频文件
    if (avformat_open_input(&formatContext, filename, nullptr, nullptr) != 0) {
        printf("Could not open file %s\n", filename);
        return -1;
    }

    // 获取视频流信息
    if (avformat_find_stream_info(formatContext, nullptr) < 0) {
        printf("Could not find stream information\n");
        avformat_close_input(&formatContext);
        return -1;
    }

    // 打印视频流信息
    av_dump_format(formatContext, 0, filename, 0);

    // 关闭文件
    avformat_close_input(&formatContext);
    avformat_network_deinit();

    return 0;
}


