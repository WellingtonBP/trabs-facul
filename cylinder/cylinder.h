typedef struct _cylinder Cylinder;

Cylinder * new_cylinder(float radius, float height);
float get_height(Cylinder *cylinder);
float get_radius(Cylinder *cylinder);
float calc_volume(Cylinder *cylinder);
float calc_area(Cylinder *cylinder);