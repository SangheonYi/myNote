#ifndef WARLOCK_HPP
# define WARLOCK_HPP
# include <iostream>
# include <string>

class	Warlock {
	private:
		std::string	name;
		std::string	title;

		Warlock();
		Warlock(Warlock const &other);
		Warlock	&operator=(Warlock const &other);
	public:
		Warlock(std::string name, std::string title);
		virtual	~Warlock();
		
		std::string	getName();
		std::string	getTitle();
		void	setTitle(std::string title);
		void	introduce();
};
#endif
