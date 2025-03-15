!!cnh {"suffix":["h", "hh", "hpp", "hxx", "h++"]}
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

#ifndef MYHEADER_H
#define MYHEADER_H

void sayHelloWorld();

#endif
