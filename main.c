#include <stdio.h>
#include <stdlib.h>

#define HEX_BASE 16

#define DATA_SIZE 2
#define DATA_SIZE_NULL_TERM DATA_SIZE + 1
#define FILE_NOT_FOUND -1
#define STARTING_OFFSET 0x0

#define PE_HEADER_LOC 0x3C

void moveOffset(int* offset, int dest)
{
  *offset += ( dest - *offset); 
}

int getPEHeader(char* data)
{
  unsigned char a = data[0];
  unsigned char b = data[1];
  return b * HEX_BASE ^ 2 + a; 
}

int main()
{
  FILE* exe;
  exe = fopen("./tests/test.exe", "r");

  if ( !exe ) return FILE_NOT_FOUND;
  
  char* data = (char*) malloc(DATA_SIZE_NULL_TERM);  
  int* offset = (int*) malloc(sizeof(int));

  *offset = STARTING_OFFSET;
  while ( fgets(data, DATA_SIZE_NULL_TERM, exe) ) {
    if ( *offset == PE_HEADER_LOC ) moveOffset(offset, getPEHeader(data));
    printf("%X\n", *offset);
    *offset += DATA_SIZE;
  }

  free(data);
  free(offset);
}
