#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <arpa/inet.h>
#include <errno.h>

void print_bytes(char * ty, char * val, unsigned char * bytes, size_t num_bytes) {
  printf("(%*s) %*s = [ ", 15, ty, 16, val);
  for (size_t i = 0; i < num_bytes; i++) {
    printf("%*u ", 3, bytes[i]);
  }
  printf("]\n");
}

#define SHOW(T,V) do { T x = V; print_bytes(#T, #V, (unsigned char*) &x, sizeof(x)); } while(0)

int main() {
  SHOW(int, 0);
  SHOW(int, 1);
  SHOW(int, 17);
  SHOW(int, -17);
  SHOW(int, 256);
  SHOW(int, INT_MAX);
  SHOW(int, INT_MAX+1);
  SHOW(unsigned int, 17);
  SHOW(unsigned int, -17);  // no compiler error!
  SHOW(unsigned int, UINT_MAX);
  SHOW(unsigned int, UINT_MAX+1);
  SHOW(unsigned char, 255);
  SHOW(long, 17);
  SHOW(short, 17);
  SHOW(uint32_t, 17);
  SHOW(uint32_t, htonl(17));
  SHOW(uint16_t, 17*256+18);
  SHOW(uint16_t, htons(17*256+18));
  SHOW(void*, &errno);
  SHOW(unsigned int, 1 << 1);
  SHOW(unsigned int, 1 << 2);
  SHOW(unsigned int, 1 << 4);
  SHOW(unsigned int, 1 << 8);
  SHOW(unsigned int, 1 << 16);
  return 0;
}
