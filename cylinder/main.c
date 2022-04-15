#include <stdio.h>
#include "cylinder.h"

int main(){
    float area, volume;
    Cylinder *cylinder;

    cylinder = new_cylinder(4, 5);

     printf("Cylinder volume: %.2f\n", calc_volume(cylinder));
     printf("Cylinder area: %.2f\n", calc_area(cylinder));


    return 0;
}
