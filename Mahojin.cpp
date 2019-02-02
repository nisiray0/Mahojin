//
// 魔方陣
//
#include "Appli.h"

main() {
    Appli * appli;

    appli=new Appli;
    appli->init(3);
    appli->go();
    delete appli;
    return 1;
}
