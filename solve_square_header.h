/*solve_square header.h - declaration of functions and constants for the program solve_square */


// TODO: Every header you write should have an include guard, it's a thing that protects
//       it from double inclusion: 
//
//       == Consider an example ==

//       1) You have two files:

//           // --- test.h ---
//           void foo();

//           // -- test.cpp --
//           #include "test.h"
//           #include "test.h"

//          When your compiler runs, it will expand code in test.cpp to: 

//           // -- test.cpp --
//           void foo();
//           void foo();

//          NOTE: You can easily check it using "-E" flag with your
//          compiler, like: clang++ -E ... or g++ -E ..., this will
//          output preprocessed file to standard output.

//          You can ask so what? Where is the problem? Your would be right,
//          there are no problem, yet, because multiple function
//          foward-declarations are, in fact, allowed.

//       2) Let's take a look at another case:

//           // --- test.h ---
//           struct foo {};

//           // -- test.cpp --
//           #include "test.h"
//           #include "test.h"

//          Everything is the same, except multiple definitions of a
//          struct are not allowed in a single file, so this program
//          doesn't compile anymore.

//          You can say: why would you include one header multiple 
//          times, just remove the second inclusion.
// 
//          And in this case it's indeed A solution.

//       3) But in the third case there will be no such solution: 

//           // ---- a.h ----
//           struct foo {};

//           // ---- b.h ----
//           #include "a.h"
//           // use foo in any way

//           // ---- c.h ----
//           #include "a.h"
//           // use foo in any way

//           // ---- d.h ----
//           #include "a.h"
//           #include "b.h"
//           // use stuff from a.h
//           // and stuff from b.h

//           // - test.cpp -
//           #include "d.h"
//           // use something from d.h

//          In this case there's no way you can avoid double
//          inclusion, because every file use the least amount
//          of header inclusion it needs, there's nothing to 
//          remove. Yet a copy of a.h is included in both
//          b.h and c.h, so including both of them will always
//          lead to double inclusion.

//          That's called diamond inclusion:
//                a.h
//               /  \
//              /    \
//            b.h    c.h  :) Because it looks like a diamond!
//             \     /
//              \   /
//               d.h

//          What to do then? Use header guards!

//       4) Header guards in action! In the same layout!
//           // ---- a.h ----
//           #ifndef A_H 
//           #define A_H
//
//           struct foo {};
//
//           #endif

//           // ---- b.h ----
//           #ifndef B_H 
//           #define B_H
//
//           #include "a.h"
//           // use foo in any way
//
//           #endif

//           // ---- c.h ----
//           #ifndef C_H 
//           #define C_H
//
//           #include "a.h"
//           // use foo in any way
//
//           #endif

//           // ---- d.h ----
//           #ifndef D_H 
//           #define D_H
//
//           #include "a.h"
//           #include "b.h"
//           // use stuff from a.h
//           // and stuff from b.h
//
//           #endif

//           // - test.cpp -
//           #include "d.h"
//           // use something from d.h

//          This kind of machinery is expected to be in every
//          header you ever write, do you get how it works?)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "math.h"

// TODO: you should always write out names of the variables, it's 
//       a valuable information and since your header is always the face
//       of your file's API, it's immensely useful:

// TODO: also, consider your naming. It's not that bad: check_coefficients
//       communicates that it checks coefficients, which is true... But?
//       Is it the full story? I think not, because a very natural question
//       arises immediately after reading this name: it checks for what?

//       You could choose, for example, check_coefficients_valid... or
//       shorter validate_coefficients, which give considerably more info
//       to the programmer. Agree?

// TODO: this function name seems weird, I couldn't guess what it does
//       before looking at the source code and that's me, I've seen
//       a few dozen of quadratic equation solvers.

//       The weird thing about naming that strikes me immediately is noun
//       "variables" in the name. It's very general, almost like saying
//       this function checks anything for anything.

//       For example, a better name would be assert_pointer_not_null, see,
//       now it's very specific. So specific in fact, there is only one way
//       to implement it, not a doubt.
int check_coefficients (double, double, double);


// TODO: But that leads to other problem with this function, does it
//       even need to exist?

//       The only thing it does is asserting, and asserting is an action
//       that, in most cases, should be placed as early as possible.

//       That's because assert, when fails prints line, column, function
//       where the fail happend, and in this case it's always gonna be
//       check_variables with a specific line and column, which makes this
//       information almost completely useless.

//       Reconsider existence of this function!
int check_variables (double*, double*);

int solve_with_discriminant (double, double, double, double*, double*);

int linear_equation (double b, double c, double* x1);

// TODO: It's not really a comparsion with null. Null can mean zero,
//       probably, but in programming it almost always means a zero
//       pointer, or in a more general sense a sentinel value with
//       a meaning of null or void.

//       Try to give it a better name!
int comparison_with_null (double);

int solve_square (double a, double b, double c, double* x1, double* x2);

// TODO: You should name function with verbs, because they do things :)
int square_equation (double a, double b, double c);

const double cmp_precision = 0.0000001;
