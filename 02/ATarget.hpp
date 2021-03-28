# ifndef ATARGET_HPP
# define ATARGET_HPP
#include <string>
#include <iostream>

class ASpell;

class ATarget {
	private:
		std::string type;
	public:
		ATarget();
		ATarget(ATarget const& other);
		ATarget(std::string const &type);
		virtual	~ATarget();
		ATarget &operator=(ATarget const &other);

		std::string	const &getType() const;
		void	getHitBySpell(ASpell const &spell) const;
		virtual	ATarget	*clone() const = 0;
};

# include "ASpell.hpp"

#endif
