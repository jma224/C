#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	if (argc != 2){
		printf("Wrong number of arguments. One required.\n");
		return -1;
	}

	FILE*fp = fopen(argv[1],"r");
	if (fp == NULL){
		printf("Cannot read document.\n");
		return -1;
	}
	size_t sz;
	fseek(fp, 0L, SEEK_END);
	sz = ftell(fp);
	rewind(fp);
	char file_data_array[sz+1];
	fread(file_data_array, 1, sz+1, fp);


	char* head= "<a href=\"/wiki/";
	char* tail= "</a>";
	char* title = " title=\"";
	char *file = file_data_array;


	while (file != NULL){
		char *s_head = strstr(file, head);
		char *s_tail = strstr(file, tail);
		char *s_title = strstr(file, title);
		if(s_head==NULL){
			exit(0);
		}
		if (s_head !=NULL&&s_tail!=NULL&&s_title!=NULL&&(s_title-s_head)>0&&(s_tail-s_title)>0){
			for (int i=0; i<s_tail-s_head-15; i++){
				if(s_title[i+8] != '"'){
					printf("%c",s_title[i+8]);
				}else{
					break;
				}
			}
			printf("\n");
		}
		file = s_tail+4;
	}
	
	return 0;
}



