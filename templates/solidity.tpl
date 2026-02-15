!!cnh {"suffix":["sol"]}
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

// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract HelloWorld {
    function helloWorld() public pure returns (string memory) {
        return "Hello World!";
    }
}
