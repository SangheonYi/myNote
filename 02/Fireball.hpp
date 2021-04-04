#ifndef FIREBALL_HPP
# define FIREBALL_HPP
# include <iostream>
# include <string>
# include "ASpell.hpp"

class	Fireball: public ASpell {
	private:
		std::string	name;
		std::string	effects;

	public:
		Fireball();
		virtual	~Fireball();
		
		virtual	ASpell	*clone() const;
};
#endif
