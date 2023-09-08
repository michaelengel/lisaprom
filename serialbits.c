#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

uint8_t bytes[] = { 
   0,
};

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s filename\n", argv[0]);
    exit(1);
  }

  int fd = open(argv[1], O_RDONLY);
  if (fd < 0) {
    perror("open");
    exit(2);
  }

  int nbytes = read(fd, bytes, 256);
  if (nbytes != 256) {
    printf("Could only read %d bytes\n", nbytes);
    exit(3);
  }

  uint8_t nibble = 0;

  for (int n = 0; n < 256; n++) {
    int bit = (bytes[n] & (1<<7))?1:0;
    nibble = (nibble << 1) | (bit & 1);

    if (((n+1) %  4) == 0) { 
      printf("%1X", nibble);
      nibble = 0;
      printf(" ");
    }
    if (((n+1) % 64) == 0) {
      printf("\n");
    }
    if (((n+1) % 256) == 0) {
      printf("\n");
    }
  }
  printf("\n\n");
}

