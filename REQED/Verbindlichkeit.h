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

static std::string verbindlichkeitToNumber(Verbindlichkeit verb) {
	switch (verb) {
	case muss:
		return "0";
	case sollte:
		return "1";
	case wird:
		return "2";
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

static Verbindlichkeit getVerbindlichkeitfromnumber(std::string verb) {
	if (verb == "0") {
		return Verbindlichkeit::muss;
	}
	else if (verb == "1") {
		return Verbindlichkeit::sollte;
	}
	else {
		return Verbindlichkeit::wird;
	}
}