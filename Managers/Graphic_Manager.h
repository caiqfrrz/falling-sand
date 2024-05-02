#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window/Mouse.hpp>

#include "../Headers/Element.h"

class Graphic_Manager
{
private:
    sf::RenderWindow* window;
    static Graphic_Manager* instance;
    Graphic_Manager();
public:
    ~Graphic_Manager();
    static Graphic_Manager* get_instance();
    const bool iswindow_opened() const;
    sf::RenderWindow* get_window();
    void draw(Element* el);
};