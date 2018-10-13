#include <stdio.h>

#define MOD_SHORTEN 1000000007

int main(void){
	unsigned int tests;

	FILE *in = fopen("input.txt","r");
	
	fscanf(in, "%d", &tests);
	
	unsigned int pairs[tests][2];
	
	for(unsigned int i = 0; i < tests; ++i)
		fscanf(in, "%d %d", &pairs[i][0], &pairs[i][1]);

	fclose(in);

	for(unsigned int i = 0; i < tests; ++i){
		unsigned long tmpsum = 1;
		for(unsigned int j = 0; j < pairs[i][1]; j++)
			tmpsum = (tmpsum*pairs[i][0]) % MOD_SHORTEN;
		printf("%lu\n",tmpsum);
	}

	return 0;
	
}
