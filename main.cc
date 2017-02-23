#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#ifdef __linux__
#include <unistd.h>
#endif


#include "Object.h"
#include "Dino.h"
#include "Block.h"
#include "constants.h"

std::vector<Object*> objects;
int worldWidth;
int worldHeight;

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
	worldWidth=1500;
	worldHeight=500;
    Dino* dino = new Dino("dino.jpg", 0, 400);
	Block* block = new Block("block.png", worldWidth, 300);
    sf::RenderWindow window(sf::VideoMode(worldWidth, worldHeight),"Game");   

    while (window.isOpen()){
        window.clear();

        int l=objects.size();
        for(int x=0;x<l;x++){
            objects[x]->update(window);
        }

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