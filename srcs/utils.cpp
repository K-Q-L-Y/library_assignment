#include "utils.hpp"

bool startswith(string s, string tofind) {
	if (tofind.length() > s.length())
		return false;
	for (int i = 0; i < tofind.length(); ++i) {
		if (tolower(s[i]) != tolower(tofind[i]))
			return false;
	}
	return true;
}

bool is_alpha(const string &s) {
	for (const char &c : s) {
		if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z'))
			return false;
	}
	return true;
}

bool is_numeric(const string &s) {
	for (const char &c : s) {
		if (!(c >= '0' && c <= '9'))
			return false;
	}
	return true;
}