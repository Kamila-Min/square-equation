/*solve_square header.h - declaration of functions and constants for the program solve_square */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "math.h"

int check_coefficients (double, double, double);

int check_variables (double*, double*);

int solve_with_discriminant (double, double, double, double*, double*);

int linear_equation (double b, double c, double* x1);

int comparison_with_null (double);

int solve_square (double a, double b, double c, double* x1, double* x2);

int square_equation (double a, double b, double c);

const double cmp_precision = 0.0000001;