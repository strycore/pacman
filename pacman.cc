#include"pacman.h"
#include"types.h"
#include"pac.h"

Pacman::Pacman()  	//constructon
{
    b=Board::instance();	//get the instance of the board
    g=new G_Pacman;	//a new one
    supertime=0;		//supertime must be set to zero
}

Pacman::~Pacman()  	//destructor
{
    delete g;
}

void Pacman::start()
{
    x=PACX; 		//set it's initial coordinates
    y=PACY;
    st=normal;		//set status to normal
    d=still; 		//direction is still
    try_d=right;		//face right
    supertime=0;		//supertime must be set to zero
}

int Pacman::is_dead()  	//is pacman dead?
{
    return st==dead;
}

void Pacman::die(Gamedata *da)  	//let pacman die a life
{
    st=dead; 				//status is dead
    da->livesdwn();			//decrement a life
}

int Pacman::getsupertime()  	//get the remaning time pacman is super
{
    return supertime;
}

int Pacman::is_super()   	//is pacman super?
{
    return st==super;
}

void Pacman::draw(void)  	//specific draw for pacman
{
    g->draw(x,y,d,try_d);	//draw pacman direction it was going and was tried
}

GID_TYPE Pacman::getgid()
{
    return g->getgid(d,try_d);
}

void Pacman::getxy(int *xx,int *yy)
{
    *xx=x;
    *yy=y;
}

int is_wall(typ block) {
    if (block == classSpecialWall || block == classWall) {
        return 1;
    } else {
        return 0;
    }
}

int Pacman::go(direction dd,Gamedata *da)  //what direction to try to move it
{
    typ going_block, future_block, next_block;

    int i = 1;	    //this i is returned: it is whether pacman moved or not.
    int going_x, going_y;	    //possible next coordinates
    int future_x, future_y;
    direction current_direction;
    current_direction = d;
    if (st==dead) { 	//if pacman died
        d=still; 		//then actual moving direction is still
        return 0;		//and return not moved
    }
    if (st == super) {
        if (supertime) 	//if supertime is > 0
            supertime--; 	//decrement supertime
        else
            st=normal;   	//if supertime is zero then status is normal
    }
    next(&future_x, &future_y, d, x, y);
    future_block = b->what_is(future_x, future_y);
    if (dd != none) {
        try_d=d=dd; //if a direction!=none given, set the two directions
    }
    next(&going_x, &going_y, d, x, y);	//compute next coordinates
    going_block = b->what_is(going_x, going_y);	//what's at new coordinates

    if (is_wall(going_block)) {
        if (is_wall(future_block)) {
            d=still;
            return 0;
        } else {
            x = future_x;
            y = future_y;
            d = current_direction;
            next_block = future_block;
        }
    } else {
        x = going_x;
        y = going_y;
        next_block = going_block;
    }
    if (next_block == classFood) {
        b->eat(x,y);				//eat food at board coordinates
        da->foodeat(); 			//let gamedata know a food is eaten
        da->scorepluss(FOODSCORE); 		//increase the score
    } else if (next_block == classSuperFood) {
        b->eat(x,y); 				//eat superfood at board coordinates
        st=super; 				//set status to super
        supertime=SUPERTIME;			//set supertime, too
    }
    return i;	//this i is returned: it is whether pacman moved or not.
}


