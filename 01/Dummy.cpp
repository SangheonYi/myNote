#include "Dummy.hpp"

Dummy::Dummy():
	ATarget("Dummy practice") {}

Dummy::~Dummy() {}

ATarget	*Dummy::clone() const
{
	return (new Dummy(*this));
}
