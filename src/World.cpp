#include <iostream>
#include <cmath>
#include "../Headers/World.h"

World::World():
pGM(Graphic_Manager::get_instance())
    {
        //newdwdw.setSize(sf::Vector2f(30, 30));
       // newdwdw.setPosition(sf::Vector2f(200, 300));
       // newdwdw.setFillColor(sf::Color::White);
        grid = Grid();
        execute();
    }

World::~World()
    {
        
    }

void World::execute()
{
        while(pGM->iswindow_opened())
        {
            pGM->get_window()->clear();
            loop_event();
            grid.execute();
            grid.draw(pGM);


            pGM->get_window()->display();
        }
}
void World::loop_event()
{
    sf::Event event;

            while(pGM->get_window()->pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    pGM->get_window()->close();

            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::Vector2i localPosition = sf::Mouse::getPosition(*(pGM->get_window()));

                    int gridX = floor(localPosition.x / 4);
				    int gridY = floor(localPosition.y / 4);
                    grid.place(1, sf::Vector2i(gridX, gridY));
                }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    sf::Vector2i localPosition = sf::Mouse::getPosition(*(pGM->get_window()));

                    int gridX = floor(localPosition.x / 4);
				    int gridY = floor(localPosition.y / 4);

                    grid.place(2, sf::Vector2i(gridX, gridY));
                }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(*(pGM->get_window()));

                    int gridX = floor(localPosition.x / 4);
				    int gridY = floor(localPosition.y / 4);

                grid.place(3, sf::Vector2i(gridX, gridY));
            }
            
}