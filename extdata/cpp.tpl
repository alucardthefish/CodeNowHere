!!cnh {"suffix":["cc", "cpp", "cxx"]} 
// **************************************************************************************************************
// File: {{ cnh_file }}
// Author: {{ cnh_name }}
// Created: {{ cnh_date }}
{% if exists("description") %}
// Description: {{ description }}
{% endif %}
// **************************************************************************************************************

#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {
    cout << "Hello World" << endl;
    return 0;
}
