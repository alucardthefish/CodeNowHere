!!cnh {"suffix":"cs"}
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

using System;

class HelloWorld
{
    public static void Main(string[] args)
    {
        Console.WriteLine("Hello, world!");
    }
}
