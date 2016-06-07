#include <stdio.h>
#include <string.h>
#include <mpi.h>
#include <malloc.h>


int main(int argc,char *argv[]){
	int rank, size, tag = 0, dest, sourceM, count=1, i, stride;
	int *miParte;

	//inicializando el arreglo de int
	int arrayEnteros[100];

	for (i = 0; i < 100; ++i)
	{
		/* code */
		arrayEnteros[i] = i+1;
	}

	MPI_Status stat;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	stride = (sizeof(arrayEnteros)/sizeof(int))/(size-1);//se envia la cantidad de datos dividido la cantidad de nodos
	//dest = rank + 1;
	//sourceM = size -1;
	//stride = 25;
	printf("stride %d\n", stride);
	//stride = 25;

	if (rank == 0)
	{
		/* code */
		int acumulador;


		for (i = 1; i < size; ++i)
		{
			/* code */
			dest = i;
			MPI_Send(&arrayEnteros[stride*(i - 1)], stride, MPI_INT, dest, tag, MPI_COMM_WORLD);
		}
		for ( i = 1, acumulador = 0; i < size; ++i)
		{
			/* code */
			int dataIn;
			sourceM = i;
			MPI_Recv(&dataIn, 1, MPI_INT, sourceM, tag, MPI_COMM_WORLD, &stat);
			acumulador += dataIn;
		}
		printf("Total: %d\n", acumulador);
		//MPI_Send();
		//MPI_Recv();
	} else {
		//data = 1;//solo se envia la suma
		dest = 0;
		sourceM = 0;//ok

		int acumulador = 0;
		miParte = (int*)malloc(sizeof(int)*stride);//inicializa el vector con el apuntador con lengt de lo recibido
		MPI_Recv(miParte, stride, MPI_INT, sourceM, tag, MPI_COMM_WORLD, &stat);
		for (i = 0, acumulador=0; i < stride; ++i)
		{
			/* code */
			acumulador += miParte[i];
		}
		MPI_Send(&acumulador, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
		//MPI_Recv();
		//MPI_Send();

	}


	MPI_Finalize();
	return 0;
}