#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	std::vector<ASpell*>::iterator ie = this->spells.end();
	for (std::vector<ASpell*>::iterator is = this->spells.begin(); is != ie; ++is)
	   delete *is;
	this->spells.clear();
}

void	SpellBook::learnSpell(ASpell *spell) {
	if (spell) {
		std::vector<ASpell*>::iterator ie = this->spells.end();
		for (std::vector<ASpell*>::iterator is = this->spells.begin(); is != ie; ++is)
		{
			if ((*is)->getName() == spell->getName())
				return ;
		}
		this->spells.push_back(spell->clone());
	}
}

void	SpellBook::forgetSpell(std::string const &spell) {
	std::vector<ASpell*>::iterator ie = this->spells.end();
	for (std::vector<ASpell*>::iterator is = this->spells.begin(); is != ie; ++is)
	{
		if ((*is)->getName() == spell)
		{
			delete *is;
			is = this->spells.erase(is);
		}
	}
}

ASpell	*SpellBook::generateSpell(std::string const &spell) {
	std::vector<ASpell*>::iterator ie = this->spells.end();
	for (std::vector<ASpell*>::iterator is = this->spells.begin(); is != ie; ++is)
	{
		if ((*is)->getName() == spell)
			return (*is);
	}
	return (NULL);
}


