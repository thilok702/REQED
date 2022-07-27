#pragma once
#include <string>

enum Verbindlichkeit {
	sollte, muss, wird
};

std::string verbindlichkeitToString(Verbindlichkeit verb) {
	switch(verb) {
	case muss:
		return "muss";
	case sollte:
		return "soltte";
	case wird:
		return "wird";
	}
	return "";
}