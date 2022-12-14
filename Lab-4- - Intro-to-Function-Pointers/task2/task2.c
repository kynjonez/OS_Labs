#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENT ME: Declare your functions here */
int add (int a, int b); // addition
int sub (int a, int b); // subtraction
int mult (int a, int b); // multiplication
int div (int a, int b); // division


int main (void)
{
	/* IMPLEMENT ME: Insert your algorithm here */
  int inp, x;
  int (my_calculator[])(int, int) = {add, subtraction, multiplication, division};

  printf("Operand 'a' : 6 | Operand 'b' : 3\n");
  printf("Specify the operation to perform (0 : add | 1: subtract | 2: multiply | 3: divide | 4: exit)\n");

  scanf("%d", &inp);
  x = (*my_calculator[inp])(6,3);
  printf("x = %d\n", x);

}

/* IMPLEMENT ME: Define your functions here */
int add (int a, int b) { printf ("Adding 'a' and 'b'\n"); return a + b; }
int sub (int a, int b) { printf ("Subtracting 'a' and 'b'\n"); return a - b; }
int mult (int a, int b) { printf ("Multiplying 'a' and 'b'\n"); return a * b; }
int div (int a, int b) { printf ("Dividing 'a' and 'b'\n"); return a / b; }