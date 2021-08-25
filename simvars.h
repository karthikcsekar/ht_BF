double temp;

// Number of cells 
int     ncells;

// Maximum Height of the BF
double  bfmaxh;

// Height dimension
double  var_zz;

// Variables for gas and solid temperatures
double  var_Tg, var_Ts;

// Variables for gas and solid temperatures: Boundary values
double  Tg_bot, Tg_top;
double  Ts_bot, Ts_top;

void initialize(){

    // Redefining total number of cells by adding 2 ghost cells
    ncells          = ncells + 2;

    // Initializing gas and solid temperature variables 
    Tg_top          = 400.0;            // Top gas temperature 
    Tg_bot          = 1600.0;           // Bottom gas temperature
    Ts_top          = 400.0;            // Top solid temperature
    Ts_bot          = 1600.0;           // Bottom solid temperature

    // Initializing gas and solid temperature variables 
    for (int i=0; i<ncells; i++){
        
    }
}