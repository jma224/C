#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

bool isPowerOfTwo(int x);
bool test(int tri_height, int L);
void cut();

int main(int argc, char *argv[]){
	if (argc != 3){		   
		printf("ERROR: Wrong number of arguments. Two required.\n");
		return -1;
	}
	if (atoi(argv[1])<=0 || atoi(argv[1])%2 != 1){
	printf("ERROR: Bad argument. Height must be positive odd integer.\n");
	return -1;
	}

	int height = atoi(argv[1]);
	int middle = (height+1)/2;
	int L = atoi(argv[2]);
	int tri_height = height/2+1;
	if (!isPowerOfTwo(tri_height) || !test(tri_height, L)){
		printf("ERROR: Height does not allow evenly dividing requested number of levels. \n");
		return -1;
	}

	//initial diamond
	char triup[tri_height][height];
	char tridown[tri_height-1][height];
	for (int i=0; i<tri_height; i++){
		for (int j=0; j<height; j++){
			triup[i][j]=' ';
		}
	}
	for (int i=0; i<tri_height; i++){
		for (int j=0; j<height; j++){
			if (j >= middle-i-1 && j< middle+i){
			       triup[i][j]='*';
			}
		}
	}

        //cutting
		cut(height, tri_height, triup, L, height/2, height/2);
	


	//tridown copy
	for (int i=0; i<tri_height-1; i++){
	        for (int j=0; j<height; j++){
			tridown[i][j]=triup[tri_height-2-i][j];
		}
	}




	//printing
	for (int i=0; i<tri_height; i++){
		for (int j=0; j<height; j++){
			printf("%c", triup[i][j]);
		}
		printf("\n");
	}
	for (int i=0; i<tri_height-1; i++){
		for (int j=0; j<height; j++){
			printf("%c", tridown[i][j]);
		}
		printf("\n");
	}

	return 0;
}


void cut(int height, int tri_h, char triup[height/2+1][height], int L, int row, int col){
	if (L>1){
		for (int i=0; i<tri_h/2; i++){
			for (int j=0; j<height; j++){
				if (j>=col-i && j<=col+i){
					triup[row-i][j]=' ';
				}	
			}
		}

		cut(height, tri_h/2, triup, L-1, row-tri_h/2, col);
		cut(height, tri_h/2, triup, L-1, row, col-tri_h/2);
		cut(height, tri_h/2, triup, L-1, row, col+tri_h/2);
	}

}



	
bool isPowerOfTwo(int x){
	if (x%2 != 0){
		return false;
	}
	while (x>1){
		x = x/2;
		if (x==1){
			return true;
		}
		if (x%2 != 0){
			return false;
		}
	}
	
}

bool test(int tri_height, int L){
	int t = 1;
	for (int i=0; i<L-1; i++){
		t = t*2;
	}
	if (tri_height>=t){
		return true;
	}else{
		return false;
	}
}
