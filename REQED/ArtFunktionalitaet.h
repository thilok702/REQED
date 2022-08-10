#pragma once
#include <string>

enum ArtFunktionalitaet {
	Systemaktivitaet, Benutzerinteraktion, Schnittstellenanforderung
};

static std::string funktionalitaetToString(ArtFunktionalitaet funk) {
	switch(funk) {
	case Benutzerinteraktion:
		return "dem/der Benutzer/-in die Möglichkeit bieten";
	case Schnittstellenanforderung:
		return "fähig sein";
	}
	return "";
}

static std::string funktionalitaetToNumber(ArtFunktionalitaet funk) {
	switch (funk) {
	case Benutzerinteraktion:
		return "1";
	case Schnittstellenanforderung:
		return "2";
	case Systemaktivitaet:
		return "0";
	}
	return "";
}

static ArtFunktionalitaet getFunktionalitaet(std::string funkt) {
	if(funkt == "Systemaktivität") {
		return ArtFunktionalitaet::Systemaktivitaet;
	} else if(funkt == "Benutzerinteraktion") {
		return ArtFunktionalitaet::Benutzerinteraktion;
	} else {
		return ArtFunktionalitaet::Schnittstellenanforderung;
	}
}