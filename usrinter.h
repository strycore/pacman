#ifndef __usrinter_h_
#define __usrinter_h_
#include"object.h"
#include"sizes.h"
#include"direc.h"

#include"systspec.h"

#define WINSTARTX 200
#define WINSTARTY 300

//is the input from mouse or keyboard
typedef enum {Mouse,Keyboard} inp_type;

//here is the graphical id type defined
#define GID_TYPE Pixmap

class UserInterface : public Object
{
    static UserInterface* _instance;//pointer to the instance of this class

    static inp_type in;		//is the input from mouse or keyboard?

    static int x,y,			//current mouse coordinates
           last_x,last_y;		//previous mouse coordinates

    static Display *mydisplay;	//pointer to display connection
    static Window mywindow;		//the window itself
    static GC mygc;			//the graphic context
    static XEvent myevent;		//an event
    static KeySym mykey;		//a key pressed
    static XSizeHints myhint;	//hints about sizes in X
    static XWMHints mywmhint;	//hints to the X Window Manager
    static int myscreen;		//the screen
    static unsigned long myforeground,	//foreground and
           mybackground;	//background colour in window
    static Font font;			//font used
    static int check(char *,KeySym);	//checks whether certain key is pressed

protected:

    UserInterface();		//constructor

public:

    static UserInterface* instance(inp_type = Keyboard);
    //returns the pointer to the instance,
    //with keyboard as default
    ~UserInterface(void); 		//destructor

    static Display* getdisplay() 	//all those are returning corresponding values
    {
        return mydisplay;
    }
    static Window getwindow()
    {
        return mywindow;
    }
    static int getscreen()
    {
        return myscreen;
    }
    static GC getgc()
    {
        return mygc;
    }
    static XEvent getevent()
    {
        return myevent;
    }

    static direction stick(void);	//returns the inputted direction

    static void write(int,int,char*);	//write string at x,y
    static void write(int,int,long int,int);//write number long int at x,y format z

    static int getinput(void);	//return whether quit or not
    static void waitsync(void);	//returns when output complete: synchronized
    static void setinp(inp_type);	//sets the input type
};

#endif
