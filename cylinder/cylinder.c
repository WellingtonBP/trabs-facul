#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cylinder.h"

struct _cylinder {
    float radius;
    float height;
};

Cylinder * new_cylinder(float radius, float height){
    Cylinder *cylinder;
    cylinder = (Cylinder *) malloc(sizeof(Cylinder));
    cylinder->height = height;
    cylinder->radius = radius;

    return cylinder;
}

float get_height(Cylinder *cylinder){
   return  cylinder->height;
}

float get_radius(Cylinder *cylinder){
    return cylinder->radius;
}

float calc_volume(Cylinder *cylinder){
    return pow(cylinder->radius, 2) * M_PI * cylinder->height;
}

float calc_area(Cylinder *cylinder){
   return (2 * pow(cylinder->radius, 2) * M_PI) + (2 * M_PI * cylinder->radius * cylinder->height); 
}
