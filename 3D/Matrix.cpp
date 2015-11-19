
#include "TXLib.h"

double Matrix [3] [3] = {{1, 0, 0},
                         {0, 1, 0},
                         {0, 0, 1}};

void MatrixMul (double Matrix1 [3] [3], const double Matrix2 [3] [3]);

int main()
    {
    txCreateWindow (800, 600);

    double Matrix1 [3] [3] = {{1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9}};

    double Matrix2 [3] [3] = {{1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9}};

    MatrixMul (Matrix1, Matrix2);

    printf ("%lf, %lf, %lf, \n%lf, %lf, %lf, \n%lf, %lf, %lf.", Matrix1 [0] [0], Matrix1 [0] [1], Matrix1 [0] [2],
                                                                Matrix1 [1] [0], Matrix1 [1] [1], Matrix1 [1] [2],
                                                                Matrix1 [2] [0], Matrix1 [2] [1], Matrix1 [2] [2]);

    return 0;
    }

void MatrixMul (double Matrix1 [3] [3], const double Matrix2 [3] [3])
    {
    double mtx [3] [3] = {{Matrix1 [0] [0], Matrix1 [0] [1], Matrix1 [0] [2]},
                          {Matrix1 [1] [0], Matrix1 [1] [1], Matrix1 [1] [2]},
                          {Matrix1 [2] [0], Matrix1 [2] [1], Matrix1 [2] [2]}};

    Matrix1 [0] [0] = mtx [0] [0] * Matrix2 [0] [0] + mtx [0] [1] * Matrix2 [1] [0] + mtx [0] [2] * Matrix2 [2] [0];
    Matrix1 [0] [1] = mtx [0] [0] * Matrix2 [0] [1] + mtx [0] [1] * Matrix2 [1] [1] + mtx [0] [2] * Matrix2 [2] [1];
    Matrix1 [0] [2] = mtx [0] [0] * Matrix2 [0] [2] + mtx [0] [1] * Matrix2 [1] [2] + mtx [0] [2] * Matrix2 [2] [2];

    Matrix1 [1] [0] = mtx [1] [0] * Matrix2 [0] [0] + mtx [1] [1] * Matrix2 [1] [0] + mtx [1] [2] * Matrix2 [2] [0];
    Matrix1 [1] [1] = mtx [1] [0] * Matrix2 [0] [1] + mtx [1] [1] * Matrix2 [1] [1] + mtx [1] [2] * Matrix2 [2] [1];
    Matrix1 [1] [2] = mtx [1] [0] * Matrix2 [0] [2] + mtx [1] [1] * Matrix2 [1] [2] + mtx [1] [2] * Matrix2 [2] [2];

    Matrix1 [2] [0] = mtx [2] [0] * Matrix2 [0] [0] + mtx [2] [1] * Matrix2 [1] [0] + mtx [2] [2] * Matrix2 [2] [0];
    Matrix1 [2] [1] = mtx [2] [0] * Matrix2 [0] [1] + mtx [2] [1] * Matrix2 [1] [1] + mtx [2] [2] * Matrix2 [2] [1];
    Matrix1 [2] [2] = mtx [2] [0] * Matrix2 [0] [2] + mtx [2] [1] * Matrix2 [1] [2] + mtx [2] [2] * Matrix2 [2] [2];
    }
