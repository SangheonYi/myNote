#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP
# include <string>
# include <vector>
# include "ATarget.hpp"

class	TargetGenerator {
	private:
		std::vector<ATarget *>	targets;
		TargetGenerator(TargetGenerator const &other);
		TargetGenerator	&operator=(TargetGenerator const &other);
	public:
		TargetGenerator();
		virtual	~TargetGenerator();

		void	learnTargetType(ATarget *target);
		void	forgetTarget(std::string const &type);
		ATarget	*createTarget(std::string const &type);
};
#endif
