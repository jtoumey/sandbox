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
#include <float.h>

double f(double);
double f_check(double);
double get_input();

int main(void)
{
   // Variable declarations
   double x,y;
   double y_check;
   
   // Collect input
   x = get_input();

   // Calculate the result
   y = f(x);
   y_check = f_check(x);

   // Print results

   printf("Function f is      : %f\n",y);
   printf("Function f_check is: %f\n",y_check);
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
                            
         Negative x: returns a value so small that the computer cannot distinguish 1
                     from 1 + exp(-50). The function returns log(1+0) = 0.
                     
                     Solution: If the computer thinks 1+x is essentially 1, then we can
                     return exp(x).
   */
      
   // code
   y = log(1 + exp(x));

   return(y);
}

double f_check(double x)
{
   // Variable declarations
   double X_MIN,X_MAX;
   X_MAX = -log(DBL_EPSILON);
   X_MIN =  log(DBL_EPSILON);

   // calculation
   if(x > X_MAX) return x;
   if(x < X_MIN) return exp(x);
   return log(1.0 + exp(x));
}
