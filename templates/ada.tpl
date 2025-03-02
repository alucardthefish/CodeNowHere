!!cnh {"suffix":["ada", "adb", "ads"]}
-- **************************************************************************************************************
-- File: {{ cnh_file }}
-- Author: {{ cnh_name }}
-- Created: {{ cnh_date }}
{% if exists("cnh_has_copyright") %}
-- {{ cnh_has_copyright }}
{% endif %}
{% if exists("cnh_description") %}
-- Description: {{ cnh_description }}
{% endif %}
-- **************************************************************************************************************

with Ada.Text_IO;

procedure main is
begin
    Ada.Text_IO.Put_Line("Hello World");
end main;
