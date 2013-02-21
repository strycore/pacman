#include"basis.h"

#define BOARDWIDTH 33
#define BOARDHEIGHT 23


#if defined(MSWIN) || !defined(DOUBLE)
#define UNITWIDTH 8		//pixmaps is 8x8
#define UNITHEIGHT 8
#else
#define UNITWIDTH 16
#define UNITHEIGHT 16
#endif


//defines different sizes for different fonts
#ifdef XWIN
#ifndef DOUBLE
#define TEXTWIDTH 8
#define TEXTHEIGHT 8
#define FONT1 "5x8"
#define FONT2 "5x7"
#else
#define TEXTWIDTH 8
#define TEXTHEIGHT 16
#define FONT1 "8x16"
#define FONT2 "7x14"
#endif
#elif defined MSWIN
#define TEXTWIDTH 6
#define TEXTHEIGHT 10
#endif

#define TEXTCHARSINLINE 15	//text characters befors board begins

#define TEXTSPACE TEXTWIDTH*TEXTCHARSINLINE
#define WINWIDTH BOARDWIDTH*UNITWIDTH+TEXTSPACE+20
#define WINHEIGHT BOARDHEIGHT*UNITHEIGHT+40



