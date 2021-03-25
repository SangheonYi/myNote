#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title):
	name(name), title(title)
{
	std::cout << this->name << ": What a boring day\n";
}

Warlock::~Warlock(void) {
	std::cout << this->name << ": My job here is done!\n";
	std::vector<ASpell*>::iterator ie = this->spells.end();
	for (std::vector<ASpell*>::iterator is = this->spells.begin(); is != ie; ++is)
	   delete *is;
	this->spells.clear();	
}

std::string const & Warlock::getName() const
{
	return (this->name);
}
std::string const & Warlock::getTitle() const
{
	return (this->title);
}

void Warlock::setTitle(std::string const &title)
{
	this->title = title;
}

void Warlock::introduce(void) const
{
	std::cout << this->name << ":my name is " << this->name << ", " << this->title << "!\n";
}

void	learnSpell(ASpell *spell) {
	if (spell) {
		std::vector<ASpell*>::iterator ie = this->spells.end();
		for (std::vector<ASpell*>::iterator is = this->spells.begin(); is != ie; is++)
		   if ((*is)->getName() == spell->getName())
			   return;
		this->spells.push_back(spell->clone());
	}
}

void	forgetSpell(std::string const &name)
{
	std::vector<ASpell*>::iterator ie = this->spells.end();
	for (std::vector<ASpell*>::iterator is = this->spells.begin(); is != ie; is++)
	{
		if ((*is)->getName() == name) {
			delete *is;
			is = this->spells.erase(is);
		}
	}
}

void	launchSpell(std::string const &name, ATarget const &target) {
	std::vector<ASpell*>::iterator ie = this->spells.end();
	for (std::vector<ASpell*>::iterator is = this->spells.begin(); is != ie; is++)
	{
		if ((*is)->getName() == name)
		{
			(*is)->launch(target);
			return ;
		}
	}
}
