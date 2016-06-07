#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char **argv) {
	int my_rank, p_size, tag = 0, dest=1, sourceM=0;
	char msg[20];
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &p_size);
	if (my_rank == 0) {
		strcpy(msg, "Hello ");
		MPI_Send(msg, strlen(msg) + 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
	} else if (my_rank == 1) {
		MPI_Recv(msg, 20, MPI_CHAR, sourceM, tag, MPI_COMM_WORLD, &status);
		printf("Mensaje recibido: %s\n", );
	}
	MPI_Finalize();
}
