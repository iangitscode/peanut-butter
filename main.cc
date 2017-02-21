#include <SFML/Graphics.hpp>

#ifdef __linux__
#include <unistd.h>
#endif

#include <iostream>
#include <vector>
#include "Object.h"
#include "Dino.h"
#include "Block.h"

extern std::vector<Object*> objects;
std::vector<Object*> objects;

#ifdef _WIN32
#include <Windows.h>
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
#endif

int main()
{
    int worldWidth=1000;
    int worldHeight=1000;
    
    Dino* dino = new Dino("dino.jpg", 100, 100);
	Block* block = new Block("block.png", 850, 300);
    sf::RenderWindow window(sf::VideoMode(worldWidth, worldHeight),"Game");   

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