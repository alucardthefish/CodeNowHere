!!cnh {"suffix":"a"}
/*
**************************************************************************************************************
File: {{ cnh_file }}
Author: {{ cnh_name }}
Created: {{ cnh_date }}
{% if exists("cnh_has_copyright") %}
{{ cnh_has_copyright }}
{% endif %}
{% if exists("cnh_description") %}
Description: {{ cnh_description }}
{% endif %}
**************************************************************************************************************
*/


#include <alef.h>

void
receive(chan(byte*) c)
{
	byte *s;
	s = <-c;
	print("%s\n", s);
	terminate(nil);
}

void
main(void)
{
	chan(byte*) c;
	alloc c;
	proc receive(c);
	c <-= "Hello, World!";
	terminate(nil);
}
