#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title):
	name(name), title(title) {
	std::cout << getName() << ": What a boring day\n";
}

Warlock::~Warlock() {
	std::cout << getName() << ": My job here is done!\n";
}

std::string	const &Warlock::getName() {
	return(this->name);
}

std::string	const &Warlock::getTitle() {
	return(this->title);
}

void	Warlock::setTitle(std::string const &title) {
	this->title = title;
}

void	Warlock::introduce() {
	std::cout << getName() << ": My name is " << getName() << ", " << getTitle() << "!\n";
}
