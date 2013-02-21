#include"basis.h"

#ifdef XWIN
#include<X11/Xlib.h>
#include<X11/Xutil.h>
#include<X11/keysym.h>
#elif defined MSWIN
#include<windows.h>
#endif

#ifdef UNIX
#include <sys/time.h>
#include <sys/times.h>
#endif
