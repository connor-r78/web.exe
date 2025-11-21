#include <stdio.h>
#include <stdlib.h>

int newEXEHeader(char* data)
{
  int a = data[0];
  int b = data[1];
  return b * 256 + a; 
}

int main()
{
  FILE* exe;
  exe = fopen("./tests/test.exe", "r");
  
  char* data = (char*) malloc(3);
  
  int offset = 0;
  while ( fgets(data, 3, exe) ) {
    if ( offset == 0x3C ) printf("%d\n", newEXEHeader(data));
    offset += 2;
  }
}
