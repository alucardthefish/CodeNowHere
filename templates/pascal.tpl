!!cnh {"suffix":["pp", "pas", "inc"]}
(*
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
*)


program HelloWorld(output);
begin
  WriteLn('Hello World!');
end.
