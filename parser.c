#include <stdio.h>
#include <stdlib.h>

#include "offsets.h"
#include "parser.h"

#define SUCCESS 0
#define FILE_NOT_FOUND -1

#define DATA_SIZE 2
#define DATA_SIZE_NULL_TERM DATA_SIZE + 1
#define STARTING_OFFSET 0x0

#define PE_HEADER_LOC 0x3C

int run(char* exePath, char* wasmPath)
{
  FILE* exe;
  FILE* wasm;
  exe = fopen(exePath, "r");
  wasm = fopen(wasmPath, "w");

  if ( !exe ) return FILE_NOT_FOUND; 
 
  char* data = (char*) malloc(DATA_SIZE_NULL_TERM);
  int* offset = (int*) malloc(sizeof(int));

  *offset = STARTING_OFFSET;
  while ( fgets(data, DATA_SIZE_NULL_TERM, exe) ) {
    if ( *offset == PE_HEADER_LOC ) moveOffset(offset, getPEHeader(data));
    *offset += DATA_SIZE;
  }

  fprintf(wasm, "");

  free(data);
  free(offset);

  return SUCCESS;
}
