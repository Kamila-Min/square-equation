/*solve_square.с - definition of functions for the project Square equation */

#include "solve_square_header.h"

int square_equation (double a, double b, double c)
{
  printf ("a = %lg, b = %lg, c = %lg\n", a, b, c);
  double x1 = 0, x2 = 0; // a * x^2 + b
  int n_Roots = solve_square (a, b, c, &x1, &x2); // variable n_Roots showing the number of roots and appropriation it meaning from function solve_square

  FILE* fp;

  fp = fopen ("equation_results.txt", "w+");

  switch (n_Roots) // pass through all possible values of variable n_Roots with last solving of square
  {
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

return 0;
}

int solve_square (double a, double b, double c, double* x1, double* x2) // function solving the square and finding a number of roots
   {
    check_variables (x1, x2);

    check_coefficients (a, b, c);

    if (comparison_with_null (a) == 1) // cases of reduction to linear equation

      linear_equation (b, c, x1);

    else // cases of finding discriminant

       solve_with_discriminant (a, b, c, x1, x2);
   }

int linear_equation (double b, double c, double* x1)
  {
    if (comparison_with_null (b) == 1)
      {
        if (comparison_with_null (c) == 1) // case with the endless amount of roots
        return -1;

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

int comparison_with_null (double x)
  {
    return abs(x) < cmp_precision;
  }
