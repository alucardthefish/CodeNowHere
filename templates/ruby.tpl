!!cnh {"suffix":["rb", "rbw"]}
# **************************************************************************************************************
# File: {{ cnh_file }}
# Author: {{ cnh_name }}
# Created: {{ cnh_date }}
{% if exists("cnh_has_copyright") %}
# {{ cnh_has_copyright }}
{% endif %}
{% if exists("cnh_description") %}
# Description: {{ cnh_description }}
{% endif %}
# **************************************************************************************************************


def print_hello
    puts "Hello World"
end
