#ifndef FWOOSH_HPP
# define FWOOSH_HPP
# include <iostream>
# include <string>
# include "ASpell.hpp"

class	Fwoosh: public ASpell {
	private:
		std::string	name;
		std::string	effects;

	public:
		Fwoosh();
		virtual	~Fwoosh();
		
		virtual	ASpell	*clone() const;
};
#endif
