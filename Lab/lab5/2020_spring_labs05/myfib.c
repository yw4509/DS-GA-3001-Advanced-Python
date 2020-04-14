#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct timespec start, end;
#define BILLION 1E9

int fib(int n)
{
	int tmp, i,a=0,b=1;
	for (i=0; i<n; i++){
		tmp = a;
		a += b;
		b = tmp;
	}
	return a;
}

int main(int argc, char* argv[])
{
	int ans=0;

	int N = atol(argv[1]);
	int repetitions = atoi(argv[2]);

	double total_time = 0.0;

	for (int i=0; i<=repetitions; i++)
	{
		clock_gettime(CLOCK_MONOTONIC, &start);
		ans = fib(N);
		clock_gettime(CLOCK_MONOTONIC, &end);

		float time_diff = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;

		total_time += time_diff;

		if (i == repetitions/2)
		{
			total_time = 0.0;
		}
	}

	int num_reps = repetitions / 2;
	double avg_time = total_time / num_reps;

	printf("Fibonacci result is %d\n",ans);
	printf("N: %d, <T_avg>: %e sec \n",N,avg_time);
	return ans;

}