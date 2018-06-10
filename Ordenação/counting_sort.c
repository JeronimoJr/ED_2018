

#include <stdio.h>

int main(int argc, char **argv){
	int i, j, k, qtd, n;
	
	scanf("%d", &n)
	
int vet[n];
int vetor[n];

	for(i = 0; i < n; i++)
		vet[i] = 0;
		
	for(i = 0; i < n; i++)
		vet[vetor[i]] = 0;
		
		for(i = 0, j = 0; j < qtd; j++){
			for(k = vet[j]; k > 0; k--)
				vetor[i++] = j;
		}
			
	return 0;
}

