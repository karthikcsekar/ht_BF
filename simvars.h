#include <iostream>
using namespace std;
double temp;

// Number of cells 
#define ncells 201

// PHYSICAL & THERMODYNAMIC PROPERTIES 
// Height dimension
double      var_zz[ncells];

// Variables for gas and solid temperatures 
double var_Tg[ncells];
double var_Ts[ncells];

// Concentration of gases: CO (G1) and CO_2(G2)
double var_G1[ncells];
double var_G2[ncells]; 

// Mole fractions of gases: CO (G1) and CO_2(G2)
double mfr_G1[ncells];
double mfr_G2[ncells];

// Thermal conductivities of gas and solid mixture phases
double ktherg[ncells];
double kthers[ncells];

// Dynamic Viscosity of gas mixture
double muforg[ncells];

// Specific heat of gas and solid mixture phases
double specpg[ncells];
double specps[ncells];

// Molar density of gas and solid mixtures phases
double rhoofg[ncells];
double rhoofs[ncells];

// Heat Transfer coefficient b/w solid and gas phases
double htcoef[ncells];

// Heat of reaction for CEQ1 :: Fe2O3 + 3CO --> 2Fe + 3CO2
double delHrr[ncells];

// Rate of reaction for CEQ1 :: Fe2O3 + 3CO --> 2Fe + 3CO2
double reacrF[ncells];

// DISCRETIZATION VARIABLES
// Matrix A for gas and solid temperature equation 
double matATg[ncells][ncells];
double matATs[ncells][ncells];

// RHS matrix for gas and solid temperature equation
double rhs_Tg[ncells];
double rhs_Ts[ncells];

// Tolerance limits
double tol;
double tolS;
double tolQ;

//Error variable for 1st Loop - no source term :: for gas and solid temperature variables
double err1[ncells];
double err2[ncells];

// For 2nd Loop 
double err3[ncells];
double err4[ncells];

// For 3rd Loop
double err5[ncells];
double err6[ncells];
 
 // BOUNDARY VALUES 
// Maximum Height of the BF
double bfmaxh;

// Variables for gas and solid temperatures: Boundary values
double Tg_bot, Tg_top;
double Ts_bot, Ts_top;

void initialize(){

    // Initializing blast furnace height 
    bfmaxh                  = 25;

    // Initializing gas and solid temperature variables 
    Tg_top                  = 400.0;            // Top gas temperature 
    Tg_bot                  = 1600.0;           // Bottom gas temperature
    Ts_top                  = 400.0;            // Top solid temperature
    Ts_bot                  = 1600.0;           // Bottom solid temperature

    // Initializing 1D space variable 
    for (int i=1; i<=ncells-1; i++){
        var_zz[i] = (i-1)*bfmaxh/(ncells-2-1);
    }
    var_zz[0]               = -bfmaxh/(ncells-2);
    var_zz[ncells-1]        = var_zz[ncells-2] + bfmaxh/(ncells-2-1);

    // Initializing gas and solid temperature variables - an average value for inital guess
    for (int i=1; i<=ncells-1; i++){
        var_Tg[i] = 0.5*(Tg_top + Tg_bot);
        var_Ts[i] = 0.5*(Ts_top + Ts_bot);        
    }

    // Tolerance limits
    tol         = 1E-6;
    tolS        = 1E-6;
    tolQ        = 1E-6;
}