!!cnh {"suffix":["f", "for", "f90", "f95", "f03"]}
! **************************************************************************************************************
! File: {{ cnh_file }}
! Author: {{ cnh_name }}
! Created: {{ cnh_date }}
{% if exists("cnh_has_copyright") %}
! {{ cnh_has_copyright }}
{% endif %}
{% if exists("cnh_description") %}
! Description: {{ cnh_description }}
{% endif %}
! **************************************************************************************************************


program hello
  print *, "Hello World!"
end program hello
