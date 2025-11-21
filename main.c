#include <stdio.h>
#include <stdlib.h>

#define FILE_NOT_FOUND -1

void moveOffset(int* offset, int dest)
{
  *offset += ( dest - *offset); 
}

int newEXEHeader(char* data)
{
  unsigned char a = data[0];
  unsigned char b = data[1];
  return b * 256 + a; 
}

int main()
{
  FILE* exe;
  exe = fopen("./tests/test.exe", "r");

  if ( !exe ) return FILE_NOT_FOUND;
  
  char* data = (char*) malloc(3);  
  int* offset = (int*) malloc(sizeof(int));

  *offset = 0x0;
  while ( fgets(data, 3, exe) ) {
    if ( *offset == 0x3C ) moveOffset(offset, newEXEHeader(data));
    printf("%X\n", *offset);
    *offset += 2;
  }

  free(data);
  free(offset);
}
