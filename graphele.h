#ifndef __graphele_h_
#define __graphele_h_

#include"systspec.h"
#include"object.h"
#include"usrinter.h"
#include"shapes.h"
#include"colour.h"
#include"types.h"

//decide the pixmap type
#define PIXMAPTYPE Pixmap

class GraphElement : public Object
{
protected:

    Display *display;			//pointer to display connection
    Window window;				//the window itself
    int screen;				    //the screen
    GC gc;					    //the graphic context
    unsigned int depth;			//the screen depth

    PIXMAPTYPE pixmap; 			//this is the pixmap

    void consfn(); 				//function to help with constructing
    void pix(PIXMAPTYPE *,SHAPETYPE [],COLOURTYPE,COLOURTYPE);	//create pixmap

public:

    virtual void draw(int,int);		    //draw graphical element
    virtual ~GraphElement(void)=0;      //destructor
};
#endif
