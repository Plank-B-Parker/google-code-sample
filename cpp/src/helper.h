#pragma once

#include <string>
#include <vector>
#include <algorithm>

std::string trim(std::string s);

std::vector<std::string> splitlines(std::string output);

bool compareStringsCaseInsensitive(std::string a, std::string b);