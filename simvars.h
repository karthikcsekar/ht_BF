#include <iostream>
using namespace std;
double temp;

// Number of cells 
#define ncells 201

// Maximum Height of the BF
double      bfmaxh;

// Height dimension
double      var_zz[ncells];

// Variables for gas and solid temperatures
double      var_Tg[ncells], var_Ts[ncells];

// Variables for gas and solid temperatures: Boundary values
double      Tg_bot, Tg_top;
double      Ts_bot, Ts_top;

void initialize(){

    // Initializing blast furnace height 
    bfmaxh                  = 25;

    // Initializing gas and solid temperature variables 
    Tg_top                  = 400.0;            // Top gas temperature 
    Tg_bot                  = 1600.0;           // Bottom gas temperature
    Ts_top                  = 400.0;            // Top solid temperature
    Ts_bot                  = 1600.0;           // Bottom solid temperature

    // Initializing gas and solid temperature variables 
    for (int i=1; i<=ncells-1; i++){
        var_zz[i] = (i-1)*bfmaxh/(ncells-2-1);
        var_Tg[i] = 0;
        var_Ts[i] = 0;        
    }
    var_zz[0]               = -bfmaxh/(ncells-2);
    var_zz[ncells-1]        = var_zz[ncells-2] + bfmaxh/(ncells-2-1);
}