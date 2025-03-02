!!cnh {"suffix":"vb"}
' **************************************************************************************************************
' File: {{ cnh_file }}
' Author: {{ cnh_name }}
' Created: {{ cnh_date }}
{% if exists("cnh_has_copyright") %}
' {{ cnh_has_copyright }}
{% endif %}
{% if exists("cnh_description") %}
' Description: {{ cnh_description }}
{% endif %}
' **************************************************************************************************************


Imports System.Console

Class HelloWorld

    Public Shared Sub Main()
        WriteLine("Hello, world!")
    End Sub

End Class
