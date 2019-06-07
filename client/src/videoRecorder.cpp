#include "../include/videoRecorder.h"

VideoRecorder::VideoRecorder():
recording(false), bufferWidth(0), bufferHeight(0){
	av_register_all();
	av_log_set_level(AV_LOG_QUIET);
}

VideoRecorder::~VideoRecorder(){}

void VideoRecorder::startRecording(uint32_t width, uint32_t height){
	if(!this->recording){
		this->bufferWidth = width;
		this->bufferHeight = height;
		this->recording = true;
		this->ctx = sws_getContext(this->bufferWidth, this->bufferHeight,
	        AV_PIX_FMT_RGB24, this->bufferWidth, this->bufferHeight,
	        AV_PIX_FMT_YUV420P, 0, 0, 0, 0);
		this->dataBuffer.resize(this->bufferWidth*this->bufferHeight*3);
		this->videoOutput = new OutputFormat(this->context, this->generateName(), width, height);
	}
}

void VideoRecorder::stopRecording(){
	if(this->recording){
		this->recording = false;
		this->videoOutput->close();
    	sws_freeContext(ctx);	
       	delete this->videoOutput; 	
       	this->bufferWidth = 0;
		this->bufferHeight = 0;
	}
}

void VideoRecorder::recordFrame(SDL_Renderer* renderer){
    if(this->recording){
    	int res = SDL_RenderReadPixels(renderer, NULL, 
    	SDL_PIXELFORMAT_RGB24, this->dataBuffer.data(), this->bufferWidth*3);
    	if (res) {
	        throw std::runtime_error("No se pudo guardar frame\n"+
	        	std::string(SDL_GetError()));
    	}
    	this->videoOutput->writeFrame(this->dataBuffer.data(), this->ctx);	
    }
}

void VideoRecorder::checkResolution(uint32_t width, uint32_t height){
	if(this->recording){
		if(this->bufferWidth != width || this->bufferHeight != height){
			this->stopRecording();
			this->startRecording(width,height);
		}
	}
}

std::string VideoRecorder::generateName(){
	auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::stringstream ss;
    ss <<  std::put_time(&tm, "../movies/%d-%m-%Y-%H-%M-%S.mpeg");
    return ss.str();
}

bool VideoRecorder::isRecording() const{
	return this->recording;
}