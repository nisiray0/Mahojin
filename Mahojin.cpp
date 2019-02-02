//
// 魔方陣 main program
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
