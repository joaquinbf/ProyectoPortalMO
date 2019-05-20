#include <iostream>

#include "../include/serverManager.h"

int main() {    
	ServerManager sm("localhost","4545");
	sm.recvInt();

    return 0;
}
