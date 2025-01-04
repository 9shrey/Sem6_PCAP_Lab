#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
char toggle_case(char c) {
    if (c >= 'A' && c <= 'Z') {
        c = c + ('a' - 'A');
    } else if (c >= 'a' && c <= 'z') {
        c = c - ('a' - 'A');
    }
    return c;
}
int main(int argc, char *argv[]) {
    int rank, size;
    char str[] = "HELLO";  
    int len = 5;          
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    char local_char;
    if (rank < len) {
        local_char = str[rank];     
        local_char = toggle_case(local_char);
        str[rank] = local_char;
    }
    printf("Rank:%d toggle char:",rank);
    for(int i=0;i<5;i++){
    printf("%c",str[i]);
    }
    printf("\n");
    MPI_Finalize();
    return 0;
}

