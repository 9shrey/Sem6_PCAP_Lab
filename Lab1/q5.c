#include<mpi.h>
#include<stdio.h>
int fac(int rank){
  if(rank==0 || rank==1){
    return 1;
  }
  else{
    return rank*fac(rank-1);
  }
}
int fib(int rank){
  if(rank==0 || rank ==1){
    return 1;
  }
  else{
    return fib(rank-2)+fib(rank-1);}
}
int main(int argc, char *argv[])
{
int rank,size;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);
if(rank%2==0){
printf("Rank is %d : Factorial is: %d\n",rank,fac(rank));
}
else{
printf("Rank is %d : Fibonacci is: %d\n",rank,fib(rank));
}
MPI_Finalize();
return 0;
}
