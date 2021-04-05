#include "Polymorph.hpp"
Polymorph::Polymorph():
	ASpell("Polymorph", "turned to a sheep") {}

Polymorph::~Polymorph() {}

Polymorph	*Polymorph::clone() const {
	return (new Polymorph(*this));
}
