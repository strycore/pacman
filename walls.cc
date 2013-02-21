#include "walls.h"
#include "gwalls.h"

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
