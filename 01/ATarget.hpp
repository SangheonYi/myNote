# ifndef ATARGET_HPP
# define ATARGET_HPP
#include <string>
#include <iostream>

class ATarget {
	private:
		std::string type;
	public:
		ATarget();
		ATarget(ATarget const& other);
		ATarget(std::string const& type);
		virtual	~ATarget();
		ATarget &operater=(ATarget const& other);

		std::string	const& getType() const;
		void	getHitBtSpell(ASpell const& spell) const;
		virtual	ATarget	*clone() const = 0;
};
#endif
