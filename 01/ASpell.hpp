#ifndef ASPELL_HPP
#define ASPELL_HPP
# include <iostream>
# include <string>

class ATarget;

class ASpell {
private:
	std::string name;
	std::string effects;
public:
	ASpell();
	ASpell(std::string const& name, std::string const& effects);
	virtual	~ASpell();
	ASpell(ASpell const & other);
	ASpell	&operator=(ASpell const& other);
	std::string const& getName() const;
	std::string const& getEffects() const;
	void	launch(ATarget const& target) const;
	virtual ASpell*	clone() const = 0;
};
# include "ATarget.hpp"
#endif
