!!cnh {"suffix":"zig"}

//**********************************************************************************************************
//File: {{ cnh_file }}
//Author: {{ cnh_name }}
//Created: {{ cnh_date }}
//{% if exists("cnh_has_copyright") %}
//{{ cnh_has_copyright }}
//{% endif %}
//{% if exists("cnh_description") %}
//Description: {{ cnh_description }}
//{% endif %}
//**********************************************************************************************************



const std = @import("std");

pub fn main() !void {
    std.debug.print("Hello, World!\n", .{});
}
