#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Define struct
struct student
{
   char  name[50];
   int   age;
   int   year;
   float gpa;
};


// Main function

int main(void)
{
   // define structs
   struct student s;
   struct student *sptr;

   // initialize 
   strcpy(s.name, "Julian");
   s.age  = 22;
   s.year = 2014; 
   s.gpa  = 3.010101;

   // malloc creates a struct on the HEAP
   sptr = malloc(sizeof(struct student));



}
