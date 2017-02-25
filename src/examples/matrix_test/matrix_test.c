#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "common/print_util.h"
#include "common/time_util.h"
#include "common/matrix.h"

#define BREAK printf("\n");
int main(int argc, char **args)
{
    print_marker("XRobot","Hello World!");
    print_marker("XRobot","Test for matrix operations!");    


    double data[] = {1.2, 1.4, 1.6, 1.8, 1.9, 2.0};

    matrix_t *m = matrix_create_data(2, 3, data);
    /* matrix_print(m, "%.2f, "); */
    /* BREAK; */
  
    matrix_transpose_inplace(m);
    /* matrix_print(m, "%.2f, "); */
    /* BREAK; */

    matrix_subtract_inplace(m, m);
    /* matrix_print(m, "%.2f, "); */
    /* BREAK; */

    matrix_t *m1 = matrix_create_identity(3);
    /* matrix_print(m1, "%.2f, "); */
    /* BREAK; */


    matrix_add_inplace(m1, m1);
    /* matrix_print(m1, "%.2f, "); */
    /* BREAK; */

    matrix_mul_inplace(m1, m1);
    /* matrix_print(m1, "%.2f, "); */
    /* BREAK; */

    matrix_row_switch(m1, 0, 2);
    /* matrix_print(m1, "%.2f, "); */
    /* BREAK; */

    matrix_col_switch(m1, 1, 2);
    /* matrix_print(m1, "%.2f, "); */
    /* BREAK; */

    matrix_plu_t *m2 = matrix_PLU(m1);
    matrix_print(m2->P, "%.2f, ");
    BREAK;
    matrix_print(m2->L, "%.2f, ");
    BREAK;
    matrix_print(m2->U, "%.2f, ");
    BREAK;
    matrix_t *m3 = matrix_mul(m2->L, m2->U);
    matrix_t *m4 = matrix_mul(m2->P, m1);
    if(!matrix_equal(m3,m4))
        printf("Yeah! :) %f \n", m2->det);
    else
        puts(":(");
    matrix_destroy(m2->P);
    matrix_destroy(m2->L);
    matrix_destroy(m2->U);
    free(m2);
    matrix_destroy(m);
    matrix_destroy(m1);
    return 0;
}
