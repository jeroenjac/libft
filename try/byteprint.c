#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <arpa/inet.h>
#include <errno.h>
#include <strings.h>

void print_bytes(char * ty, char * val, unsigned char * bytes, size_t num_bytes) {
  printf("(%*s) %*s = [ ", 15, ty, 16, val);
  for (size_t i = 0; i < num_bytes; i++) {
    printf("%*u ", 3, bytes[i]);
  }
  printf("]\n");
}

#define SHOW(T,V) do { T x = V; print_bytes(#T, #V, (unsigned char*) &x, sizeof(x)); } while(0)

int main() {
  long	a;
  char	b[3] = "def";
  
  a = 255;
  SHOW(int, a);
  a = 256;
  SHOW(int, a);
  a = 258;
  SHOW(int, a);
  a = 256*256 + 256*8 + 5;
  SHOW(int, a);
  SHOW(int, b);
  bzero(b, 3);
  SHOW(int, b);
  return 0;
}
