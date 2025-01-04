#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

float calculate(float num1, float num2, char operation) {
    float result = 0.0;
    switch (operation) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/':
            if (num2 != 0) result = num1 / num2; break;
    }
    return result;
}

int main(int argc, char *argv[]) {
    int rank, size;
    float num1=7.3, num2=3.6, result;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) {
        result = calculate(num1, num2, '+');
        printf("Process %d: %.2lf + %.2lf = %.2lf\n", rank, num1, num2, result);
    } else if (rank == 1) {
        result = calculate(num1, num2, '-');
        printf("Process %d: %.2lf - %.2lf = %.2lf\n", rank, num1, num2, result);
    } else if (rank == 2) {
        result = calculate(num1, num2, '*');
        printf("Process %d: %.2lf * %.2lf = %.2lf\n", rank, num1, num2, result);
    } else if (rank == 3) {
        result = calculate(num1, num2, '/');
        printf("Process %d: %.2lf / %.2lf = %.2lf\n", rank, num1, num2, result);
    }
MPI_Finalize();
return 0;
}

