
from mpi4py import MPI
import time

comm = MPI.COMM_WORLD
rank = comm.Get_rank()

if rank == 0:
    data = {'a': 7, 'b': 3.14}
    req = comm.isend(data, dest=1, tag=11)
    req.wait()
    print('Process {} sent {}'.format(rank, data))
    
elif rank == 1:
    req = comm.irecv(source=0, tag=11)
    # do something
    time.sleep(2)
    
    data = req.wait()
    print('Process {} received {}'.format(rank, data))
