!!cnh {"suffix":["q", "qm", "qtest"]}
# **************************************************************************************************************
# File: {{ cnh_file }}
# Author: {{ cnh_name }}
# Created: {{ cnh_date }}
{% if exists("cnh_has_copyright") %}
% {{ cnh_has_copyright }}
{% endif %}
{% if exists("cnh_description") %}
# Description: {{ cnh_description }}
{% endif %}
# **************************************************************************************************************


class HelloWorld
{
    constructor()
    {
        background $.output("Hello, world!");
    }
    output($arg)
    {
        printf("%s\n", $arg);
    }
}

new HelloWorld();
