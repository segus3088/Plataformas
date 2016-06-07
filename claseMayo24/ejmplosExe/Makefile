run: compile
	mpirun -np 8 --hostfile machinefile /shared/openmpi_demo
compile:
	mpicc openmpi_demo.c -o /shared/openmpi_demo
clean:
	rm -rf /shared/openmpi_demo
ex1: example1
	mpirun -np 2 --hostfile machinefile /shared/ex1
example1:
	mpicc mpiExample1.c -o /shared/ex1
ex2: example2
	mpirun -np 8 --hostfile machinefile /shared/ex2
example2:
	mpicc mpiExample2.c -o /shared/ex2
ex3: example3
	mpirun --mca btl_tcp_if_exclude lo,eth0 -np 2 --hostfile machinefile /shared/ex3
example3:
	mpicc mpiExample3.c -o /shared/ex3
ex4: example4
	mpirun --mca btl_tcp_if_exclude lo,eth0 -np 8 --hostfile machinefile /shared/ex4
example4:
	mpicc mpiExample4.c -o /shared/ex4
ex5: example5
	mpirun --mca btl_tcp_if_exclude lo,eth0 -np 8 --hostfile machinefile /shared/ex5
example5:
	mpicc mpiExample5.c -o /shared/ex5
mpi01: mpi01c
	mpirun --mca btl_tcp_if_exclude lo,eth0 -np 2 --hostfile machinefile /shared/mpi01
mpi01c:
	mpicc mpi_01.c -o /shared/mpi01
mpiD41: mpiD41c
	mpirun --mca btl_tcp_if_exclude lo,eth0 -np 2 --hostfile machinefile /shared/mpiD41
mpiD41c:
	mpicc mpiD41.c -o /shared/mpiD41
mpiJ07: mpiJ07c
	mpirun --mca btl_tcp_if_exclude lo,eth0 -np 8 --hostfile machinefile /shared/mpiJ07
mpiJ07c:
	mpicc mpiJ07.c -o /shared/mpiJ07