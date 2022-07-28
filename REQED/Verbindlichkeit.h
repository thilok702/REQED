#pragma once
#include <string>

enum Verbindlichkeit {
	sollte, muss, wird
};

static std::string verbindlichkeitToString(Verbindlichkeit verb) {
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

static Verbindlichkeit getVerbindlichkeit(std::string verb) {
	if(verb == "muss") {
		return Verbindlichkeit::muss;
	} else if(verb == "sollte") {
		return Verbindlichkeit::sollte;
	} else {
		return Verbindlichkeit::wird;
	}
}