#include"timing.h"
#include<stdio.h>
#include"pac.h"

static struct timeval *tp1,*tp2;		//current and previous time
static struct tms *tmsp;			//time struct
static double tot_tid;				//time diffenence
static  clock_t cl;				//clock time
static int toTid;				//time
static struct timespec remain;

#include<unistd.h>
#include<time.h>

//write a such struct
void printtp(struct timeval tp)
{
    printf("%d s %d u\n",tp.tv_sec,tp.tv_usec);
}

//write a tms
void printtms(struct tms t)
{
    double k=.016666666;
    printf("%f usr, %f sys\n",k*t.tms_utime,k*t.tms_stime);
    printf("%f usr, %f sys : children\n",k*t.tms_cutime,k*t.tms_cstime);
}

//difference between two times
double difftime(struct timeval tp1,struct timeval tp2)
{
    long a,b;
    a=tp1.tv_sec-tp2.tv_sec;
    b=tp1.tv_usec-tp2.tv_usec;

    if (b<0)
    {
        a--;
        b+= 1000000;
    }
    return (b*0.000001)+a;
}

void timingstart()  			//initialize timing
{
    tp1=new timeval;                  	//allocate structures
    tp2=new timeval;
    tmsp=new tms;
    //initialize
    (*tp1).tv_sec=0;
    (*tp1).tv_usec=0;

    (*tp2).tv_sec=0;
    (*tp2).tv_usec=0;

    gettimeofday(tp1,NULL);             	//get the time
}

void timing(int super)          	//do timing/synchronization
{
    super++;				//divisor
    if (!super) pacexit("super zero");	//if would then be division be zero
    do
    {
        gettimeofday(tp2,NULL);		//get the time now
        tot_tid=difftime(*tp2,*tp1);		//compute difference between moments
        if (tot_tid<(0.25/super)) 		//if time interval not yet used up
            remain.tv_sec = 0;
        remain.tv_nsec = ((0.25/super) - tot_tid) * 1000000000;
        nanosleep(&remain, NULL);				//sleep
            ;					//nothing
    }
    while (tot_tid<(0.25/super));		//while time interval not used up
    cl=times(tmsp); 			//get the time
    *tp1=*tp2;     				//current time will be previous time
}


