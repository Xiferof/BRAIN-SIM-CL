/*
 *
 * Copyright (c) 2012, Neurasmus B.V., The Netherlands,
 * web: www.neurasmus.com email: info@neurasmus.com
 *
 * Any use reproduction in whole or in parts is prohibited
 * without the written consent of the copyright owner.
 *
 * All Rights Reserved.
 *
 *
 * Author: Sebastian Isaza
 * Created: 10-04-2012
 * Modified: 06-06-2012
 *
 * Description : Top header file of the Inferior Olive model. It contains the
 * constant model conductances, the data structures that hold the cell state and
 * the function prototypes.
 *
 */


#ifndef MAIN_H_
#define MAIN_H_
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include "variables.h" 

#ifdef __APPLE__
#include <OpenCL/cl.h>
#else
#include <CL/cl.h>
#endif


#ifdef DEBUG
# define DEBUG_PRINT(x) printf x
#else
# define DEBUG_PRINT(x) do {} while (0)
#endif


/*** TYPEDEFS AND STRUCTS***/

typedef cl_double cl_mod_prec;


struct dend{
    double V_dend;
    double Hcurrent_q;
    double Calcium_r;
    double Potassium_s;
    double I_CaH;
    double Ca2Plus;
};

struct soma{
    double g_CaL;
    double V_soma;
    double Sodium_m;
    double Sodium_h;
    double Calcium_k;
    double Calcium_l;
    double Potassium_n;
    double Potassium_p;
    double Potassium_x_s;
};

struct axon{
    double V_axon;
    double Sodium_m_a;
    double Sodium_h_a;
    double Potassium_x_a;
};

typedef struct cellState{
    struct dend dend;
    struct soma soma;
    struct axon axon;
}cellState;

typedef struct cellCompParams{
    double iAppIn;
    double neighVdend[15];
    cellState *prevCellState;
    cellState *newCellState;
}cellCompParams;

typedef struct channelParams{
    double *v;
    double *prevComp1, *prevComp2;
    double *newComp1, *newComp2;
}channelParams;

typedef struct dendCurrVoltPrms{
    double *iApp;
    double iC;
    double *vDend;
    double *vSoma;
    double *q, *r, *s;
    double *newVDend;
    double *newI_CaH;
}dendCurrVoltPrms;

typedef struct somaCurrVoltPrms{
    double *g_CaL;
    double *vSoma;
    double *vDend;
    double *vAxon;
    double *k, *l, *m, *h, *n, *x_s;
    double *newVSoma;
}somaCurrVoltPrms;

typedef struct axonCurrVoltPrms{
    double *vSoma;
    double *vAxon;
    double *m_a, *h_a, *x_a;
    double *newVAxon;
}axonCurrVoltPrms;

//typedef cl_float cl_mod_prec


#endif /* MAIN_H_ */
