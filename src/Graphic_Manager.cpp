#include "../Managers/Graphic_Manager.h"
#include <iostream>

#define WIDTH_WINDOW 800
#define HEIGHT_WINDOW 800

Graphic_Manager* Graphic_Manager::instance(nullptr);

Graphic_Manager::Graphic_Manager():
window(new sf::RenderWindow(sf::VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), "Falling Sand"))
{
    window->setFramerateLimit(60);
}
Graphic_Manager::~Graphic_Manager()
{
    delete window;
}

Graphic_Manager* Graphic_Manager::get_instance()
{
    if(!instance)
    {
        instance = new Graphic_Manager();
    }
    return instance;
}
const bool Graphic_Manager::iswindow_opened()
{
    if(window->isOpen())
    {
        return true;
    }
    else
        return false;
}
sf::RenderWindow* Graphic_Manager::get_window()
{
    return window;
}

void Graphic_Manager::draw(Element* el)
{
    if(el != nullptr)
    {
        window->draw(*(el->get_body()));
    }
}