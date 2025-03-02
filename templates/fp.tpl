!!cnh {"suffix":"fp"}
% **************************************************************************************************************
% File: {{ cnh_file }}
% Author: {{ cnh_name }}
% Created: {{ cnh_date }}
{% if exists("cnh_has_copyright") %}
% {{ cnh_has_copyright }}
{% endif %}
{% if exists("cnh_description") %}
% Description: {{ cnh_description }}
{% endif %}
% **************************************************************************************************************


main = emit.(return ~"Hello, World!\n")
