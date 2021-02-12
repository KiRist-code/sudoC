#include<iostream>
#include<stdlib.h>

void sudo(char **command[]);

void sudo(char **command[]){
    system(command);
}