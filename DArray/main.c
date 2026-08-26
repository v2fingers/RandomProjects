#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  uint32_t *data;
  size_t count;
  size_t capacity;
} DArray;

int main() {
  DArray xs = {0};
  for (int x = 0; x < 100; ++x) {
    if (xs.count >= xs.capacity) {
      if (xs.capacity == 0)
        xs.capacity = 256;
      else
        xs.capacity *= 2;
      xs.data = realloc(xs.data, xs.capacity * sizeof(*xs.data));
    }
    xs.data[xs.count++] = x;
  }
  for (size_t i = 0; i < xs.count; ++i) {
    printf("%u\n", xs.data[i]);
    printf("Address: %p\n", &xs);
  }
  printf("Count: %zu\n", xs.count);
  printf("Capacity: %zu\n", xs.capacity);
  return 0;
};
