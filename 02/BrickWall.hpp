#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP
# include <iostream>
# include <string>
# include "ATarget.hpp"

class	BrickWall: public ATarget {
	private:
		std::string	name;
		std::string	effects;

	public:
		BrickWall();
		virtual	~BrickWall();
		
		virtual	ATarget	*clone() const;
};
#endif
