#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct Definitions
struct student
{
   char  name[50];
   int   age;
   int   year;
   float gpa;
};

// Function definitions
void student_print(struct student);


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
   // sptr points to this struct
   sptr = malloc(sizeof(struct student));
   
   // initialize
   sptr->age  = 19;
   sptr->year = 2015;
   sptr->gpa  = 3.2;
   strcpy(sptr->name, "offset");

   (*sptr).age = 20; // same age acess as 'sptr->age'


   // print whole struct
   student_print(s);
}


void student_print(struct student st)
{
   printf("Name: %s\n ",st.name);
   printf("\tAge : %d\n ",st.age);
   printf("\tYear: %d\n ",st.year);
   printf("\tGPA : %f\n ",st.gpa);
}
