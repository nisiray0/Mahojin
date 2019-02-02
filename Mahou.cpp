//
//
#include <stdio.h>
#include "Hline.h"
#include "Mahou.h"

Mahou::Mahou() : mem_size(0) {
}

Mahou::~Mahou() {
}

int Mahou::go() {
    int ret;

    ret=mem_hline[0]->gonext();
    return ret;
}

int Mahou::init(int pnum) {
    mem_size=pnum;
    mem_max=mem_size*mem_size;
    mem_hline.resize(mem_size);
    mem_vline.resize(mem_size);
    mem_boxes.resize(mem_max);
    return 1;
}

int Mahou::judge() {
    int ret=1;

    for(int i=0;i<mem_size;i++)
        if(mem_vline[i]->isjustice() == 0 || mem_hline[i]->isjustice() == 0) {
            ret=0;
            break;
        }
    return ret;
}

int Mahou::standby() {
    for(int i=0;i<mem_size;i++)
        mem_hline[i]->standby();
    return 1;
}

