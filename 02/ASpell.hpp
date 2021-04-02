#ifndef ASPELL_HPP
# define ASPELL_HPP
# include <string>
# include <iostream>

class	ATarget;

class	ASpell {
	private:
		std::string name;
		std::strung effects;
	public:
		ASpell();
		~ASpell();
		ASpell(ASpell const &other);
		ASpell	&operator=(ASpell const &other);

		ASpell(std::string const &name, std::string const &effects);

		std::string const &getName() const;
		std::string const &getEffects() const;
		void	launch(ATarget const &target) const;
		virtual ASpell	*clone() const = 0;
};
#endif

# include "ATarget.hpp"
