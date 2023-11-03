#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "iomanager.h"

File* readFile(char* path){
    File* file = malloc(sizeof(File));
    file->path = path;
    file->text = NULL;

    FILE* filePointer = NULL;
    long lSize;

    filePointer = fopen(path, "r");
    if(filePointer == NULL){
        return NULL;
    }

    fseek(filePointer, 0L, SEEK_END);
    lSize = ftell(filePointer);
    rewind(filePointer);

    file->text = malloc(lSize+1);

    if(file->text == NULL){
        fclose(filePointer);
        return NULL;
    }

    if(fread(file->text, lSize, 1, filePointer) != 1){
        fclose(filePointer);
        return NULL;
    }

    fclose(filePointer);
    return file;
}