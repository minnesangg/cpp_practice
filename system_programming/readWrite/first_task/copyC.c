#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){

    FILE *srcFile, *destFile;

    char buffer[4096];
    size_t bytesReaded;

    if(argc != 3){
        fprintf(stderr, "Using %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    srcFile = fopen(argv[1], "rb");
    if(srcFile == NULL){
        perror("Error opening input file.");
        return 2;
    }

    destFile = fopen(argv[2], "wb");
    if(destFile == NULL){
        perror("Error opening second file.");
        return 3;
    }

    while((bytesReaded = fread(buffer, 1, sizeof(buffer), srcFile)) > 0){
        fwrite(buffer, 1, bytesReaded, destFile);
    }

    printf("File copied!\n");

    fclose(srcFile);
    fclose(destFile);

    return 0;
}