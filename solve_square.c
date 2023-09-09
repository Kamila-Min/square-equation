/*solve_square.с - definition of functions for the project Square equation */

// TODO: you should name headers accordingly to the file name, so if you have
//       solve_square.c, corresponding header should be named solve_square.h,
//       it's a conventions and makes it easy to find corresponding headers.

#include "solve_square_header.h"

int square_equation(double a, double b, double c)
{
  printf ("a = %lg, b = %lg, c = %lg\n", a, b, c);
  double x1 = 0, x2 = 0; // a * x^2 + b
  int n_Roots = solve_square (a, b, c, &x1, &x2); // variable n_Roots showing the number of roots and appropriation it meaning from function solve_square

  FILE* fp;

  fp = fopen ("equation_results.txt", "w+");

  switch (n_Roots) // pass through all possible values of variable n_Roots with last solving of square
  { // TODO: Wouldn't it be much easier to select message in switch and then just 
    //       write it to the file after it, would remove tons of repetition ;)
   case -1: 
   {
    char *message = "The endless amount of roots";
    fputs (message, fp);
    fclose (fp);
   } break;

   case 0: 
   {
    char *message = "No roots";
    fputs (message, fp);
    fclose (fp);
   } break;

   case 1: 
   {
    int number = 354;
    char str [10];
    snprintf(str, sizeof str, "%lg", x1);
    char *message = str;
    fputs (message, fp);
    fclose (fp);
   } break;

   case 2: 
   {
    char str [10];
    snprintf(str, sizeof str, "%lg %lg", x1, x2);
    char *message = str;
    fputs (message, fp);
    fclose (fp);
   } break;
   
   default: 
   {
    char *message = "ERROR, the amount of roots > 2";
    fputs (message, fp);
    fclose (fp);
   } return 1;
  }

return 0; // TODO: that is misaligned, I saw it o_o
}

int solve_square (double a, double b, double c, double* x1, double* x2) // function solving the square and finding a number of roots
   {
// ^ TODO: choose one coding style, because in function before you align
//         this bracket at the beginning of the line and here it's not o_o
    check_variables (x1, x2);

    check_coefficients (a, b, c);

    if (comparison_with_null (a) == 1) // cases of reduction to linear equation

      linear_equation (b, c, x1);

    else // cases of finding discriminant

       solve_with_discriminant (a, b, c, x1, x2);
       // TODO: naming seems inconsistent:
       //       1. in one branch you wrote "solve_with_discriminant", which
       //          says about the method but not about what it solves.

       //       2. in one branch you wrote "linear_equation", which
       //          says about what it solves, but not about the method and
       //          is silent event about the action, but I've already wrote
       //          about that.
   }

int linear_equation (double b, double c, double* x1)
  {
    if (comparison_with_null (b) == 1)
      {
        if (comparison_with_null (c) == 1) // case with the endless amount of roots
        return -1; // TODO: indent it properly!

        else // case without any roots
        return 0;
      }

    else
      {
        *x1 = -c/b; // case with the one root
        return 1;
      }
  }

int check_coefficients (double a, double b, double c)
  {
    assert (isfinite (a)); // checking coefficients a, b, c
    assert (isfinite (b));
    assert (isfinite (c));
  }

int check_variables (double* x1, double* x2)
  {
    assert (x1 != x2 != NULL);
  }

int solve_with_discriminant (double a, double b, double c, double* x1, double* x2) // cases of reduction to finding discriminant
    {
       double D = b*b - 4*a*c;

       if (D < 0) // case without any roots
        return 0;

       if (comparison_with_null (D) == 1) // case with the one root
       {
        *x1 = -b/(2*a);

        return 1;
       }

       if (D > 0) // case with two roots
       {
         double sqrt_D = sqrt (D);

         *x1 = (-b + sqrt_D)/2*a;
         *x2 = (-b - sqrt_D)/2*a;

         return 2;
        }
    }

// TODO: there is a bool type, even in C if you #include <stdbool.h>
//       and in C++ it's available for sure. So strongly consider using it!
int comparison_with_null (double x)
  {
    return abs(x) < cmp_precision;
  }

// TODO: you should use .cpp extension instead of .c, cpp compiler is stricter
//       and doesn't have a lot of C weirdness that can develop bad habbits,
//       so it's a lot better for learning!
