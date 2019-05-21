#ifndef _RENDERABLE_OBJECT_H_
#define _RENDERABLE_OBJECT_H_

class RenderableObject{
public:
	RenderableObject(){}
	virtual ~RenderableObject(){}
	virtual void render(int resx,int resy,int width,int height){}
};


#endif
