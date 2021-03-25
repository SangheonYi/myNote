# include "ASpell.hpp"

ASpell::ASpell():
	name(), effects() {}

ASpell::ASpell(std::string const& name, std::string const& effects):
	name(name), effects(effects)
{}

ASpell::ASpell(ASpell const& other):
	name(other.name), effects(other.effects)
{}

ASpell::~ASpell() {}

ASpell &ASpell::operater=(ASpell const& other)
{
	this->name = other.name;
	this->effects = other.effects;
	return (*this);
}

std::string	const &ASpell::getName() const
{
	return (this->name);
}

std::string	const &ASpell::getEffects() const
{
	return (this->Effects);
}

void	ASpell::launch(ATarget const& target) {
	target.getHitBySpell(*this);
}
