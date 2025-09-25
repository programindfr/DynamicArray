#include "Array.h"
#include <stdio.h>

ARRAY_INIT_TYPE(char, char)
ARRAY_INIT_NEW(char, char)
ARRAY_INIT_DELETE(char, char)
ARRAY_INIT_APPEND(char, char)
ARRAY_INIT_REMOVE(char, char)
ARRAY_INIT_DUMP0(char, char)
ARRAY_INIT_INSERT(char, char)
ARRAY_INIT_POP(char, char)

ARRAY_INIT_TYPE(char *, charptr)
ARRAY_INIT_NEW(char *, charptr)
ARRAY_INIT_DELETE(char *, charptr)
ARRAY_INIT_APPEND(char *, charptr)
ARRAY_INIT_REMOVE(char *, charptr)
ARRAY_INIT_DUMP0(char *, charptr)
ARRAY_INIT_INSERT(char *, charptr)
ARRAY_INIT_POP(char *, charptr)

int main(void)
{
	char c;
	char *p;
	char *cd;
	char **pd;
	Array_char_t *buf;
	Array_charptr_t *str;

	buf = Array_new_char();
	str = Array_new_charptr();

	Array_append_char(buf,'h');
	Array_append_charptr(str, "hello");
	
	Array_insert_char(buf, 0, 'w');
	Array_insert_charptr(str, 0, "world");

	printf("%c, %c\n", buf->array[0], buf->array[1]);
	printf("%s, %s\n", str->array[0], str->array[1]);

	cd = Array_dump0_char(buf);
	pd = Array_dump0_charptr(str);

	c = Array_pop_char(buf, 0);
	p = Array_pop_charptr(str, 0);
	
	printf("%c\n", c);
	printf("%s\n", p);
	
	Array_remove_char(buf, 'h');
	Array_remove_charptr(str, "hello");

	printf("%ld\n", buf->length);
	printf("%ld\n", str->length);

	Array_delete_char(buf);
	Array_delete_charptr(str);

	printf("%s\n", cd);
	printf("%s, %s\n", pd[0], pd[1]);

	free(cd);
	free(pd);
	
	return 0;
}
