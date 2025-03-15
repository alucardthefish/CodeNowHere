!!cnh {"suffix":"es"}
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


if (typeof console === 'object') {
    console.log('Hello, World!');
} else if (typeof document === 'object') {
    document.write('Hello, World!');
} else {
    print('Hello, World!');
}
