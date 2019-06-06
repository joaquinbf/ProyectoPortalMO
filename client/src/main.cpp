#include "../include/client.h"

int main() {    
	try{
		Client client;
	    client.main();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
	return 0;
}
