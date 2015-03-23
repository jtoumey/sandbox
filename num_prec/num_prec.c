#include <stdio.h>
#include <math.h>

double f(double);
double f_over(double);
double get_input();

int main(void)
{
   // Variable declarations
   double x,y;
   double y_over;
   double y_under;
   
   // Collect input
   x = get_input();

   // Calculate the result
   y = f(x);
   y_over = f_over(x);

   // Print results

   printf("Function f is     : %f\n",y);
   printf("Function f_over is: %f\n",y_over);
   return 0;
}

/********************************
/                               /
/ Function Definitions          /
/                               /
********************************/

double get_input()
{
   // Variable declarations
   double arg;

   // Read input
   printf("Enter argument: \n");
   scanf ("%lf",&arg);

   return(arg);
}

double f(double x)
{
   // Variable declarations
   double y;
   
   // code
   y = log(1 + exp(x));

   return(y);
}

double f_over(double x)
{
   // Variable declarations
   double y,X_MAX;
   X_MAX = 1000.;

   // calculation
   if(x > X_MAX)
   {
      y = x;
   }
   else
   {
      y = log(1 + exp(x));
   }
   return(y);
}
