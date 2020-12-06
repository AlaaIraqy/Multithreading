#include <bits/stdc++.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
using namespace std;

#define MAX 10

#define MAX_THREAD 4
int n,m,x;
int matA[MAX][MAX];
int matB[MAX][MAX];
int matC[MAX][MAX];
int step_i = 0;

void* multi(void* arg)
{
	int core = step_i++;

	for (int i = core * n / 4; i < (core + 1) * n / 4; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				matC[i][j] += matA[i][k] * matB[k][j];
}

int main()
{
    cout << "Enter n"<<endl;
    cin >> n;
    cout << "Enter m"<<endl;
    cin >> m;
    cout << "Enter x"<<endl;
    cin >> x;
    cout <<"Enter Matrix A (row by row)"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>> matA[i][j];

        }
    }
    cout <<"Enter Matrix B (row by row)"<<endl;
     for(int i=0;i<m;i++){
        for(int j=0;j<x;j++){
            cin>> matB[i][j];

        }
    }

	cout << endl
		<< "Matrix A" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << matA[i][j] << " ";
		cout << endl;
	}


	cout << endl
		<< "Matrix B" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < x; j++)
			cout << matB[i][j] << " ";
		cout << endl;
	}

	pthread_t threads[n];


	for (int i = 0; i < n; i++) {
		int* p;
		pthread_create(&threads[i], NULL, multi, (void*)(p));
	}


	for (int i = 0; i < n; i++)
		pthread_join(threads[i], NULL);


	cout << endl
		<< "Multiplication of A and B" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < x ; j++)
			cout << matC[i][j] << " ";
		cout << endl;
	}
	return 0;
}
