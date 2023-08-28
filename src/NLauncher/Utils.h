#pragma once

#include <string>
#include <vector>
#include <Windows.h>

class Utils
{
public:
	Utils();
	std::string ReplaceAll(std::string, const std::string&, const std::string&);
	std::string join(const std::vector<std::string>&, const std::string&);
	std::vector<std::string> split(std::string, std::string);
	void startup(LPCSTR, LPSTR);
};

