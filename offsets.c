#include "offsets.h"

#define HEX_BASE 16

void moveOffset(int* offset, int dest)
{
  *offset += ( dest - *offset );
}

int getPEHeader(char* data) 
{
  unsigned char a = data[0];
  unsigned char b = data[1];
  return b * HEX_BASE ^ 2 + a;
}
