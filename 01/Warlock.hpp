#ifndef WARLOCK_HPP
# define WARLOCK_HPP
# include <iostream>
# include <string>
# include <vector>
# include "ATarget.hpp"
# include "ASpell.hpp"

class	Warlock {
	private:
		std::string	name;
		std::string	title;
		std::vector<ASpell*>	spells;

		Warlock();
		Warlock(Warlock const &other);
		Warlock	&operator=(Warlock const &other);
	public:
		Warlock(std::string name, std::string title);
		virtual	~Warlock();

		std::string	const &getName() const;
		std::string	const &getTitle() const;
		void	setTitle(std::string const &title);
		void	introduce() const;

		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string const &name);
		void	launchSpell(std::string const &name, ATarget const &target);
};
#endif
