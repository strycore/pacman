#include"usrinter.h"
#include<stdio.h>
#include"gpacman.h"
#include"colour.h"
#include<stdlib.h>
#include"arg.h"
#include"pac.h"
#include<string.h>
#include"board.h"

static GC back;

inp_type UserInterface::in=Keyboard;	//initializers
int UserInterface::x=0;
int UserInterface::y=0;
int UserInterface::last_x=0;
int UserInterface::last_y=0;

UserInterface* UserInterface::_instance=0;

//returns the pointer to the instance
UserInterface* UserInterface::instance(inp_type inp)
{
    if (_instance==0)
        _instance=new UserInterface;
    in=inp;
    return _instance;
}

inline void UserInterface::setinp(inp_type i)
{
    in=i;
}

Display* UserInterface::mydisplay=0;	//more initializers
Window UserInterface::mywindow=0;
GC UserInterface::mygc=0;
XEvent UserInterface::myevent= {0};
KeySym UserInterface::mykey=0;
XSizeHints UserInterface::myhint= {0};
XWMHints UserInterface::mywmhint= {0};
int UserInterface::myscreen=0;
unsigned long UserInterface::myforeground=0;
unsigned long UserInterface::mybackground=0;
Font UserInterface::font=0;


UserInterface::UserInterface()  	//constructor
{
    setinp(in);				//sets the input type
    mydisplay = XOpenDisplay("");		//connects to a display
    if (!mydisplay) pacexit("no display possible");	//if it was not possible, exit
    myscreen = DefaultScreen(mydisplay);	//get the default screen
    Colour(this);				//initialize the colours
    mybackground=Colour::MYBACKGROUND; 	//set background colour
    myforeground=Colour::MYFOREGROUND;	//set foreground colour
    myhint.x=WINSTARTX;
    myhint.y=WINSTARTY;	//set window's initial coordinates
    myhint.width=WINWIDTH; 			//set window's width and height
    myhint.height=WINHEIGHT;
    myhint.min_width=WINWIDTH; 			//set window's width and height
    myhint.min_height=WINHEIGHT;
    myhint.max_width=WINWIDTH; 			//set window's width and height
    myhint.max_height=WINHEIGHT;
    myhint.flags=PPosition|PSize|PMinSize|PMaxSize;//|PResizeInc|PBaseSize;		//what myhint members were set
    mywmhint.flags=InputHint;//|StateHint;		//say we want to have input
    mywmhint.input=True;			//that we set inputflag
    mywmhint.initial_state=NormalState;
    mywindow=XCreateSimpleWindow(mydisplay, DefaultRootWindow(mydisplay),
                                 myhint.x,myhint.y,myhint.width,myhint.height,5,
                                 myforeground,mybackground);
    //created the window
    XSetStandardProperties(mydisplay,mywindow,PACTITLE,PACTITLE,None,Argument::args,Argument::argc,&myhint);
    //some properties were set
    XSetWMHints(mydisplay,mywindow,&mywmhint);	//give window manager hints
    mygc=XCreateGC(mydisplay,mywindow,0,0);		//create a graphic context
    XSetBackground(mydisplay,mygc,mybackground);	//set window background
    XSetForeground(mydisplay,mygc,myforeground);	//set window foreground
    font=XLoadFont(mydisplay,FONT1);	//load the font
    if (!font) font=XLoadFont(mydisplay,FONT2);
    XSetFont(mydisplay,mygc,font);		//set the font
    XSelectInput(mydisplay,mywindow,ExposureMask);//|VisibilityChangeMask);//,ButtonPressMask|KeyPressMask|ExposureMask|VisibilityChangeMask);
    //select what we want as input
    XSetGraphicsExposures(mydisplay,mygc,False);
    XMapRaised(mydisplay,mywindow);		//raise the window, that is, show it
    do XNextEvent(mydisplay,&myevent);	//wait until window is exposed
    while (myevent.type!=Expose);

    Window root,child;
    int dumx,dumy;
    unsigned int keys_buttons;	//dummies
    XQueryPointer(mydisplay,mywindow,&root,&child,&dumx,&dumy,&x,&y,&keys_buttons);
    //get the initial mouse coordinates
    XSelectInput(mydisplay,mywindow,ExposureMask|VisibilityChangeMask);//,ButtonPressMask|KeyPressMask|ExposureMask|VisibilityChangeMask);
    //select what we want as input
}

UserInterface::~UserInterface(void)  	//destructor
{
    XUnloadFont(mydisplay,font);		//unload the font
    XFreeGC(mydisplay, mygc);		//destroy gc
    XDestroyWindow(mydisplay, mywindow);	//destroy window
    XCloseDisplay(mydisplay);		//close the display connection
}

void UserInterface::waitsync(void)
{
    XSync(mydisplay,0);	//returns when output complete: synchronized
}

int UserInterface::getinput(void)  	//get input whether quit or not,
{
    //it may also change input type
    if (QLength(mydisplay)>0) {
        XNextEvent(mydisplay, &myevent);	//get next event from the queue
//printf("%d \n",myevent.type);
        switch (myevent.type) {			//what kind of event was it?
        case Expose: {
//  Window root,child;int dumx,dumy;unsigned int keys_buttons;	//dummies
//  if (myevent.xexpose.count==0) 	//if this is first expose
//   XQueryPointer(mydisplay,mywindow,&root,&child,&dumx,&dumy,&x,&y,&keys_buttons);
//					//get the initial mouse coordinates
// XRaiseWindow(mydisplay,mywindow);	//let window stay on top
#ifdef XPOSSE
            writetext();
            Board::instance()->draw();
            waitsync();
#endif
        }
        break;
#ifdef RAISE
        case VisibilityNotify:
            if (myevent.xvisibility.state!=VisibilityUnobscured)
                XRaiseWindow(mydisplay,mywindow);	//let window stay on top
            break;
#endif
        case MappingNotify:			//something about the keyboard mapping
            XRefreshKeyboardMapping(&myevent.xmapping);
            break;
        case MapNotify:
//   XRaiseWindow(mydisplay,mywindow);	//let window stay on top
            break;
        }

    }

    if (in==Mouse) {			//if input is from mouse
        Window root,child;
        int dumx,dumy,xx,yy; //dummies
        unsigned int keys_buttons;		//what keys/buttons hit/pressed
        XQueryPointer(mydisplay,mywindow,&root,&child,&dumx,&dumy,&xx,&yy,&keys_buttons);
        if (keys_buttons & Button1Mask) 	//if left mouse button down
            in=Keyboard;				//input type is keyboard
        if ((keys_buttons & Button2Mask) || (keys_buttons & Button3Mask))
            return 1;				//if middle or right is down quit
    } else {				//else if input is from keyboard
        char key_vector[32];			//denotes 256 possible keys
        XQueryKeymap(mydisplay,key_vector);	//queries and gets data for all keys
//int kkk; for (kkk=0;kkk<32;kkk++)
//printf("%x ",key_vector[kkk]);
//printf("\n");
        if (check(key_vector,XK_m)) {	//if m is pressed input type is mouse
            in=Mouse;
            return 0;
        }
        if (check(key_vector,XK_M)) {	//if m is pressed input is keyboard
            in=Mouse;
            return 0;
        }
        if (check(key_vector,XK_Q)) return 1;	//if q is pressed quit
        if (check(key_vector,XK_q)) return 1;	//if q is pressed quit
    }
//}
    return 0;
}

//checks whether certain key is pressed
int UserInterface::check(char key_vector[32], KeySym key)
{
    unsigned int byteindex, bitindex;	//byte and bit number
    KeyCode code;				//keykode
    code=XKeysymToKeycode(mydisplay,key);	//get the code of the wanted key
    if (code==NoSymbol) pacexit("NoSymbol\n");	//if no such, exit
    byteindex=(code/8);				//what's it's index number
    bitindex=code & 7;				//what's it's bit number
    return (1 & (key_vector[byteindex]>>bitindex));	//has it been hit?
}

direction UserInterface::stick(void)
{
    if (in==Mouse) {						//mouse input
        Window root,child;
        int dumx,dumy;
        unsigned int keys_buttons;	//dummies
        last_x=x;
        last_y=y;					//present is past
        XQueryPointer(mydisplay,mywindow,&root,&child,&dumx,&dumy,&x,&y,&keys_buttons);
        //get new coordinates
        if (x==last_x && y==last_y) return none;	//if not moved then none
        int dx=x-last_x;
        int dy=y-last_y;		//get changes of coordinates
        if (dx>=dy && dx>-dy) return right;		//destine directions
        if (dx>=dy && dx<=-dy) return up;
        if (dx<dy && dx>-dy) return down;
        if (dx<dy && dx<=-dy) return left;
        pacwarning("errorstick\n");	//give warning if not all directons covered
    } else {			//if input comes from keyboard
        char key_vector[32];		//denotes 256 possible keys
        XQueryKeymap(mydisplay,key_vector);	//queries and gets data for all keys
        if (check(key_vector,XK_Up)) return up;		//if up key pressed, up
        if (check(key_vector,XK_Down)) return down;	//etc
        if (check(key_vector,XK_Left)) return left;
        if (check(key_vector,XK_Right)) return right;
        return none;					//if none of these, then none
    }
}

//write string at x,y
void UserInterface::write(int x,int y,char* str)
{
    XDrawImageString(mydisplay,mywindow, mygc,TEXTWIDTH*x,TEXTHEIGHT*y,str, strlen(str));
}

//write number long int at x,y format z
void UserInterface::write(int x,int y,long int v,int l)
{
    char*  str;
    str = (char*) malloc (l+1);
    sprintf (str, "%.*d", l,v);
    XDrawImageString(mydisplay,mywindow, mygc,TEXTWIDTH*x,TEXTHEIGHT*y,str, strlen(str));
}
