!!cnh {"suffix":["erl", "ebin", "escript"]}
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


-module(prog).

-export([main/0]).

main() -> io:format("Hello world!~n").
