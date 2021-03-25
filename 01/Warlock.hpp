# ifndef WARLOCK_HPP
# define WARLOCK_HPP
# include <string>
# include <iostream>
# include <vector>

class Warlock {
	private:
		std::string name;
		std::string title;
		std::vector	<ASpell*>	spells;

		Warlock();
		Warlock(Warlock const &other);
		Warlock &operator=(Warlock const &other);
	public:
		Warlock(std::string const &name, std::string const &title);
		virtual ~Warlock();
		std::string const &getName(void) const;
		std::string const &getTitle(void) const;
		
		void	setTitle(std::string const &title);
		void	introduce(void) const;
		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string const &name);
		void	launchSpell(std::string const &name, ATarget const &target);
};
# endif
