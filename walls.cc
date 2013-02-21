#include "walls.h"

Walls::Walls()
{
}

VerticalWall::VerticalWall()
{
    consfn();
    pix(&pixmap,vertwall_bits,Colour::WALLCOLOUR,Colour::MYBACKGROUND);
};

HorizontalWall::HorizontalWall()
{
    consfn();
    pix(&pixmap,horiwall_bits,Colour::WALLCOLOUR,Colour::MYBACKGROUND);
};



E0::E0()
{
    consfn();
    pix(&pixmap,e0_bits,Colour::WALLCOLOUR,Colour::MYBACKGROUND);
}

E180::E180()
{
    consfn();
    pix(&pixmap,e180_bits,Colour::WALLCOLOUR,Colour::MYBACKGROUND);
}

E270::E270()
{

    consfn();
    pix(&pixmap,e270_bits,Colour::WALLCOLOUR,Colour::MYBACKGROUND);
}

E90::E90()
{
    consfn();
    pix(&pixmap,e90_bits,Colour::WALLCOLOUR,Colour::MYBACKGROUND);
}

T0::T0()
{
    consfn();
    pix(&pixmap,t0_bits,Colour::WALLCOLOUR,Colour::MYBACKGROUND);
}

T180::T180()
{
    consfn();
    pix(&pixmap,t180_bits,Colour::WALLCOLOUR,Colour::MYBACKGROUND);
}

T270::T270()
{
    consfn();
    pix(&pixmap,t270_bits,Colour::WALLCOLOUR,Colour::MYBACKGROUND);
}

T90::T90()
{
    consfn();
    pix(&pixmap,t90_bits,Colour::WALLCOLOUR,Colour::MYBACKGROUND);
}



Cross::Cross()
{
    consfn();
    pix(&pixmap,cross_bits,Colour::WALLCOLOUR,Colour::MYBACKGROUND);
};

Corner1::Corner1()
{
    consfn();
    pix(&pixmap,corner1_bits,Colour::WALLCOLOUR,Colour::MYBACKGROUND);
};

Corner2::Corner2()
{
    consfn();
    pix(&pixmap,corner2_bits,Colour::WALLCOLOUR,Colour::MYBACKGROUND);
};

Corner3::Corner3()
{
    consfn();
    pix(&pixmap,corner3_bits,Colour::WALLCOLOUR,Colour::MYBACKGROUND);
};

Corner4::Corner4()
{
    consfn();
    pix(&pixmap,corner4_bits,Colour::WALLCOLOUR,Colour::MYBACKGROUND);
};
