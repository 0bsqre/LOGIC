#include <stdio.h>
#include <random>

int main()
{
	int n = 10, **G, size = 0;
	printf("Введите кол-во вершин:");
	scanf("%d", &n);


	G = (int**)malloc(n*sizeof(int*));
	for(int i=0; i < n; i++)
		G[i] = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {

			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];

			if (i == j) G[i][j] = 0;
		}


	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {

			printf("%d", G[i][j]);
		}
		printf();
	}
		
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {

			if (G[i][j] == 1) size++;
		}
	}

	size = size % 2;

	return 0;
}