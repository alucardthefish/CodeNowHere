#include <string>
#include "../headers/injawrap.h"
#include "../headers/inja.hpp"
#include "injawrap.h"

InjaWrap::InjaWrap() {
    _env.set_trim_blocks(true);
    _env.set_lstrip_blocks(true);

    _env.add_callback("rpad", 2, [](inja::Arguments& args) {
        string str = args.at(0)->get<string>();
        int width = args.at(1)->get<int>();
        size_t len = str.length();
        size_t pad = width - len;
        return str + string(pad, ' ');
    });

    _env.add_callback("lpad", 2, [](inja::Arguments& args) {
		string str = args.at(0)->get<string>();
		int width = args.at(1)->get<int>();
		size_t len = str.length();
		size_t pad = width - len;
		return string(pad, ' ') +str;
	});

    _env.add_callback("center", 2, [](inja::Arguments& args) {
		string str = args.at(0)->get<string>();
		int width = args.at(1)->get<int>();
		size_t len = str.length();
		size_t pad = width - len;
		return string(pad / 2, ' ') + str + string(pad / 2, ' ');
	});
}

void InjaWrap::LoadJson(string_view fileName) {
    std::ifstream jf(fileName.data());
    _data = json::parse(jf);
}

void InjaWrap::SetValue(string_view name, string value) {
    _data[name] = value;
}

string InjaWrap::GetValue(string_view name)
{
    return _data[name];
}
string InjaWrap::RenderFile(const string& file) {
    auto result = _env.render_file(file, _data);
    return result;
}
