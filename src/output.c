#include <stdio.h>
#include "output.h"
#include "config.h"

void print_match(char* line, int line_number, config* conf){
    if(conf->line_number == 0){
        printf("%s", line);
        return;
    }
    printf("[%d]%s", line_number, line);
    return;
}   