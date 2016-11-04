#include "kernel.h"

/**
Input: cellCompParamsPtr, cellStatePtr, i
cellCompParamsPtr: Array of struct which stores values of neighbours for each cell.
cellStatePtr: Array with values for each cell.
i: current simulation step


Retreive the voltage of the dendrite (V_dend) from each neighbour
**/
__kernel void neighbor_kernel(global mod_prec *cellStatePtr,global mod_prec *cellCompParamsPtr,  uint i){



}