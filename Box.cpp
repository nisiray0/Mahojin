//
//
#include "Box.h"

Box::Box() :mem_num(0),mem_nummgr(0),mem_nextbox(0) {
// Box::Box() :mem_num(0),mem_nummgr(NULL),mem_nextbox(NULL) {
}

Box::~Box() {
}

int Box::gonext() {
    int ret=1;
    int result;

    if(mem_nextbox) {
        result=mem_nextbox->gonext();
        if(result==0) {
            ret=nextnum();
            if(ret)
                result=mem_nextbox->gonext();
        }
    }
    else 
        ret=nextnum();
    
    return ret;
}

int Box::nextnum() {
    int ret=1;
    int result;

    if(mem_num)
        mem_nummgr->delnum(mem_num);

    while(1) {
        mem_num++;
        if(mem_nummgr->getmax() < mem_num)  {
            mem_num=0;
            ret=0;
            break;
        }
        else {
            if(mem_nummgr->isused(mem_num)) 
                continue;
            else {
                mem_nummgr->usenum(mem_num);
                break;
             }
        }
    }

    return ret;
}

int Box::standby() {
    for(int i=1;i<=mem_nummgr->getmax();i++) {
        if(mem_nummgr->isused(i))
            continue;
        else {
            mem_num=i;
            mem_nummgr->usenum(i);
            break;
        }
    }

    return mem_num;
}

