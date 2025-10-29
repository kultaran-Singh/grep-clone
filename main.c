#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

    //Checking arguments given
    if(argc < 3){
        printf("Too Few Arguments\n");
        return 0;
    }
    if(argc > 3){
        printf("Too Many Arguments\n");
        return 0;
    }
    char* toSearch = argv[1];
    char toOpen[100];
    sprintf(toOpen, argv[2]);
    FILE* fp = fopen(toOpen, "r"); 

    if(fp == NULL){ //Checking if the file opened
        printf("Couldn't open file\n");
        return 0;
    }
    
    char buff[50];
    bool found = false;
    while(fgets(buff, sizeof(buff), fp) != NULL){
        if(strstr(buff, toSearch) != NULL){
            printf("%s", buff);
            found = true;
        }
        
    }
    if(!found)
        printf("Not Found\n");

    fclose(fp);
    return 0;
}   