!!cnh {"suffix":["cfm", "cfml", "cfc"]}
<!---
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
--->


<cfscript>
    function Main() {
        var msg = "Hello World";
        return msg;
    }
</cfscript>
