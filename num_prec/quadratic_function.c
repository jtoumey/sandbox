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

int main(void)
{
   //
   printf("Calculate the roots of: 3 * x^2 + 10^9 * x + 5 = 0\n");
   
   
   
   return(0);
}