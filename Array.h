#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_INIT_TYPE(TYPE, NAME) \
typedef struct { \
	TYPE   *array; \
	size_t length; \
} Array_ ## NAME ## _t;

#define ARRAY_INIT_NEW(TYPE, NAME) \
static Array_ ## NAME ## _t *Array_new_ ## NAME (void) \
{ \
	return calloc(1, sizeof(Array_ ## NAME ## _t)); \
}

#define ARRAY_INIT_DELETE(TYPE, NAME) \
static void Array_delete_ ## NAME (Array_ ## NAME ## _t *obj) \
{ \
	free(obj->array); \
	free(obj); \
}

#define ARRAY_INIT_APPEND(TYPE, NAME) \
static void Array_append_ ## NAME (Array_ ## NAME ## _t *obj, TYPE elem) \
{ \
	obj->array = realloc(obj->array, ++obj->length * sizeof(TYPE)); \
	obj->array[obj->length - 1] = elem; \
}

#define ARRAY_INIT_REMOVE(TYPE, NAME) \
static void Array_remove_ ## NAME (Array_ ## NAME ## _t *obj, TYPE elem) \
{ \
	for (size_t i = 0; i < obj->length; ++i) \
	{ \
		if (memcmp(&obj->array[i], &elem, sizeof(TYPE)) == 0) \
		{ \
			if (i < --obj->length) \
				memmove(&obj->array[i], &obj->array[i + 1], (obj->length - i) * sizeof(TYPE)); \
			obj->array = realloc(obj->array, obj->length * sizeof(TYPE)); \
			break; \
		} \
	} \
}

#define ARRAY_INIT_DUMP0(TYPE, NAME) \
static TYPE *Array_dump0_ ## NAME (Array_ ## NAME ## _t *obj) \
{ \
	TYPE *dump = calloc(obj->length + 1, sizeof(TYPE)); \
	memcpy(dump, obj->array, obj->length * sizeof(TYPE)); \
	return dump; \
}

#define ARRAY_INIT_INSERT(TYPE, NAME) \
static void Array_insert_ ## NAME (Array_ ## NAME ## _t *obj, size_t index, TYPE elem) \
{ \
	assert(index <= obj->length); \
	obj->array = realloc(obj->array, ++obj->length * sizeof(TYPE)); \
	if (index < obj->length - 1) \
		memmove(&obj->array[index + 1], &obj->array[index], (obj->length - (index + 1)) * sizeof(TYPE)); \
	obj->array[index] = elem; \
}

#define ARRAY_INIT_POP(TYPE, NAME) \
static TYPE Array_pop_ ## NAME (Array_ ## NAME ## _t *obj, size_t index) \
{ \
	assert(index < obj->length); \
	TYPE elem = obj->array[index]; \
	if (index < --obj->length) \
		memmove(&obj->array[index], &obj->array[index + 1], (obj->length - index) * sizeof(TYPE)); \
	obj->array = realloc(obj->array, obj->length * sizeof(TYPE)); \
	return elem; \
}

#endif/*__ARRAY_H__*/
