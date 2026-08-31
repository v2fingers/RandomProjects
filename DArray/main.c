#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  void *data;
  int size;
  int capacity;
  size_t element_size;
} DArray;

// Initialize the array
void initArray(DArray *array, int initialCapacity, size_t elementSize) {
  array->data = malloc(initialCapacity * elementSize);
  array->size = 0;
  array->capacity = initialCapacity;
  array->element_size = elementSize;
}

// Add an element, growing the array if necessary
void insertElement(DArray *array, void *element) {
  if (array->size == array->capacity) {
    array->capacity *= 2;

    void *temp = realloc(array->data, array->capacity * array->element_size);

    if (temp == NULL) {
      printf("Memory reallocation failed!\n");
      return;
    }

    array->data = temp;
  }

  // Find the address of the next element
  void *destination = (char *)array->data + array->size * array->element_size;

  // Copy the element into the array
  memcpy(destination, element, array->element_size);

  array->size++;
}

// Get an element by index
void *getElement(DArray *array, int index) {
  return (char *)array->data + index * array->element_size;
}

// Clean up memory
void freeArray(DArray *array) {
  free(array->data);

  array->data = NULL;
  array->size = 0;
  array->capacity = 0;
  array->element_size = 0;
}

int main() {
  DArray arr;

  // Tell the array that it will contain ints
  initArray(&arr, 2, sizeof(int));

  // Insert 5 integers
  for (int i = 1; i <= 10; i++) {
    int value = i * 100;
    insertElement(&arr, &value);
  }

  printf("Array Size: %d, Capacity: %d, Element Size: %zu\n", arr.size,
         arr.capacity, arr.element_size);

  // Read the elements
  for (int i = 0; i < arr.size; i++) {
    int *value = (int *)getElement(&arr, i);
    printf("%d \n", *value);
  }

  void *num = getElement(&arr, 9);
  printf("Element 3: %d\n", *(int *)num);

  freeArray(&arr);

  return 0;
}
