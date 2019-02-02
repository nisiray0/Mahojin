//
//
#include "Hline.h"
#include "Box.h"

Hline::Hline() : mem_nextline(0) {
// Hline::Hline() : mem_nexline(NULL) {
}

Hline::~Hline() {
}

int Hline::gonext() {
    int ret=1;
    int result;

    if(mem_nextline) {
        result=mem_nextline->gonext();
        if(result==0)
            ret=mem_box[0]->gonext();
    }
    else {
        ret=mem_box[0]->gonext();
    }

    return ret;
}

int Hline::standby() {
    for(int i=0;i<getsize();i++)
        mem_box[i]->standby();
    return 1;
}

