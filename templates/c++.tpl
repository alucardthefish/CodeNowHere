!!cnh {"suffix":["cc", "cpp", "cxx"]}
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

#include <iostream>

using namespace std;


int main(int argc, char * argv[]) {
    cout << "Hello World" << endl;
    return 0;
}
