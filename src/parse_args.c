#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "config.h"
#include "parse_args.h"


char** parse_args(int argc, char* argv[], config* conf){

    char c;
    char** files = calloc(2, sizeof(char**));
    int i = 0;
    while((c = getopt(argc, argv, "ilrc")) != -1){
        switch(c){
            case 'i':
                conf->case_insensitive = 1;
                break;
            case 'l':
                conf->line_number = 1;
                break;
            case 'r':
                conf->recurse = 1;
                break;
            case 'c':
                conf->match_count = 1;
                break;
        }
    }
    for(int index = optind; index < argc; index++){
        files[i] = argv[index];
        i++;
    }
    return files;
}