
from mpi4py import MPI
import timeit

comm = MPI.COMM_WORLD
rank = comm.Get_rank()

N = 10000000

def parSum():
    if rank == 0: 
        s = sum(range(N//2))
        comm.send(s,dest=2)
        
    elif rank == 1:
        s = sum(range(N//2+1,N))
        comm.send(s,dest=2)
        
    elif rank == 2:
        s1 = comm.recv(source=0)
        s2 = comm.recv(source=1)
        print (s1+s2)


def serSum():
    s = sum(range(N))

if rank == 0:
    
    tp = timeit.Timer("parSum()","from __main__ import parSum")
    print ('Parallel time: {:.4f} sec'.format(tp.timeit(number=10))) 

    ts = timeit.Timer("serSum()","from __main__ import serSum")
    print ('Serial time: {:.4f} sec'.format(ts.timeit(number=10))) 

