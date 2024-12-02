#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_LEN 256 //length of buffer where shell commands are stored

char ERROR_MESSAGE[30] = "An error has occurred\n";
int exit_switch = 0;
char** paths;

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

void parse(int argc){
    char* buffer[BUFFER_LEN];
    char* tokens = malloc(sizeof(BUFFER_LEN));
    int i = 0;
    
    if(argc == 1){
        fgets(buffer, BUFFER_LEN, stdin);
        tokens = tokenizer(buffer);

        //TODO: LOGIC FOR BUILT IN COMMANDS GOES HERE USING tokens[0]
        //IF ALL BUILT IN COMMAND LOGIC DOES NOT HIT, USE process(tokens) TO EXECUTE AN EXTERNAL COMMAND FROM PATHS IN paths

    }



}

void printError(){
    write(STDERR_FILENO, ERROR_MESSAGE, strlen(ERROR_MESSAGE));
}

int process(char* tokens){
    int rc = fork();

    if(rc < 0){
        printError();
        exit(0);
    }
    else if(rc == 0){ //child

    }



    return rc;
}

int main(int argc, char **argv){
    char* tokens = malloc(sizeof(BUFFER_LEN));

    do{
        print_shell();
        parse(argc);

    } while(exit_switch == 0);
}

