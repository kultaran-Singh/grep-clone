#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "process.h"
#include "config.h"
#include "output.h"

void process_sources(char** sources, config* conf){
    char* toSearch = sources[0];
    for(int i = 1; i < 2; i++){
        process_files(toSearch, sources[i], conf);
    }
}

void process_files(char* toSearch, char* file, config* conf){

    FILE* fptr = fopen(file, "r");
    char buff[60];
    int line_number = 1;
    int matches = 0;
    

    while(fgets(buff, sizeof(buff), fptr) != NULL){ //Iterate through all the lines
        if(conf->case_insensitive == 1){
            lower(buff);
            lower(toSearch);
        }
        if(strstr(buff, toSearch) != NULL){
            print_match(buff, line_number, conf);
            matches++;
        }
        line_number++;
    }

    if(conf->match_count == 1)
        printf("Matches: %d\n", matches);

    fclose(fptr);
}

char* lower(char* str){
    for(int i = 0; str[i] != '\0'; i++){
        str[i] = (char)tolower(str[i]);
    }
    return str;
}