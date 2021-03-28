# include "Warlock.hpp"
# include "Dummy.hpp"
# include "Fwoosh.hpp"

int	main() {
	std::cout << "--- Constructors:\n";
	Warlock richard("Richard", "Master");

	Fwoosh	*spell = new Fwoosh();
	Dummy	target;

	std::cout << "--- \"Fwoosh\" not learned:\n";

	richard.launchSpell("Fwoosh", target);

	std::cout << "--- \"Fwoosh\" learned:\n";

	richard.learnSpell(spell);
	richard.launchSpell("Fwoosh", target);

	std::cout << "--- Forgotten \"Fwoosh\":\n";

	richard.forgetSpell("Fwoosh");
	richard.launchSpell("Fwoosh", target);
	
	std::cout << "--- Non-existant spell :\n";

	richard.launchSpell("Splash", target);
	richard.forgetSpell("Splash");
	richard.launchSpell("Splash", target);
     

	std::cout << "--- Destructors:\n";
	return (0);
}
