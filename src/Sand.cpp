#include "../Headers/Sand.h"
#include "../Headers/Grid.h"

Sand::Sand(sf::Vector2f pos, Grid* pG):
Element(1, 1, 1.4, pG)
{
    // Define an array of yellowish sand colors
    sf::Color sandColors[8] = {
        sf::Color(245, 222, 179), // Wheat
        sf::Color(240, 230, 140), // Khaki
        sf::Color(222, 205, 140), // Darker
        sf::Color(238, 232, 170), // PaleGoldenRod
        sf::Color(255, 233, 171), // Light Pale Yellow
    };

    // Randomly select a color from the array
    int colorIndex = rand() % 4;
    body.setFillColor(sandColors[colorIndex]);

    body.setPosition(pos);
}

Sand::~Sand()
{

}

void Sand::update(sf::Vector2i pos_grid)
{
    if(!hasMoved)
        pGrid->checkBelow(pos_grid);

    hasMoved = true;
}