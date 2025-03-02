!!cnh {"suffix":"ceylon"}
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


void hello(String? name) {
    if (exists name) {
        print("Hello, ``name``!");
    }
    else {
        print("Hello, world!");
    }
}
