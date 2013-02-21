#ifndef __walls_h_
#define __walls_h_
#include "staticel.h"
#include "gstatele.h"

class Walls : public StaticElement
{
public:
    Walls();
    typ is_a(void) {
        return classWall;
    }
};

class G_Walls : public StaticGraphElement
{
};

class StraightWall : public G_Walls
{
public:
    void draw(void);
};


class T_Wall : public G_Walls
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


class T0 : public T_Wall
{
public:
    T0();
};

class T180 : public T_Wall
{
public:
    T180();
};

class T270 : public T_Wall
{
public:
    T270();
};

class T90 : public T_Wall
{
public:
    T90();
};


class EndWall : public G_Walls
{
public:
    void draw(void);
};

class E0 : public EndWall
{
public:
    E0();
};

class E90 : public EndWall
{

public:

    E90();

};

class E180 : public EndWall
{
public:
    E180();
};

class E270 : public EndWall
{
public:
    E270();
};

class Cross : public G_Walls
{
public:
    Cross();
};

class Corner : public G_Walls
{
};

class Corner1 : public Corner
{
public:
    Corner1();
};
class Corner2 : public Corner
{
public:
    Corner2();
};

class Corner3 : public Corner
{
public:
    Corner3();
};

class Corner4 : public Corner
{
public:
    Corner4();
};

#endif
