# ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP
# include "ATarget.hpp"
# include <vector>

class TargetGenerator {
private:
	std::vector<ATarget*> targets;
public:
	TargetGenerator();
	virtual ~TargetGenerator();

	void	learnTargetType(ATarget *target);
	void	forgetTargetType(std::string const &type);
	ATarget	*createTarget(std::string const &type);
};
# endif
