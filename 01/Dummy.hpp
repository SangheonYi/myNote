#ifndef DUMMY_HPP
# define DUMMY_HPP
# include <iostream>
# include <string>
# include "ATarget.hpp"

class	Dummy: public ATarget {
	private:
		std::string	name;
		std::string	effects;

	public:
		Dummy();
		virtual	~Dummy();
		
		virtual	ATarget	*clone() const;
};
#endif
