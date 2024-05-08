#include <iostream>
#include <cmath>
#include "../Headers/World.h"

World::World():
pGM(Graphic_Manager::get_instance()),
radius(sf::Vector2f(NUM_GRID/2, NUM_GRID/2))
    {
        grid = Grid();
        execute();
    }

World::~World()
    {
        
    }

void World::execute()
{
    std::cout << "oiiii";
        while(pGM->iswindow_opened())
        {
            pGM->get_window()->clear();
            loop_event();
            grid.execute();
            grid.draw(pGM);
            radius.execute();


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
                
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    for(int i = 0; i < NUM_GRID; i++)
                    {
                        for(int j = 0; j < NUM_GRID; j++)
                        {
                            if(radius.verifiesInside(sf::Vector2f(i * 4, j * 4)))
                            {
                                grid.place(2, sf::Vector2i(i, j));
                            }
                        }
                    }
                }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                {
                    for(int i = 0; i < NUM_GRID; i++)
                    {
                        for(int j = 0; j < NUM_GRID; j++)
                        {
                            if(radius.verifiesInside(sf::Vector2f(i * 4, j * 4)))
                            {
                                grid.place(3, sf::Vector2i(i, j));
                            }
                        }
                    }
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                radius.sizeUp();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                radius.sizeDown();
            }
            
}