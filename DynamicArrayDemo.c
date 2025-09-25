#include "DynamicArray.h"
#include <stdio.h>

DA_INIT(int, int)
DA_INIT(int *, intptr)

int main(void)
{
	da_array_int *array;

	array = da_new_int();
	da_append_int(array, 7);
	printf("array[0] = %d, length = %ld\n", array->array[0], array->length);
	da_remove_int(array, 7);
	printf("length = %ld\n", array->length);
	da_delete_int(array);

	da_array_intptr *arrayptr;
	int a = 512;
	int b = 64;

	arrayptr = da_new_intptr();
	da_append_intptr(arrayptr, &a);
	printf("array[0] = %d, length = %ld\n", *arrayptr->array[0], arrayptr->length);
	da_append_intptr(arrayptr, &b);
	printf("array[0] = %d, array[1] = %d, length = %ld\n", *arrayptr->array[0], *arrayptr->array[1], arrayptr->length);
	da_remove_intptr(arrayptr, &a);
	printf("array[0] = %d, length = %ld\n", *arrayptr->array[0], arrayptr->length);
	da_delete_intptr(arrayptr);
	
	return 0;
}
