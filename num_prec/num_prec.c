#include <stdio.h>
#include <math.h>

double f(double);

int main(void)
{
   // Variable declarations
   double x;
   double y;
   
   x = 10.;
   y = f(x);
   printf("Function f is: %d",y);
   return 0;
}

double f(double x)
{
   // Variable declarations
   double y;
   
   // code
   y = log(1 + exp(x));

   return(y);
}
