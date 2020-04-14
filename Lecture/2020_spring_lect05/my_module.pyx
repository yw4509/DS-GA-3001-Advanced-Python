def cfunc(int n):
    cdef int a = 0
    cdef int i
    for i in range(n):
        a += i
    return a
