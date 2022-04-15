#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct _Point{
   int x;
   int y;
} Point;

Point *fill(Point *points, int *n){
   int i, x = 0, y = 0;

   printf("Digite a quantidade de pontos: ");
   scanf("%i", n);

   points = (Point *) malloc(*n * sizeof(Point));

   srand(time(NULL));
   for (i = 0; i < *n; i++){
      x = rand() % 101;
      y = rand() % 101;
      points[i].x = x;
      points[i].y = y;
   }

   return points;
}

void showPoints(Point *points, int n){
   int i;

   for(i = 0; i < n; i++){
      printf("\nPoint %i: x-> %i, y-> %i", i+1, points[i].x, points[i].y);
   }
}

void showAngles(double *angles, int n){
   int i;
   for(i = 0; i < n; i++){
      printf("\nAngle %i: %.2f", i+1, angles[i]);
   }
}

void calcAngle(Point *points, double *angles, int n){
   int i; 
   double angle;
   for(i = 0; i < n; i++){
      angle = atan2(points[i].y, points[i].x) * (180/M_PI); 
      angles[i] = angle < 0 ? angle + 360 : angle;
   }
}

void calcCentroid(Point *points, Point *centroid, int n){
   int i, sumX = 0, sumY = 0;

   for(i = 0; i < n; i++){
      sumX += points[i].x;
      sumY += points[i].y;
   }

   centroid->x = sumX / n;
   centroid->y = sumY / n;
}

void translate(Point *points, Point centroid, int n){
   int i;
   
   for(i = 0; i < n; i++){
      points[i].x -= centroid.x;
      points[i].y -= centroid.y;
   }
}

void dChange(double *val1, double *val2){
   double aux;
   aux = *val1;
   *val1 = *val2;
   *val2 = aux;
}

void pChange(Point *val1, Point *val2){
   Point aux;
   aux = *val1;
   *val1 = *val2;
   *val2 = aux;
}

int qsPartition(Point *points, double *angles, int start, int end){
   int pivot = angles[end], j = start, i = 0, aux = 0;

   for(i = start; i < end; i++){
      if(angles[i] <= pivot){
         dChange(&angles[i], &angles[j]);
         pChange(&points[i], &points[j]);
         j++;
      }
   }

   dChange(&angles[end], &angles[j]);
   pChange(&points[end], &points[j]);

   return j;
}

void sort(Point *points, double *angles, int start, int end){
   int p = 0; 
   if(start < end) {
      p = qsPartition(points, angles, start, end);
      sort(points, angles, start, p-1);
      sort(points, angles, p+1, end);
   }
}

float calcArea(Point *points, int n){
   int i;
   float area = 0;
   for(i = 0; i < n-1; i++){
      area += ((points[i].x - points[i+1].x) * (points[i].y + points[i+1].y))/2;
   }
   area += ((points[n-1].x - points[0].x) * (points[n-1].y + points[0].y))/2;
   return area;
}

void main(){
   int n = 0;
   double *angles;
   float area;
   Point *points, centroid;

   points = fill(points, &n);
   printf("\n=-=-= Before translate =-=-=\n");
   showPoints(points, n);
   calcCentroid(points, &centroid, n);
   printf("\n\nCentroid: x-> %i, y-> %i\n", centroid.x, centroid.y);
   translate(points, centroid, n);
   angles = (double *) malloc(n * sizeof(double));
   calcAngle(points, angles, n);
   sort(points, angles, 0, n-1);
   printf("\n=-=-= After translate =-=-=\n");
   showPoints(points, n);
   printf("\n\n=-=-= Angles =-=-=\n");
   showAngles(angles, n);
   area = calcArea(points, n);
   printf("\n\n=-=-= Area =-=-=\n\n%.2f", area);
}