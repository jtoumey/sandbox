/**************************************************************************
/                                                                         /
/  Module:       quadratic_function.c                                     /
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
/                Specifically -- finding the roots of a quadratic         /
/              . This example is adapted from the John D. Cook article    /
/                'Avoiding Overflow, Underflow, and loss of precision'    /
/                [1].                                                     /
/                                                                         /
/ [1]  www.codeproject.org/Articles/25294/Avoiding-Overflow-Underflow-    /
/      and-Loss-of-Precision.                                             /
/                                                                         /
**************************************************************************/
#include <stdio.h>
#include <math.h>
#include <float.h>

double root_naive(double, double, double);

int main(void)
{
   //
   double a = 3.0, b = 1.0e9, c = 5.0;
   double r1
   //
   printf("Calculate the roots of: 3 * x^2 + 10^9 * x + 5 = 0\n");
   
   
   printf("--- Naive Calculation ---\n");
   printf("Root 1 (r1): \n");
   
   return(0);
}


/******************************************************************************
* Function:    root_naive
*
* Description: naively calculates the roots of a quadratic equation using a 
*              formula that fail due to limited floating point precision. 
*
* Parameters:  a   DOUBLE   quadratic eqn coef.
*              b   DOUBLE   quadratic eqn coef.
*              C   DOUBLE   quadratic eqn coef.
*
* Return:      r1  DOUBLE   first root
*              r2  DOUBLE   second root
******************************************************************************/
double root_naive(double a,double b, double c)
{
   //
   double d  = b*b - 4.0*a*c;
   double r1 = (-b - sqrt(d))/(2.0*a);
   double r2 = (-b + sqrt(d))/(2.0*a);
   
   //
   return(r1,r2);
}