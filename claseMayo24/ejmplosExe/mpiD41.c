#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char **argv) {
	int my_rank, p_size, tag = 0, dest, sourceM, count=1;
	char recvbuf, sendbuf;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &p_size);
	if (my_rank == 0) {
		sourceM = 1;
		dest = 1;
		MPI_Recv(recvbuf, count);
		MPI_Send(sendbuf, strlen(msg) + 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
	} else if (my_rank == 1) {
		sourceM = 0;
		dest = 0;
		MPI_Recv(msg, 20, MPI_CHAR, sourceM, tag, MPI_COMM_WORLD, &status);
		
	}
	MPI_Finalize();
}
