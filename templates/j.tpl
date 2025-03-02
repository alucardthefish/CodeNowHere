!!cnh {"suffix":["ijx", "ijs"]}
AB. **************************************************************************************************************
AB. File: {{ cnh_file }}
AB. Author: {{ cnh_name }}
AB. Created: {{ cnh_date }}
{% if exists("cnh_has_copyright") %}
AB. {{ cnh_has_copyright }}
{% endif %}
{% if exists("cnh_description") %}
AB. Description: {{ cnh_description }}
{% endif %}
AB. **************************************************************************************************************


load 'printf'
'' printf 'Hello, World!\n'
