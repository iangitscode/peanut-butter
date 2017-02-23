#ifndef _OBJECT_H_
#define _OBJECT_H_
#include <string>
#include "constants.h"
#include <SFML/Graphics.hpp>

class Object{
	sf::Sprite* mySprite;
	sf::Texture texture;
	public:
		int width, height, xPos, yPos, xVel, yVel, xAcc, yAcc;
		Object(std::string, int, int);
		virtual ~Object() = 0;
		void update(sf::RenderWindow&); //Basic updating for every object - physics, drawing
		virtual void objectUpdate() = 0; //Specific updating for each object
		virtual void collisionDetected(Object*) = 0;
		void moveObject(float,float);
		void scaleSize(float,float);
		void setSize(float, float);
};

extern std::vector<Object*> objects;
#endif