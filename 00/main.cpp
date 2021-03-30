#include "Warlock.hpp"

int main() {
	std::cout << "--- Constructors: \n";
	Warlock richard("Richard", "Master of the Universe");

	std::cout << "--- Introduce:\n";
	richard.introduce();

	std::cout << "--- New Title: \n";
	richard.setTitle("Master of the Earth");
	richard.introduce();

	std::cout << "--- Destructors: \n";
	return (0);
}
