#include <stdio.h>

#include "config.h"
#include "parse_args.h"
#include "process.h"

int main(int argc, char* argv[]){
    config conf = {0};
    
    char** files = parse_args(argc, argv, &conf);

    process_files(files);

    return 0;
}