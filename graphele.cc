#include"graphele.h"
#include<stdio.h>
#include<stdlib.h>

void GraphElement::draw(int x,int y)  	//draw graphical element
{
    XCopyArea(display,pixmap,window,gc,0,0,UNITWIDTH,UNITHEIGHT,TEXTSPACE+UNITWIDTH*x,UNITWIDTH*y);				//copy pixmap to window
}

void GraphElement::consfn()  		//function to help with constructing
{
    UserInterface* u=UserInterface::instance();	//get UserInterface instance
    display=u->getdisplay();		//get pointer to display connection
    window=u->getwindow();			//get window
    screen=u->getscreen();			//get screen
    gc=u->getgc();				//get graphic context
    int wx,wy;				//dummies
    Window root;				//dummy
    unsigned int wwidth,wheight,wdepth,wborder,width,height,status;
    //dummies, except wdepth
    XGetGeometry(display,window,&root,&wx,&wy,&wwidth,&wheight,
                 &wborder,&wdepth);			//get X data
    depth=wdepth;				//setting depth
}

GraphElement::~GraphElement(void)  	//destructor
{
    XFreePixmap(display,pixmap);		//freeing pixmap
}

//create pixmap
void GraphElement::pix(Pixmap *p,char map[],unsigned long myforeground, unsigned long mybackground)
{
    *p=XCreatePixmapFromBitmapData(display,window,map,UNITWIDTH,UNITHEIGHT,
                                   myforeground,mybackground,depth);
}
