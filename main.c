#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printList(){
}

void create(){
}

void* cse320_malloc(){
	return void*(0);
}

void* cse320_virt_to_phys(void* virt){
	return void*(0);
}

int main(int argc, char** argv){
	if (argc != 1){
		printf("Invalid number of arguments (expected 1)\n");
	} else {
		int status = 1;
		char str[255];
		do {
			char** args;
			printf("> ");
			fgets(str,255,stdin);
			char* p = strchr(str,'\n');
                        if (p != NULL){
                                str[p-str]='\0';
                        }
			if ( strcmp(str,"") == 0 ){
			} else if ( strcmp(str,"create") == 0){
				create();
			} else if ( strcmp(str,"list") == 0){
				printList();
			} else if ( strcmp(str,"exit") == 0){
				status = 0;
			} else {
				char* token;
                                int i = 0;
                                for (token=strtok(str," "); token != NULL; token=strtok(NULL, " ")){
                                        args[i] = strdup(token);
                                        i += 1;
                                }
                                args[i] = NULL;
				if ( strcmp(args[0],"kill") == 0){
				} else if ( strcmp(args[0],"mem") == 0){
				} else if ( strcmp(args[0],"allocate") == 0){
				} else if ( strcmp(args[0],"read") == 0){
				} else if ( strcmp(args[0],"write") == 0){
				} else {
					printf("Invalid command: %s not recognized\n", args[0]);
				}
				i -= 1;
                                while (i >= 0){
                                        free(args[i]);
                                        i -= 1;
                                } 
			}
			
		} while (status);
		
	}
}
