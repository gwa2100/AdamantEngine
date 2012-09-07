#ifndef __DEFINES_H__
#define __DEFINES_H__

#define DEFPROPERTY( name, type, variable )\
protected:\
type variable ;\
public:\
	type  & name () { return variable; }\
	void Set ## name ( const type & val ) { variable = val; }

enum ECollision
{
    eCOLLISION_NONE             = 0x0,
    eCOLLISION_TOP              = 0x1,
    eCOLLISION_BOTTOM           = 0x2,
    eCOLLISION_LEFT             = 0x4,
    eCOLLISION_RIGHT            = 0x8,
    eCOLLISION_X_CENTER         = 0xC,
    eCOLLISION_Y_CENTER         = 0x3,
    eCOLLISION_LEFT_SIDE        = 0x40,
    eCOLLISION_RIGHT_SIDE       = 0x80,
    eCOLLISION_TOP_LEFT         = 0x5,  //Combination of eCOLLISION_TOP      | eCOLLISION_LEFT
    eCOLLISION_TOP_RIGHT        = 0x9,  //Combination of eCOLLISION_TOP      | eCOLLISION_RIGHT
    eCOLLISION_BOTTOM_LEFT      = 0x6,  //Combination of eCOLLISION_BOTTOM   | eCOLLISION_LEFT
    eCOLLISION_BOTTOM_RIGHT     = 0xA,  //Combination of eCOLLISION_BOTTOM   | eCOLLISION_RIGHT
    eCOLLISION_TOP_X_CENTER     = 0xD, //Combination of eCOLLISION_TOP      | eCOLLISION_X_CENTER
    eCOLLISION_BOTTOM_X_CENTER  = 0xE, //Combination of eCOLLISION_BOTTOM   | eCOLLISION_X_CENTER
    eCOLLISION_Y_CENTER_LEFT    = 0x7, //Combination of eCOLLISION_Y_CENTER | eCOLLISION_LEFT
    eCOLLISION_Y_CENTER_RIGHT   = 0xB  //Combination of eCOLLISION_Y_CENTER | eCOLLISION_RIGHT
};

#include <SDL_video.h>

class CDefault_Rect : public SDL_Rect
{
public:
    CDefault_Rect( Sint16 nX = 0, Sint16 nY = 0, Uint16 uW = 0, Uint16 uH = 0) { x = nX; y = nY; w = uW; h = uH;};
};


#endif
