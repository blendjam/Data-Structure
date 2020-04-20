#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE  256
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_SIZE];
    int age;
}person;

unsigned int hash(char * name){
    int length = strlen(name);
    unsigned int hash_value;
    for(int i = 0 ; i < length ; i++)
        hash_value += name[i];
    return hash_value;
}

int main()
{
    printf("Sanket => %u\n",hash("Sanket"));
    printf("Sayog => %u\n",hash("Syog"));

    return 0;
}