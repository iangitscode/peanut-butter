#include "Block.h"
#include "constants.h"
Block::Block(std::string image, int x, int y):Object{image,x,y}{
	this->xVel = -3;
	this->yVel = 0;
}

Block::~Block() {

}
void Block::objectUpdate() {

	if (this->xPos < 0) this->xPos = worldWidth;		//resets back to front
}

void Block::collisionDetected(Object* other) {
}