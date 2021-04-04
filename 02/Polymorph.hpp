#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP
# include <iostream>
# include <string>
# include "ASpell.hpp"

class	Polymorph: public ASpell {
	private:
		std::string	name;
		std::string	effects;

	public:
		Polymorph();
		virtual	~Polymorph();
		
		virtual	ASpell	*clone() const;
};
#endif
