#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_LEN 256 //length of buffer where shell commands are stored

char ERROR_MESSAGE[30] = "An error has occurred\n";
int exit_switch = 0;

void print_shell(){
    printf("shell>");
}

char* tokenizer(char* buffer){
    char* tokens = malloc(sizeof(BUFFER_LEN));
    int i = 0;

    tokens[0] = strtok(buffer, " \t\n");
    while(tokens[i] != NULL){
        i++;
        tokens[i] = strtok(NULL, " \t\n");
    }
    tokens[i+1] = NULL;

    return tokens;
}

char* parse(int argc){
    char* buffer[BUFFER_LEN];
    char* tokens = malloc(sizeof(BUFFER_LEN));
    int i = 0;
    
    if(argc == 1){
        fgets(buffer, BUFFER_LEN, stdin);
        tokens = tokenizer(buffer);

        return tokens;
    }



}

void printError(){
    write(STDERR_FILENO, ERROR_MESSAGE, strlen(ERROR_MESSAGE));
}

int process(char* tokens){
    int rc = fork();


}

int main(int argc, char **argv){
    char* tokens = malloc(sizeof(BUFFER_LEN));

    do{
        print_shell();
        tokens = parse(argc);
        process(tokens);

    } while(exit_switch == 0);
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