#include <stdio.h>
#include <string.h>

#define BUFFER_LEN 256 //length of buffer where shell commands are stored

char ERROR_MESSAGE[30] = "An error has occurred\n";
int exit_switch = 0;



int main(int argc, char **argv){
do{
    print_shell();
    exit_switch = parse();








} while(exit_switch == 0);
}


void print_shell(){
    printf("shell>");
}

int parse(){
    char buffer[BUFFER_LEN];
    
    fgets(buffer, BUFFER_LEN, stdin);
    char* tokens[BUFFER_LEN][BUFFER_LEN] = tokenize(&buffer);

    if(strcmp(tokens[0][BUFFER_LEN], "exit") == 0 && strlen(tokens[1][BUFFER_LEN] != 0)){
        write(STDERR_FILENO, ERROR_MESSAGE, strlen(ERROR_MESSAGE));
    }
    if(strcmp(tokens[0][BUFFER_LEN], "exit") == 0){
        return 1;
    }


}

char* tokenize(char* buffer){
    int i = 0;
    int j = 0;
    char* tokens[BUFFER_LEN][BUFFER_LEN] = NULL;

    for(int j; j < BUFFER_LEN; j++){
        if(buffer[j-1] == (' ' || '\t') && buffer[j] != (' ' || '\t')){
            tokens[i][j] = '\0';
            i++;
        }  
        if(buffer[j] != (' ' || '\t')){
            tokens[i][j] = buffer[j];
        }
    }

    return tokens;
}
