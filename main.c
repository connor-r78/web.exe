#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INVALID_USAGE -2

#define ARGS 5

extern int run(char* exePath, char* wasmPath);

void print_usage(char* name)
{
  printf("Usage: %s -x example.exe -o example.wasm\n", name);
}

int main(int argc, char** argv)
{
  if ( argc != ARGS ) {
    print_usage(argv[0]);
    return INVALID_USAGE;
  }

  int opt;
  char* exe = NULL;
  char* wasm = NULL;

  while ( (opt = getopt(argc, argv, "x:o:")) != -1 ) {
    switch ( opt ) {
    case 'x':
      exe = optarg;
      break;
    case 'o':
      wasm = optarg;
      break;
    case '?':
      printf("Unknown option: %c\n", optopt);
      print_usage(argv[0]);
    }
  }

  return run(exe, wasm);
}
