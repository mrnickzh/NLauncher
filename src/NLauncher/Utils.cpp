#include "Utils.h"

Utils::Utils() {

};

std::string Utils::ReplaceAll(std::string str, const std::string& from, const std::string& to) {
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
	return str;
};

std::string Utils::join(const std::vector<std::string>& sequence, const std::string& separator)
{
	std::string result;
	for (size_t i = 0; i < sequence.size(); ++i)
		result += sequence[i] + ((i != sequence.size() - 1) ? separator : "");
	return result;
};

std::vector<std::string> Utils::split(std::string s, std::string del = " ")
{
	int start = 0;
	int end = s.find(del);
	std::vector<std::string> list;
	while (end != -1) {
		list.push_back(s.substr(start, end - start));
		start = end + del.size();
		end = s.find(del, start);
	}
	list.push_back(s.substr(start, end - start));
	return list;
};

void Utils::startup(LPCSTR lpApplicationName, LPSTR lpArgs)
{
	STARTUPINFOA si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	CreateProcessA
	(
		lpApplicationName,
		lpArgs,
		NULL,
		NULL,
		FALSE,
		NULL,
		NULL,
		NULL,
		&si,
		&pi
	);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
};
