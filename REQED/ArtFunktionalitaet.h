#pragma once
#include <string>

enum ArtFunktionalitaet {
	Systemaktivitaet, Benutzerinteraktion, Schnittstellenanforderung
};

std::string funktionalitaetToString(ArtFunktionalitaet funk) {
	switch(funk) {
	case Benutzerinteraktion:
		return "dem/der Benutzer/-in die M�glichkeit bieten";
	case Schnittstellenanforderung:
		return "f�hig sein";
	}
	return "";
}