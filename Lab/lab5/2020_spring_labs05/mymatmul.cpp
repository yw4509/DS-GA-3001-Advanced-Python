#include <bits/stdc++.h> 

using namespace std; 
struct timespec start, end;
#define BILLION 1E9

vector<vector<double> > matmul(vector< vector<double > > &x, vector< vector<double > > &y){
	int m1 = x.size();

	int m2 = y.size();
	int n2 = y[0].size();

	double val;

	vector < vector < double > > z(m1, vector< double >(n2,0));

	for (int i=0; i<m1; i++){
		for (int j=0; j<n2; j++){
			val = 0.0;
			for (int k=0; k<m2; k++){
				val += x[i][k]*y[k][j];
			} 
			z[i][j] = val;
		}
	}
	return z;
}

double calculate_sum(vector< vector<double> > &z){
	int n = z.size();
	double ans = 0;

	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			ans += z[i][j];
		}
	}
	return ans;

}

int main(int argc, char* argv[])
{

	int N = atol(argv[1]);
	int repetitions = atoi(argv[2]);
	int i=0, j=0;

	vector<vector<double> > x(N, vector< double >(N,0));
	vector<vector<double> > y(N, vector< double >(N,0));
	vector<vector<double> > z;

	for (i=0;i<N; i++){
		for (j=0;j<N;j++){
			x[i][j] = rand() % 10 + 1;
			y[i][j] = rand() % 10 + 1;
		}
	}

	double total_time = 0.0;

	for (int i=0; i<=repetitions; i++)
	{
		clock_gettime(CLOCK_MONOTONIC, &start);
		z = matmul(x,y);
		clock_gettime(CLOCK_MONOTONIC, &end);

		float time_diff = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;

		total_time += time_diff;

		if (i == repetitions/2)
		{
			total_time = 0.0;
		}
	}

	double checksum = calculate_sum(z);
	int num_reps = repetitions / 2;
	double avg_time = total_time / num_reps;

	printf("checksum is %lf\n",checksum);
	printf("N: %d, <T_avg>: %e sec \n",N,avg_time);
	return checksum;

}