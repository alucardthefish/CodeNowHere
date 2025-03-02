!!cnh {"suffix":["agda", "lagda"]}
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

module hello where
  open import IO
  main = run (putStrLn "Hello, World!")
