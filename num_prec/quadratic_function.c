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

double root_naive(double);

int main(void)
{
   //
   double a = 3.0, b = 1.0e9, c = 5.0;
    
   //
   printf("Calculate the roots of: 3 * x^2 + 10^9 * x + 5 = 0\n");
   
   
   
   return(0);
}


/******************************************************************************
* Function:    root_naive
* Description: naively calculates the roots of a quadratic equation using a 
*              formula that fail due to limited floating point precision. 
* Parameters:  , data type, and description>
*              <variable2 name, data type, and description>
* Return:      <data type and description>
******************************************************************************/
double root_naive(double a,double b, double c)
{
   
}