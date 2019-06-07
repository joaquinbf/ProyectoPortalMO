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
	bool recording;
	uint32_t bufferWidth;
    uint32_t bufferHeight;
    std::vector<char> dataBuffer;
	FormatContext context;
    OutputFormat* videoOutput;
    SwsContext * ctx;
public:
	VideoRecorder();
	~VideoRecorder();
	void startRecording(uint32_t width, uint32_t height);
	void recordFrame(SDL_Renderer* renderer);
	void stopRecording();
	void checkResolution(uint32_t width, uint32_t height);
	std::string generateName();
};

#endif
