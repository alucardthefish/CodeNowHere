!!cnh {"suffix":"unknown_ext_type"}
{% if exists("cnh_comment") and not exists("cnh_comment_closure") %}
{{ cnh_comment }} **************************************************************************************************************
{{ cnh_comment }} File: {{ cnh_file }}
{{ cnh_comment }} Author: {{ cnh_name }}
{{ cnh_comment }} Created: {{ cnh_date }}
{% if exists("cnh_has_copyright") %}
{{ cnh_comment }} {{ cnh_has_copyright }}
{% endif %}
{% if exists("cnh_description") %}
{{ cnh_comment }} Description: {{ cnh_description }}
{% endif %}
{{ cnh_comment }} **************************************************************************************************************
{% else %}
    {% if exists("cnh_comment") and exists("cnh_comment_closure") %}
{{ cnh_comment }}
**************************************************************************************************************
File: {{ cnh_file }}
Author: {{ cnh_name }}
Created: {{ cnh_date }}
{% if exists("cnh_has_copyright") %}
{{ cnh_has_copyright }}
{% endif %}
{% if exists("cnh_description") %}
Description: {{ cnh_description }}
{% endif %}
**************************************************************************************************************
{{ cnh_comment_closure }}
    {% else %}
        {# Do something else if neither condition is met #}
    {% endif %}
{% endif %}

Start your coding!
