#include"basis.h"

#ifdef XWIN
#define SHAPETYPE char	//the bits in the char (8 bits)
#elif defined MSWIN
#define SHAPETYPE short	//2 bytes, 16 bits needed
#elif defined VTX
#define SHAPETYPE char	//the actual character
#endif

#ifdef XWIN	//X-Win only, seems to want it mirrored about Y-axis
#ifndef DOUBLE
static SHAPETYPE pacman0_bits[]=    {0x3c,0x7e,0xff,0xff,0xff,0xff,0x7e,0x3c};
static SHAPETYPE pacmanleft_bits[]= {0x3c,0x68,0xf0,0xe0,0xe0,0xf0,0x78,0x3c};
static SHAPETYPE pacmanright_bits[]= {0x3c,0x16,0x0f,0x07,0x07,0x0f,0x1e,0x3c};
static SHAPETYPE pacmanup_bits[]=   {0x00,0x00,0x81,0xc3,0xa7,0xff,0x7e,0x3c};
static SHAPETYPE pacmandown_bits[]= {0x3c,0x7e,0xff,0xa7,0xc3,0x81,0x00,0x00};

static SHAPETYPE vertwall_bits[]= {0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c};

static SHAPETYPE horiwall_bits[]= {0x00,0x00,0xff,0xff,0xff,0xff,0x00,0x00};

static SHAPETYPE blank_bits[]= {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

static SHAPETYPE cross_bits[]= {0x3c,0x3c,0xff,0xff,0xff,0xff,0x3c,0x3c};

static SHAPETYPE food_bits[]= {0x00,0x00,0x18,0x3c,0x3c,0x18,0x00,0x00};

static SHAPETYPE superfood_bits[]= {0x00,0x3c,0x7e,0x7e,0x7e,0x7e,0x3c,0x00};

static SHAPETYPE ghost_bits[]= {0x18,0x7e,0xff,0xdb,0xff,0xff,0xff,0xa5};

static SHAPETYPE corner2_bits[]= {0x3c,0x3e,0x3f,0x3f,0x3f,0x1f,0x00,0x00};

static SHAPETYPE corner3_bits[]= {0x00,0x00,0x1f,0x3f,0x3f,0x3f,0x3e,0x3c};

static SHAPETYPE corner4_bits[]= {0x00,0x00,0xf8,0xfc,0xfc,0xfc,0x7c,0x3c};

static SHAPETYPE corner1_bits[]= {0x3c,0x7c,0xfc,0xfc,0xfc,0xf8,0x00,0x00};

static SHAPETYPE specwall_bits[]= {0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00};

static SHAPETYPE bonuspoint_bits[]= {0x00,0x00,0x24,0x18,0x18,0x24,0x00,0x00};

static SHAPETYPE bonuslife_bits[]= {0x00,0x00,0x1c,0x38,0x38,0x1c,0x00,0x00};

static SHAPETYPE e180_bits[]= {0x00,0x00,0xf8,0xfc,0xfc,0xf8,0x00,0x00};

static SHAPETYPE e90_bits[]= {0x00,0x00,0x18,0x3c,0x3c,0x3c,0x3c,0x3c};

static SHAPETYPE e0_bits[]= {0x00,0x00,0x1f,0x3f,0x3f,0x1f,0x00,0x00};

static SHAPETYPE e270_bits[]= {0x3c,0x3c,0x3c,0x3c,0x3c,0x18,0x00,0x00};

static SHAPETYPE t0_bits[]= {0x00,0x00,0xff,0xff,0xff,0xff,0x7e,0x3c};

static SHAPETYPE t270_bits[]= {0x3c,0x3e,0x3f,0x3f,0x3f,0x3f,0x3e,0x3c};

static SHAPETYPE t180_bits[]= {0x3c,0x7e,0xff,0xff,0xff,0xff,0x00,0x00};

static SHAPETYPE t90_bits[]= {0x3c,0x7c,0xfc,0xfc,0xfc,0xfc,0x7c,0x3c};
#else
static SHAPETYPE pacman0_bits[]=    {0xf0, 0x0f, 0xf0, 0x0f, 0xfc, 0x3f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfc, 0x3f, 0xf0, 0x0f, 0xf0, 0x0f};
static SHAPETYPE pacmanleft_bits[]= {0xf0, 0x0f, 0xf0, 0x0f, 0xc0, 0x3c, 0xc0, 0x3c, 0x00, 0xff, 0x00, 0xff, 0x00, 0xfc, 0x00, 0xfc, 0x00, 0xfc, 0x00, 0xfc, 0x00, 0xff, 0x00, 0xff, 0xc0, 0x3f, 0xc0, 0x3f, 0xf0, 0x0f, 0xf0, 0x0f};
static SHAPETYPE pacmanright_bits[]= {0xf0, 0x0f, 0xf0, 0x0f, 0x3c, 0x03, 0x3c, 0x03, 0xff, 0x00, 0xff, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0xff, 0x00, 0xff, 0x00, 0xfc, 0x03, 0xfc, 0x03, 0xf0, 0x0f, 0xf0, 0x0f};
static SHAPETYPE pacmanup_bits[]=   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x03, 0xc0, 0x0f, 0xf0, 0x0f, 0xf0, 0x33, 0xfc, 0x33, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfc, 0x3f, 0xf0, 0x0f, 0xf0, 0x0f};
static SHAPETYPE pacmandown_bits[]= {0xf0, 0x0f, 0xf0, 0x0f, 0xfc, 0x3f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x33, 0xfc, 0x33, 0xfc, 0x0f, 0xf0, 0x0f, 0xf0, 0x03, 0xc0, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static SHAPETYPE vertwall_bits[]= {0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f};

static SHAPETYPE horiwall_bits[]= {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static SHAPETYPE blank_bits[]= {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static SHAPETYPE cross_bits[]= {0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f};

static SHAPETYPE food_bits[]= {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x03, 0xc0, 0x03, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xc0, 0x03, 0xc0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static SHAPETYPE superfood_bits[]= {0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0xf0, 0x0f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xf0, 0x0f, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00};

static SHAPETYPE ghost_bits[]= {0xc0, 0x03, 0xc0, 0x03, 0xfc, 0x3f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xf3, 0xcf, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x33, 0xcc, 0x33, 0xcc};

static SHAPETYPE corner2_bits[]= {0xf0, 0x0f, 0xf0, 0x0f, 0xfc, 0x0f, 0xfc, 0x0f, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x03, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static SHAPETYPE corner3_bits[]= {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x03, 0xff, 0x03, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x0f, 0xfc, 0x0f, 0xfc, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f};

static SHAPETYPE corner4_bits[]= {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xc0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0x3f, 0xf0, 0x3f, 0xf0, 0x0f, 0xf0, 0x0f};

static SHAPETYPE corner1_bits[]= {0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x3f, 0xf0, 0x3f, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xc0, 0xff, 0xc0, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static SHAPETYPE specwall_bits[]= {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static SHAPETYPE bonuspoint_bits[]= {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0c, 0x30, 0x0c, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0x30, 0x0c, 0x30, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static SHAPETYPE bonuslife_bits[]= {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x03, 0xf0, 0x03, 0xc0, 0x0f, 0xc0, 0x0f, 0xc0, 0x0f, 0xc0, 0x0f, 0xf0, 0x03, 0xf0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static SHAPETYPE e180_bits[]= {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xc0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xc0, 0xff, 0xc0, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static SHAPETYPE e90_bits[]= {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x03, 0xc0, 0x03, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f};

static SHAPETYPE e0_bits[]= {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x03, 0xff, 0x03, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x03, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static SHAPETYPE e270_bits[]= {0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xc0, 0x03, 0xc0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static SHAPETYPE t0_bits[]= {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfc, 0x3f, 0xf0, 0x0f, 0xf0, 0x0f};

static SHAPETYPE t270_bits[]= {0xf0, 0x0f, 0xf0, 0x0f, 0xfc, 0x0f, 0xfc, 0x0f, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x0f, 0xfc, 0x0f, 0xfc, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f};

static SHAPETYPE t180_bits[]= {0xf0, 0x0f, 0xf0, 0x0f, 0xfc, 0x3f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static SHAPETYPE t90_bits[]= {0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x3f, 0xf0, 0x3f, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0x3f, 0xf0, 0x3f, 0xf0, 0x0f, 0xf0, 0x0f};

#endif


#elif defined MSWIN			//MS-Win only

static SHAPETYPE pacman0_bits[]=    {0x3c,0x7e,0xff,0xff,0xff,0xff,0x7e,0x3c};
static SHAPETYPE pacmanright_bits[]= {0x3c,0x68,0xf0,0xe0,0xe0,0xf0,0x78,0x3c};
static SHAPETYPE pacmanleft_bits[]= {0x3c,0x16,0x0f,0x07,0x07,0x0f,0x1e,0x3c};
static SHAPETYPE pacmanup_bits[]=   {0x00,0x00,0x81,0xc3,0xa7,0xff,0x7e,0x3c};
static SHAPETYPE pacmandown_bits[]= {0x3c,0x7e,0xff,0xa7,0xc3,0x81,0x00,0x00};

static SHAPETYPE vertwall_bits[]= {0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c};

static SHAPETYPE horiwall_bits[]= {0x00,0x00,0xff,0xff,0xff,0xff,0x00,0x00};

static SHAPETYPE blank_bits[]= {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

static SHAPETYPE cross_bits[]= {0x3c,0x3c,0xff,0xff,0xff,0xff,0x3c,0x3c};

static SHAPETYPE food_bits[]= {0x00,0x00,0x18,0x3c,0x3c,0x18,0x00,0x00};

static SHAPETYPE superfood_bits[]= {0x00,0x3c,0x7e,0x7e,0x7e,0x7e,0x3c,0x00};

static SHAPETYPE ghost_bits[]= {0x18,0x7e,0xff,0xdb,0xff,0xff,0xff,0xa5};

static SHAPETYPE corner1_bits[]= {0x3c,0x3e,0x3f,0x3f,0x3f,0x1f,0x00,0x00};

static SHAPETYPE corner4_bits[]= {0x00,0x00,0x1f,0x3f,0x3f,0x3f,0x3e,0x3c};

static SHAPETYPE corner3_bits[]= {0x00,0x00,0xf8,0xfc,0xfc,0xfc,0x7c,0x3c};

static SHAPETYPE corner2_bits[]= {0x3c,0x7c,0xfc,0xfc,0xfc,0xf8,0x00,0x00};

static SHAPETYPE specwall_bits[]= {0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00};

static SHAPETYPE bonuspoint_bits[]= {0x00,0x00,0x24,0x18,0x18,0x24,0x00,0x00};

static SHAPETYPE bonuslife_bits[]= {0x00,0x00,0x1c,0x38,0x38,0x1c,0x00,0x00};

static SHAPETYPE e0_bits[]= {0x00,0x00,0xf8,0xfc,0xfc,0xf8,0x00,0x00};

static SHAPETYPE e90_bits[]= {0x00,0x00,0x18,0x3c,0x3c,0x3c,0x3c,0x3c};

static SHAPETYPE e180_bits[]= {0x00,0x00,0x1f,0x3f,0x3f,0x1f,0x00,0x00};

static SHAPETYPE e270_bits[]= {0x3c,0x3c,0x3c,0x3c,0x3c,0x18,0x00,0x00};

static SHAPETYPE t0_bits[]= {0x00,0x00,0xff,0xff,0xff,0xff,0x7e,0x3c};

static SHAPETYPE t90_bits[]= {0x3c,0x3e,0x3f,0x3f,0x3f,0x3f,0x3e,0x3c};

static SHAPETYPE t180_bits[]= {0x3c,0x7e,0xff,0xff,0xff,0xff,0x00,0x00};

static SHAPETYPE t270_bits[]= {0x3c,0x7c,0xfc,0xfc,0xfc,0xfc,0x7c,0x3c};

#elif defined VTX			//vt??? unix only
static SHAPETYPE pacman0_bits[]= {'P'};
static SHAPETYPE pacmanleft_bits[]= {'P'};
static SHAPETYPE pacmanright_bits[]= {'P'};
static SHAPETYPE pacmanup_bits[]=   {'P'};
static SHAPETYPE pacmandown_bits[]= {'P'};

static SHAPETYPE vertwall_bits[]= {'|'};

static SHAPETYPE horiwall_bits[]= {'-'};

static SHAPETYPE blank_bits[]= {' '};

static SHAPETYPE cross_bits[]= {'+'};

static SHAPETYPE food_bits[]= {'.'};

static SHAPETYPE superfood_bits[]= {'o'};

static SHAPETYPE ghost_bits[]= {'G'};

static SHAPETYPE corner2_bits[]= {'X'};

static SHAPETYPE corner3_bits[]= {'X'};

static SHAPETYPE corner4_bits[]= {'X'};

static SHAPETYPE corner1_bits[]= {'X'};

static SHAPETYPE specwall_bits[]= {'_'};

static SHAPETYPE bonuspoint_bits[]= {'?'};

static SHAPETYPE bonuslife_bits[]= {'p'};

static SHAPETYPE e180_bits[]= {'-'};

static SHAPETYPE e90_bits[]= {'|'};

static SHAPETYPE e0_bits[]= {'-'};

static SHAPETYPE e270_bits[]= {'|'};

static SHAPETYPE t0_bits[]= {'-'};

static SHAPETYPE t270_bits[]= {'|'};

static SHAPETYPE t180_bits[]= {'-'};

static SHAPETYPE t90_bits[]= {'|'};
#endif





