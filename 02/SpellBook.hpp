#ifndef SPELLBOOK_HPP 
# define SPELLBOOK_HPP
# include "ASpell.hpp"
# include <vector>

class SpellBook {
	private:
		std::vector<ASpell*> spells;
		SpellBook(SpellBook const &other);
		SpellBook	*operator=(SpellBook const &other);
	public:
		SpellBook();
		virtual	~SpellBook();

		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string const &spell);
		ASpell	*generateSpell(std::string const &spell);
};
#endif

