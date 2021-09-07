#include <iostream>
#include "simvars.h"
#include "simfuns.h"
using namespace std;
int main() {
    initialize();
    std::cout<<temp<<std::endl;
    std::cout<<"Hello"<<std::endl;

    for (int i=0;i<ncells;i++){
        std::cout<<var_zz[i]<<std::endl;
    }
}