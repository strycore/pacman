#ifndef __gwalls_h_
#define __gwalls_h_
#include"gstatele.h"

class G_Walls : public StaticGraphElement
{

};

class StraightWall : public G_Walls
{

public:

    void draw(void);

};


class HorizontalWall : public StraightWall
{

public:

    HorizontalWall();

};

class VerticalWall : public StraightWall
{

public:

    VerticalWall();

};


#endif
