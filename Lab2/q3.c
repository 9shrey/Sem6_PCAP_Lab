#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define N 10
int main(int argc, char *argv[]) {
    int rank, size, array[N], value, result;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) {
        printf("Enter %d integers:\n", N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &array[i]);
        }
        for (int i = 1; i < size; i++) {
            MPI_Send(&array[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
        value = array[0];
    } else {
        MPI_Recv(&value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    if (rank % 2 == 0) {
        result = value * value; 
    } else {
        result = value * value * value;
    }
    printf("Process %d: Received %d, Result %d\n", rank, value, result);
    MPI_Finalize();
    return 0;
}

