#include "../include/videoRecorder.h"

VideoRecorder::VideoRecorder(int32_t width, int32_t height):
bufferWidth(width), bufferHeight(height), videoOutput(this->context, this->generateName())
{
	this->ctx = sws_getContext(this->bufferWidth, this->bufferHeight,
        AV_PIX_FMT_RGB24, this->bufferWidth, this->bufferHeight,
        AV_PIX_FMT_YUV420P, 0, 0, 0, 0);
	this->dataBuffer.resize(this->bufferWidth*this->bufferHeight*3);
}

VideoRecorder::~VideoRecorder(){}

void VideoRecorder::recordFrame(SDL_Renderer* renderer){
    int res = SDL_RenderReadPixels(renderer, NULL, 
    	SDL_PIXELFORMAT_RGB24, this->dataBuffer.data(), this->bufferWidth*3);
    if (res) {
        //mejor tirar error
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "RendererReadPixels error", 
        	SDL_GetError(), NULL);
    }
    this->videoOutput.writeFrame(this->dataBuffer.data(), this->ctx);
}

void VideoRecorder::close(){
    this->videoOutput.close();
    sws_freeContext(ctx);
}

std::string VideoRecorder::generateName(){
	return std::string("HARCODED.mpeg");
}
