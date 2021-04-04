#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title):
	name(name), title(title) {
	std::cout << getName() << ": What a boring day\n";
}

Warlock::~Warlock() {
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
