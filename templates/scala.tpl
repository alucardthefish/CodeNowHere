!!cnh {"suffix":["scala", "sc"]}
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


object HelloWorld {
   def main(args: Array[String]) {
      println("Hello, world!")
   }
}
