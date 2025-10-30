#ifndef PROCESS_H
#define PROCESS_H
#include "config.h"

void process_sources(char** sources, config* conf);
void process_files(char* toSearch, char* file, config* conf);

#endif