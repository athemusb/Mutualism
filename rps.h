#define PI 3.14159265359

#define Nx 250
#define dt 1.0e-2
#define l 10.0
#define dx l/Nx
#define tf 1.0e3
#define NF 100
#define q tf/NF

//Vegetation
#define R 1   //interaction radius
#define a 5 //seed_comp_intensity
#define D_v 0.0001   //diffusion

//Polinator
#define b 0.5 //exponential growth
#define g 1 //intra competition
#define m 12   //mutualism
#define D_p 0.001   //diffusion
