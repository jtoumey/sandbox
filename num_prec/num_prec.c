/**************************************************************************
/                                                                         /
/  Module:       num_prec.c                                               /
/                                                                         /
/  Programmer:   Julian M. Toumey                                         /
/                Madison, WI                                              /
/                                                                         /
/  Date:         March 2015                                               /
/                                                                         /
/  Language:     C                                                        /
/                                                                         /
/  Description:  This code demonstrates the failure of mathematical       /
/                operations when operating with finite precision.         /
/                Specifically -- the EXP and LOG operations. This example /
/                is adapted from the John D. Cook article 'Overflow and   /
/                loss of precision' [1].                                  /
/                                                                         / 
/ [1]  www.johndcook.com/blog/2008/04/16/overflow-and-loss-of-precision/  /
/                                                                         /
**************************************************************************/

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
   
   /* This function naively calculates the exponential of the input, adds 1, and then
   /  takes the natural log. One might expect a value slightly large than the input
   /  argument x. In some cases, this fails: 
         
         Large x:    returns INF. In this case, exp(x) is large enough (larger than 10^308)
                     that the result overflows (larger than a floating point number can be)
                     and the compiler considers log(1 + exp(INF)) = INF. 
                  
                     Solution: if x is large enough to overflow the EXP operation, then
                               just return x.
                            
         Negative x: 
   */
      
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
