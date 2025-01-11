#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <mpi.h>
void toggle_case(char* word) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (isupper(word[i])) {
            word[i] = tolower(word[i]);
        } else if (islower(word[i])) {
            word[i] = toupper(word[i]);
        }
    }
}
int main(int argc, char** argv) {
    int rank, size;
    char word[100];
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) {
        printf("Enter a word to send: ");
        fgets(word, 100, stdin);
        word[strcspn(word, "\n")] = 0;
        MPI_Ssend(word, strlen(word) + 1, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(word, 1, MPI_CHAR, 1, 0, MPI_COMM_WORLD, &status);
        printf("Modified word received: %s\n", word);

    } 
    else{
        MPI_Recv(word, 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status);
        toggle_case(word);
        MPI_Ssend(word, strlen(word) + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}

