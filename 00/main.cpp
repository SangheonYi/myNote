# include "Warlock.hpp"

int	main() {
	std::cout << "--- Constructors:\n";
	Warlock richard("Richard", "Master");
	std::cout << "--- Introduce:\n";
	richard.introduce();

	std::cout << "--- New Title:\n";
	richard.setTitle("no mmmmas");
	richard.introduce();

	std::cout << "--- Destructors:\n";
	return (0);
}
