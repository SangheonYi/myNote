#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title):
	name(name), title(title) {
	std::cout << getName() << ": What a boring day\n";
}

Warlock::~Warlock() {
	std::vector<ASpell*>::iterator	ite = this->spells.end();
	for (std::vector<ASpell*>::iterator	it = this->spells.begin(); it != ite; it++)
		delete *it;
	this->spells.clear();
	std::cout << getName() << ": My job here is done!\n";
}

std::string	const &Warlock::getName() const {
	return (this->name);
}

std::string	const &Warlock::getTitle() const {
	return (this->title);
}

void	Warlock::setTitle(std::string const &title) {
	this->title = title;
}

void	Warlock::introduce() const {
	std::cout << getName() << ": My name is " << getName() << ", " << getTitle() << "!\n";
}

void	Warlock::learnSpell(ASpell *spell) {
	if (spell) {
		std::vector<ASpell*>::iterator	ite = this->spells.end();
		for (std::vector<ASpell*>::iterator	it = this->spells.begin(); it != ite; it++) {
			if ((*it)->getName() == spell->getName())
				return ;
		}
		this->spells.push_back(spell->clone());
	}
}

void	Warlock::forgetSpell(std::string const &name) {
	std::vector<ASpell*>::iterator	ite = this->spells.end();
	for (std::vector<ASpell*>::iterator	it = this->spells.begin(); it != ite; it++) {
		if ((*it)->getName() == name)
		{
			delete *it;
			it = this->spells.erase(it);
		}
	}
}
void	Warlock::launchSpell(std::string const &name, ATarget const &target) {
	std::vector<ASpell*>::iterator	ite = this->spells.end();
	for (std::vector<ASpell*>::iterator	it = this->spells.begin(); it != ite; it++) {
		if ((*it)->getName() == name)
			(*it)->launch(target);
	}
}
