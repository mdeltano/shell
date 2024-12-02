#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_LEN 256 //length of buffer where shell commands are stored

char ERROR_MESSAGE[30] = "An error has occurred\n";
int exit_switch = 0;



int main(int argc, char **argv){
    char* tokens[BUFFER_LEN];

    do{
        print_shell();
        tokens = parse(argc);

    } while(exit_switch == 0);
}


void print_shell(){
    printf("shell>");
}

char* parse(int argc){
    char* buffer[BUFFER_LEN];
    char* tokens[BUFFER_LEN];
    int i = 0;
    
    if(argc == 0){
        fgets(buffer, BUFFER_LEN, stdin);
        tokens = tokenizer(buffer);

        return tokens;
    }



}

char* tokenizer(char* buffer){
    tokens[0] = strtok(buffer, " \t\n");
    while(tokens[i] != NULL){
        i++;
        tokens[i] = strtok(NULL, " \t\n");
    }
    tokens[i+1] = NULL;
}



void printError(){
    write(STDERR_FILENO, ERROR_MESSAGE, strlen(ERROR_MESSAGE));
}

int process(char** tokens){
    int rc = fork();


}


/*
    if(strcmp(tokens[0][BUFFER_LEN], "exit") == 0 && strlen(tokens[1][BUFFER_LEN] != 0)){
        printError();
        return 0;
    }
    if(strcmp(tokens[0][BUFFER_LEN], "exit") == 0){
        return 1;
    }
    */