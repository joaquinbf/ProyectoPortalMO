#ifndef __BUTTON_H__
#define __BUTTON_H__

class Button: public Body {
public:
    Button(uint32_t body_id, b2World *b2world, float x, float y);    
};

#endif
