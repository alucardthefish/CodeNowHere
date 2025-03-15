!!cnh {"suffix":["c", "cc"]}
// **************************************************************************************************************
// File: {{ cnh_file }}
// Author: {{ cnh_name }}
// Created: {{ cnh_date }}
{% if exists("cnh_has_copyright") %}
// {{ cnh_has_copyright }}
{% endif %}
{% if exists("cnh_description") %}
// Description: {{ cnh_description }}
{% endif %}
// **************************************************************************************************************

#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Hello World");
    return 0;
}
