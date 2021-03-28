#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
	std::vector<ATarget*>::iterator ie = this->targets.end();
	for (std::vector<ATarget*>::iterator i = this->targets.begin();i != ie; i++)
		delete *i;
	this->targets.clear();
}

void	TargetGenerator::learnTargetType(ATarget *target) {
	if (type)
	{
		std::vector<ATarget*>::iterator ie = this->targets.end();
		for (std::vector<ATarget*>::iterator i = this->targets.begin();i != ie; i++)
		{
			if ((*i)->getType() == target->getType())
				return ;
		}
		this->targets.push_back(target->clone());
	}
}

void	TargetGenerator::forgetTargetType(std::string const &type)
	std::vector<ATarget*>::iterator ie = this->targets.end();
	for (std::vector<ATarget*>::iterator i = this->targets.begin();i != ie; i++)
	{
		if ((*i)->getType() == type)
		{
			delete *i;
			i = this->targets.erase(i);
		}
	}
}

ATarget	TargetGenerator::*createTarget(std::string const &type) {
	std::vector<ATarget*>::iterator ie = this->targets.end();
	for (std::vector<ATarget*>::iterator i = this->targets.begin();i != ie; i++)
	{
		if ((*i)->getType() == type)
		{
			return (*i);
		}
	}
	return (NULL);
}
