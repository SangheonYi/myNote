#ifndef ATARGET_HPP
# define ATARGET_HPP
# include <iostream>
# include <string>

class	ASpell;

class	ATarget {
	private:
		std::string	type;
		std::string	effects;

	public:
		ATarget();
		ATarget(ATarget const &other);
		ATarget(std::string const &type);
		virtual	~ATarget();
		ATarget	&operator=(ATarget const &other);

		std::string	const &getType() const;
		std::string	const &getEffects() const;
		void	getHitBySpell(ASpell const &spell) const;
		virtual	ATarget	*clone() const = 0;
};
# include "ASpell.hpp"
#endif
