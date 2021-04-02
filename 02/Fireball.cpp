#include "Fireball.hpp"

Fireball::Fireball():
	ASpell("Fireball", "burn to a crisp") {}

Fireball::~Fireball() {}

ASpell	*Fireball::clone() const {
	return (new Fireball());
}
