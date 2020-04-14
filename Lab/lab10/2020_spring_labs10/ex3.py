
from mpi4py import MPI

comm = MPI.COMM_WORLD

my_rank = comm.Get_rank()
p = comm.Get_size()

if my_rank != 0:
    message = 'Hello from the other rank {}'.format(my_rank)
    comm.send(message, dest = 0)

else:
    for pid in range(1,p):
        message = comm.recv(source = pid)
        print('Process {} receives message: {}'.format(my_rank, message))
