/* atoi,atof,atol example */
#include <stdio.h>
#include <stdlib.h>
int main ()
{
  int a;float b;long c;
  a=atoi("32");
  b=atof("3.1415");
  c=atol("567283");
  printf ("%d,%f,%d\n",a,b,c); 
  return 0;
}
