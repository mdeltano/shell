#include <stdio.h>
#include <string.h>

#define BUFFER_LEN 256 //length of buffer where shell commands are stored

char ERROR_MESSAGE[30] = "An error has occurred\n";



int main(int argc, char **argv){
do{
    print_shell();
    parse();








} while(1);
}


void print_shell(){
    printf("shell>");
}

int parse(){
    char buffer[BUFFER_LEN];
    char cmd[BUFFER_LEN];
    char* args[BUFFER_LEN];
    int i = 0;
    int j = 0;
    
    fgets(buffer, BUFFER_LEN, stdin);
    tokenize(&buffer);

    
}

char* tokenize(char* buffer){
    int i = 0;
    int j = 0;
    char* tokens[BUFFER_LEN][BUFFER_LEN];

    for(int j; j < BUFFER_LEN; j++){
        if(buffer[j-1] == (" " || "\t") && buffer[j] != (" " || "\t")){
            i++;
        }  
        if(buffer[j] != (" " || "\t")){
            tokens[i][j] = buffer[j];
        }
    }


}
