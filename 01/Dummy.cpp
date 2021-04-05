#include "Dummy.hpp"
Dummy::Dummy():
	ATarget("Dummy Practice") {}

Dummy::~Dummy() {}

Dummy	*Dummy::clone() const {
	return (new Dummy(*this));
}
