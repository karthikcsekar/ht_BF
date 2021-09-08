#include <iostream>
#include <math.h>

// Function used in the HT-MT model are defined here

// ITERATION FUNCTIONS
/*  Successive-over-relaxation (SOR) method is used for iteration to next converged solution 
    omega = 0.75 (under-relaxed) 
*/
// SORMETHOD_DD - For 2 Dirichlet boundary conditions  
double * sormethod_DD(double A[ncells][ncells], double X[ncells], double b[ncells], double X_bot, double X_top){
    double tol          = 10E-7;
    double err          = 1000.0;
    double omega        = 0.75;
    double sigma        = 0.0;
    double temp[ncells];
    while (err > tol){
        // Copying current state of X for error calculation
        for(int k=0; k<ncells; k++){
            temp[k] = X[k];
        }
        for(int i=0; i<ncells; i++){
            sigma = 0.0;
            for(int j=0; j<ncells; j++){
                if (j!=i){
                    sigma = sigma + A[i][j]*X[j];
                }
            }
            X[i] = (1 - omega)*X[i] + omega*(b[i] - sigma)/A[i][i];
        }
        X[0]        = 2*X_bot - X[1];
        X[ncells-1] = 2*X_top - X[ncells-2];

        // Error calculation
        err         = temp[0] - X[0];
        for( int i=0; i<ncells; i++){
            if ((temp[i]-X[i])>err){
                err = temp[i]-X[i];
            } 
        }
    }
    return X;
}    
// SORMETHOD_DN - For Dirichlet BC at bottom and Neumann BC at top
double * sormethod_DN(double A[ncells][ncells], double X[ncells], double b[ncells], double X_bot){
    double tol          = 10E-7;
    double err          = 1000.0;
    double omega        = 0.75;
    double sigma        = 0.0;
    double temp[ncells];
    while (err > tol){
        // Copying current state of X for error calculation
        for(int k=0; k<ncells; k++){
            temp[k] = X[k];
        }
        for(int i=0; i<ncells; i++){
            sigma = 0.0;
            for(int j=0; j<ncells; j++){
                if (j!=i){
                    sigma = sigma + A[i][j]*X[j];
                }
            }
            X[i] = (1 - omega)*X[i] + omega*(b[i] - sigma)/A[i][i];
        }
        X[0]        = 2*X_bot - X[1];
        X[ncells-1] = X[ncells-2];

        // Error calculation
        err         = temp[0] - X[0];
        for( int i=0; i<ncells; i++){
            if ((temp[i]-X[i])>err){
                err = temp[i]-X[i];
            } 
        }
    }
    return X;
}    

// DEPENDENT PHASE PROPERTIES 
/* diffusivity, thermal conductivity, mass density, specifc heats are calculated 
*/
/*  Returns diffusivity of CO-CO2 gas mixture for temperatures upto 1900
    Ref: A Txtbk of Meta Kinetics Pg:180
*/
double * diffusivity(double var_Tg[ncells]){

    static double  diffiv[ncells];
    for(int i=1; i<ncells; i++ ){
        diffiv[i] = 1.583E-3*pow((var_Tg[i]/1900.0),3/2);
    }
    return diffiv;
}

// CHEMICAL REACTION PROPERTIES 
/* Here reaction rates and heats of reactions are calculated 
*/