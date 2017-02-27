#include "Block.h"
Block::Block(std::string image, int x, int y):Object{image,x,y}{
	srand(time(NULL));
	this->xVel = -10;
	this->yVel = 0;
}

Block::~Block() {

}

void Block::objectUpdate() {

	if (this->xPos < 0){
		this->xPos = worldWidth + rand()%1500;		//resets back to front
		this->xVel = -((rand()%10)+10); 
	}
}

void Block::collisionDetected(Object* other){
	std::cout<<"Hit"<<std::endl;
}