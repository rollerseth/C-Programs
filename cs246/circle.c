// Author: Seth Roller

# include <stdio.h>
#include <math.h>

int main(int agrc, char *argv[]) {

  double rad;

  printf("Enter the radius of a circle: ");
  scanf("%lf", &rad);

  double circum;
  double area;
  
  area = M_PI * rad * rad;
  circum = 2 * M_PI * rad;
  
  printf("The circumference is: %lf\n", circum); 
  printf("The area is: %lf\n", area); 
  

}
