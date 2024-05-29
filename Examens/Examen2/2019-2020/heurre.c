#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int hh;
    int mm;
    int ss;
} Heure;
int h_to_s(Heure h){
    return (h.hh * 3600 + h.mm * 60 + h.ss)
}
Heure sec_to_heur(int sec)
{
    Heure H;
    H.hh = sec / 3600;
    sec %= 3660;
    H.mm = sec / 60;
    sec %= 60;
    H.ss = sec;
    return h ;
}