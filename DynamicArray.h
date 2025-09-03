#ifndef __DYNAMIC_ARRAY_H__
#define __DYNAMIC_ARRAY_H__

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define DA_INIT(TYPE, NAME) \
typedef struct { \
	TYPE   *array; \
	size_t length; \
} da_array_ ## NAME; \
\
static da_array_ ## NAME *da_new_ ## NAME (void) \
{ \
	return calloc(1, sizeof(da_array_ ## NAME)); \
} \
\
static void da_delete_ ## NAME (da_array_ ## NAME *obj) \
{ \
	free(obj->array); \
	free(obj); \
} \
\
static void da_append_ ## NAME (da_array_ ## NAME *obj, TYPE elem) \
{ \
	obj->array = realloc(obj->array, ++obj->length * sizeof(TYPE)); \
	obj->array[obj->length - 1] = elem; \
} \
\
static void da_remove_ ## NAME (da_array_ ## NAME *obj, TYPE elem) \
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

#endif/*__DYNAMIC_ARRAY_H__*/
