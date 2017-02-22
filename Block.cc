#include "Block.h"
Block::Block(std::string image, bool movable, int x, int y) :Object{ image,movable,x,y } {
	this->xVel = -3;
	this->yVel = 0;
}

Block::~Block() {

}
void Block::objectUpdate() {

	if (this->xPos < 0) this->xPos = 850;		//resets back to front
}

void Block::collisionDetected(Object* other) {
}