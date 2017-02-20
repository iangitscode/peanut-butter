#include <SFML/Graphics.hpp>
//#include <unistd.h>
#include <iostream>
#include <vector>
#include "Object.h"
#include "Paddle.h"
#include <Windows.h>

extern std::vector<Object*> objects;
std::vector<Object*> objects;

void usleep(__int64 usec)
{
	HANDLE timer;
	LARGE_INTEGER ft;

	ft.QuadPart = -(10 * usec); // Convert to 100 nanosecond interval, negative value indicates relative time

	timer = CreateWaitableTimer(NULL, TRUE, NULL);
	SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
	WaitForSingleObject(timer, INFINITE);
	CloseHandle(timer);
}

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