//* Jingyan Ma *//
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]){

	if (argc != 2){
		printf("ERROR: Wrong number of arguments. One required.\n");
		return -1;
	}

	if (atoi(argv[1])<=0 || atoi(argv[1])%2 != 1){
		printf("ERROR: Bad argument. Height must be positive odd integer.\n");
		return -1;
	}

	int height = atoi(argv[1]);
	int middle = (height+1)/2;
	for (int i=0; i<middle; i++){
		for (int j=0; j<middle-1-i; j++){
			printf(" ");
		}
		for (int j=0; j<2*i+1; j++){
			printf("*");
		}
		for (int j=middle+i; j<height; j++){
			printf(" ");
		}
		printf("\n");
	}
	for (int i=1; i<middle; i++){
		for (int k=0; k<i; k++){
			printf(" ");
		}
		for (int k=0; k<height-2*i; k++){
			printf("*");
		}
		for (int k=0; k<i; k++){
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}

