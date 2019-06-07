#ifndef _VIDEO_RECORDER_H_
#define _VIDEO_RECORDER_H_

#include <SDL2/SDL.h>
#include <exception>
#include <vector>
#include <string>
extern "C" {
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
}

#include "../include/SdlWindow.h"
#include "../include/SdlTexture.h"
#include "../include/FormatContext.h"
#include "../include/OutputFormat.h"

class VideoRecorder{
	int bufferWidth;
    int bufferHeight;
    std::vector<char> dataBuffer;
	FormatContext context;
    OutputFormat videoOutput;
    SwsContext * ctx;
public:
	explicit VideoRecorder(int32_t width, int32_t height);
	~VideoRecorder();
	void recordFrame(SDL_Renderer* renderer);
	void close();
	std::string generateName();
};

#endif
