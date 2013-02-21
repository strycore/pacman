#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colour.h"
#include "arg.h"
#include "pac.h"

COLOURTYPE Colour::MYFOREGROUND=0; //initializers
COLOURTYPE Colour::MYBACKGROUND=0;
COLOURTYPE Colour::WALLCOLOUR=0;
COLOURTYPE Colour::PACMANCOLOUR=0;
COLOURTYPE Colour::GHOSTCOLOUR1=0;
COLOURTYPE Colour::GHOSTCOLOUR2=0;
COLOURTYPE Colour::GHOSTCOLOUR3=0;
COLOURTYPE Colour::GHOSTCOLOUR4=0;
COLOURTYPE Colour::RUNGHOSTCOLOUR=0;
COLOURTYPE Colour::FOODCOLOUR=0;
COLOURTYPE Colour::SUPERFOODCOLOUR=0;
COLOURTYPE Colour::BONUSPOINTCOLOUR=0;
COLOURTYPE Colour::BONUSLIFECOLOUR=0;

//plain colour names
static COLOURNAME black,white,cyan,lightblue,yellow,red,violetred,violet,
                  orangered,deepskyblue,gold,lightyellow,grey,lightgrey,dimgrey,
                  slategrey,darkslategrey,lightslategrey;

Colour::Colour(UserInterface* u)  	//constructor
{
    static int starts=0;			//to make sure only one construction

    Window window;				//our window
    int screen; 				//our screen

    if (starts) { 				//make sure it is initialized just once
        pacwarning("Colour is just initialized once\n");
        return;
    }
    starts=1;				//to make sure only one construction

    display=u->getdisplay();		//get pointer to display connection
    screen=u->getscreen();			//get the screen

    Visual *vis=DefaultVisual(display,screen);	//get the visual type class

    int colour=0;				//colour?

//if it is not grayish then it is colour (only maybe)
    if (Argument::argc==1 && vis->c_class!=GrayScale && vis->c_class!=StaticGray) colour=1;

//the following picks the first argument matching grey or colour
//in none given, no colour is assumed
    if (Argument::argc>1) {			//if there are arguments
        char** temp=Argument::args;		//initial pointer to strings
        char* s;				//argument string
        while(s=*temp) {			//while there is still an argument left
            if (!strcmp(s,"grey")) {	//if argument is grey then no colours
                colour=0;
                break;
            }
            if (!strcmp(s,"colour")) {	//if argument is colour then colours
                colour=1;
                break;
            }
            temp++;				//increment to next string
        }
    }

    if (colour) {				//if colour chosen
        cmap=DefaultColormap(display,DefaultScreen(display));	//get colourmap
//the colour initializing is almost straightforward, you set the RGB
//mark flags according to what attribute members were set
//then you allocate the colour, which you get with ?????.pixel
        cyan.red=0;
        cyan.green=65535;
        cyan.blue=65535;
        cyan.flags=DoRed|DoGreen|DoBlue;
        if(XAllocColor(display,cmap,&cyan)==0) pacexit("Colour initialization error");

        black.red=0;
        black.green=0;
        black.blue=0;
        black.flags=DoRed|DoGreen|DoBlue;
        if(XAllocColor(display,cmap,&black)==0) pacexit("Colour initialization error");

        white.red=65535;
        white.green=65535;
        white.blue=65535;
        white.flags=DoRed|DoGreen|DoBlue;
        if(XAllocColor(display,cmap,&white)==0) pacexit("Colour initialization error");

        lightblue.red=173*256;
        lightblue.green=216*256;
        lightblue.blue=230*256;
        lightblue.flags=DoRed|DoGreen|DoBlue;
        if(XAllocColor(display,cmap,&lightblue)==0) pacexit("Colour initialization error");

        yellow.red=65535;
        yellow.green=65535;
        yellow.blue=0;
        yellow.flags=DoRed|DoGreen|DoBlue;
        if(XAllocColor(display,cmap,&yellow)==0) pacexit("Colour initialization error");

        red.red=65535;
        red.green=0;
        red.blue=0;
        red.flags=DoRed|DoGreen|DoBlue;
        if(XAllocColor(display,cmap,&red)==0) pacexit("Colour initialization error");

        orangered.red=65535;
        orangered.green=69*256;
        orangered.blue=0;
        orangered.flags=DoRed|DoGreen|DoBlue;
        if(XAllocColor(display,cmap,&orangered)==0) pacexit("Colour initialization error");

        violetred.red=208*256;
        violetred.green=32*256;
        violetred.blue=144*256;
        violetred.flags=DoRed|DoGreen|DoBlue;
        if(XAllocColor(display,cmap,&violetred)==0) pacexit("Colour initialization error");

        violet.red=238*256;
        violet.green=130*256;
        violet.blue=238*256;
        violet.flags=DoRed|DoGreen|DoBlue;
        if(XAllocColor(display,cmap,&violet)==0) pacexit("Colour initialization error");

        deepskyblue.red=0;
        deepskyblue.green=192*256-1;
        deepskyblue.blue=65535;
        deepskyblue.flags=DoRed|DoGreen|DoBlue;
        if(XAllocColor(display,cmap,&deepskyblue)==0) pacexit("Colour initialization error");

        gold.red=65535;
        gold.green=216*256-1;
        gold.blue=0;
        gold.flags=DoRed|DoGreen|DoBlue;
        if(XAllocColor(display,cmap,&gold)==0) pacexit("Colour initialization error");

        lightyellow.red=65535;
        lightyellow.green=65535;
        lightyellow.blue=0;
        lightyellow.flags=DoRed|DoGreen|DoBlue;
        if(XAllocColor(display,cmap,&lightyellow)==0) pacexit("Colour initialization error");

        MYFOREGROUND =cyan.pixel;
        MYBACKGROUND =black.pixel;
        WALLCOLOUR =deepskyblue.pixel;
        PACMANCOLOUR =yellow.pixel;
        GHOSTCOLOUR1 =red.pixel;
        GHOSTCOLOUR2 =violetred.pixel;
        GHOSTCOLOUR3 =violet.pixel;
        GHOSTCOLOUR4 =orangered.pixel;
        RUNGHOSTCOLOUR =lightblue.pixel;
        FOODCOLOUR =lightyellow.pixel;
        SUPERFOODCOLOUR =gold.pixel;
        BONUSPOINTCOLOUR =gold.pixel;
        BONUSLIFECOLOUR =gold.pixel;
    } else {					//if no colours chosen
        cmap=DefaultColormap(display,DefaultScreen(display));

        grey.red=192*256;
        grey.green=192*256;
        grey.blue=192*256;
        grey.flags=DoRed|DoGreen|DoBlue;
        if(XAllocColor(display,cmap,&grey)==0) pacexit("Colour initialization error");

        dimgrey.red=105*256;
        dimgrey.green=105*256;
        dimgrey.blue=105*256;
        dimgrey.flags=DoRed|DoGreen|DoBlue;
        if(XAllocColor(display,cmap,&dimgrey)==0) pacexit("Colour initialization error");

        lightgrey.red=211*256;
        lightgrey.green=211*256;
        lightgrey.blue=211*256;
        lightgrey.flags=DoRed|DoGreen|DoBlue;
        if(XAllocColor(display,cmap,&lightgrey)==0) pacexit("Colour initialization error");

        lightslategrey.red=119*256;
        lightslategrey.green=136*256;
        lightslategrey.blue=153*256;
        lightslategrey.flags=DoRed|DoGreen|DoBlue;
        if(XAllocColor(display,cmap,&lightslategrey)==0) pacexit("Colour initialization error");

        slategrey.red=112*256;
        slategrey.green=128*256;
        slategrey.blue=144*256;
        slategrey.flags=DoRed|DoGreen|DoBlue;
        if(XAllocColor(display,cmap,&slategrey)==0) pacexit("Colour initialization error");

        darkslategrey.red=47*256;
        darkslategrey.green=79*256;
        darkslategrey.blue=79*256;
        darkslategrey.flags=DoRed|DoGreen|DoBlue;
        if(XAllocColor(display,cmap,&darkslategrey)==0) pacexit("Colour initialization error");

        MYFOREGROUND =WhitePixel(display,screen);
        MYBACKGROUND =BlackPixel(display,screen);
        WALLCOLOUR =darkslategrey.pixel;
        PACMANCOLOUR =WhitePixel(display,screen);
        GHOSTCOLOUR1 =slategrey.pixel;
        GHOSTCOLOUR2 =slategrey.pixel;
        GHOSTCOLOUR3 =slategrey.pixel;
        GHOSTCOLOUR4 =slategrey.pixel;
        RUNGHOSTCOLOUR =lightgrey.pixel;
        FOODCOLOUR =lightgrey.pixel;
        SUPERFOODCOLOUR =grey.pixel;
        BONUSPOINTCOLOUR =dimgrey.pixel;
        BONUSLIFECOLOUR =WhitePixel(display,screen);
    }
}

Colour::~Colour()
{
    XFreeColormap(display,cmap);	//free the colourmap
}
