#pragma once
#include <vector>
#include <tuple>
#include <filesystem>
#include <optional>

#include "injawrap.h"

using std::vector;
using std::tuple;
using std::optional;

namespace fs = std::filesystem;

class CnhEngine {
    InjaWrap _inja;
    json _data;

public:
    void LoadDataValue(string_view name, string value);
    void LoadDataFile(string_view file);

    vector<string> RenderFile(const string& name);
    vector<tuple<fs::path, string>> FindTemplates(string_view fileName);
    bool IsFileExtensionTypeSupported(string ext);
};
