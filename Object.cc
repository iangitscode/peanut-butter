#include "Object.h"
#include <iostream>
Object::Object(std::string image, int x, int y):xPos{x},yPos{y},xVel{0},yVel{0}{
	objects.push_back(this);
	texture.loadFromFile(image);
	width=texture.getSize().x;
	height=texture.getSize().y;
	mySprite = new sf::Sprite(texture);
}

Object::~Object(){
	delete mySprite;
}

void Object::update(sf::RenderWindow& window){
	objectUpdate(); //do object specific update

	xPos+=xVel;
	yPos+=yVel;

	int l=objects.size();
	for(int y=0;y<l;y++){
		Object* other = objects[y];
    	if(this==other) continue; //don't want to check object against itself
    	if(this->xPos < other->xPos + other->width &&
		   this->xPos + this->width > other->xPos &&
		   this->yPos < other->yPos + other->height &&
		   this->height + this->yPos > other->yPos){
    	   //collision detected
    	   this->collisionDetected(other);
        }
    }
    mySprite->setPosition(xPos,yPos);
	window.draw(*mySprite);
}
void Object::moveObject(float x, float y){
	xPos=x;
	yPos=y;
}

void Object::scaleObject(float xFactor, float yFactor){
	mySprite->scale(xFactor,yFactor);
}