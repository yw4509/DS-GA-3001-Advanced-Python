def better_grouper(inputs, n):
    iters = [iter(inputs)] * n
    return zip(*iters)


for _ in better_grouper(range(100000000), 10):
    pass
