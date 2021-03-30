#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title):
	name(name), title(title)
{
	std::cout << this->name << ": What a boring day\n";
}

Warlock::~Warlock(void) {
	std::cout << this->name << ": My job here is done!\n";
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

void	Warlock::learnSpell(ASpell *spell) {
		this->spellBook.learnSpell(spell);
}

void	Warlock::forgetSpell(std::string const &name)
{
	this->spellBook.forgetSpell(name);
}

void	Warlock::launchSpell(std::string const &name, ATarget const &target) {
	ASpell *spell = this->spellBook.generateSpell(name);
	if (spell)
		spell->launch(target);
}
