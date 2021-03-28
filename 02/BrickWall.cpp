#include "BrickWall.hpp"

BrickWall::BrickWall():
	ATarget("BrickWall practice") {}

BrickWall::~BrickWall() {}

ATarget BrickWall::*clone() const {
	return (new BrickWall(this*));
}

