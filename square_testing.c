/*program for testing*/

#include "square_equation.c"

int main ()
{
    printf ("Solving the quadratic equation of the form: ax^2 + bx + c = 0\n\n");

    FILE* f;
    FILE* fp;

    f = fopen("square_tests.txt", "r");

    int A[3] = {0};
    char str_1 [30];
    char str_2 [30]; 
    char *s_1;
    char *s_2;
    int i = 0;
    char smb = 0;
    int num_rtests = 0; // mumber of right passed tests
    int num_tests = 6; // number of all tests

    while (feof (f) == 0)
    {
        for (i = 0; i < 3; i++)
        {
            fscanf(f,"%d", &A[i]);
        }

        double a = A[0], b = A[1], c = A[2];

        square_equation (a, b, c);

        fp = fopen ("equation_results.txt", "r");

        s_2 = fgets (str_2, sizeof(str_2), fp);

        printf ("Program: %s\n", s_2);

        fseek (f, 1, SEEK_CUR); // pointer offset 1 byte to the right

        s_1 = fgets (str_1, sizeof(str_1), f);
        
        printf ("Correct: %s\n", s_1);

        if (strcmp (s_1, s_2) == 0)
         num_rtests++;
    }

    fclose (f);
    fclose (fp);
    remove ("equation_results.txt");

    printf ("Successfully passed tests: %d/%d\n", num_rtests, num_tests);

    return 0;
}
