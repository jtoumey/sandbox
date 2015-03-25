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

void root_basic(double, double, double, double *r1, double *r2);

int main(void)
{
   //
   double a = 3.0, b = 1.0e9, c = 5.0;
   double root1, root2;
   //
   printf("\nCalculate the roots of: 3 * x^2 + 10^9 * x + 5 = 0\n\n");
   //
   root_basic(a, b, c, &root1, &root2);
   
   printf("=== Basic Calculation ===\n");
   printf("\tRoot 1 (r1): %f\n",root1);
   printf("\tRoot 1 (r1): %f\n",root2);
   
   return(0);
}


/******************************************************************************
* Function:    root_basic
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
void root_basic(double a,double b, double c, double *r1, double *r2)
{
   //
   double d  = b*b - 4.0*a*c;
   *r1 = (-b - sqrt(d))/(2.0*a);
   *r2 = (-b + sqrt(d))/(2.0*a);
   
   //
}
