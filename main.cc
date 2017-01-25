#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <iostream>
#include <vector>
#include "Object.h"
#include "Paddle.h"

extern std::vector<Object*> objects;
std::vector<Object*> objects;

int main()
{
    int worldWidth=1000;
    int worldHeight=1000;
    sf::RenderWindow window(sf::VideoMode(worldWidth, worldHeight),"Game");
    
    Paddle* paddle = new Paddle("paddle.png");

    while (window.isOpen()){
        window.clear();
        //Update

        int l=objects.size();
        for(int x=0;x<l;x++){
            objects[x]->update(window);
        }

        //Update
        window.display();
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) window.close();
        } 
        usleep(10000);
    }

    int l=objects.size();
    for(int x=0;x<l;x++){
        delete objects[x];
    }
}