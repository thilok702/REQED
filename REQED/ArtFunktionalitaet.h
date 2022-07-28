#pragma once
#include <string>

enum ArtFunktionalitaet {
	Systemaktivitaet, Benutzerinteraktion, Schnittstellenanforderung
};

static std::string funktionalitaetToString(ArtFunktionalitaet funk) {
	switch(funk) {
	case Benutzerinteraktion:
		return "dem/der Benutzer/-in die M�glichkeit bieten";
	case Schnittstellenanforderung:
		return "f�hig sein";
	}
	return "";
}


static ArtFunktionalitaet getFunktionalitaet(std::string funkt) {
	if(funkt == "Systemaktivit�t") {
		return ArtFunktionalitaet::Systemaktivitaet;
	} else if(funkt == "Benutzerinteraktion") {
		return ArtFunktionalitaet::Benutzerinteraktion;
	} else {
		return ArtFunktionalitaet::Schnittstellenanforderung;
	}
}