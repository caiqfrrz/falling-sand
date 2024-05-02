#include "../Headers/Grid.h"

Grid::Grid()
{
    for(int i = 0; i < NUM_GRID; i++)
    {
        for(int j = 0; j< NUM_GRID; j++)
        {
            grid[i][j] = nullptr;
            privategrid[i][j] = 0;
        }
    }
}
Grid::~Grid()
{

}
void Grid::execute()
{
    for(int i = 0; i < NUM_GRID; i++)
    {
        for(int j = 0; j < NUM_GRID; j++)
        {
            if(privategrid[i][j] == 1)
            {
                grid[i][j]->update(sf::Vector2i(i, j));
            }
        }
    }

}
void Grid::draw(Graphic_Manager* pGM)
{
    for(int i = 0; i < NUM_GRID; i++)
    {
        for(int j = 0; j< NUM_GRID; j++)
        {
            if(grid[i][j] != nullptr)
            {
                grid[i][j]->update_pos(sf::Vector2i(i, j));
                pGM->draw(grid[i][j]);
                privategrid[i][j] = grid[i][j]->getId();
            }
            else
                privategrid[i][j] = 0;
            
        }
    }
    
}

void Grid::checkBelow(sf::Vector2i pos_grid)
{
    int i = pos_grid.x;
    int j = pos_grid.y;

    std::cout << "i: " << i << " j: " << j << std::endl;
    
    //If block below is empty, continue downwards
    if(privategrid[i][j + 1] == 0 && j < NUM_GRID - 30)
    {
        //Verifies blocks below to see if the element wouldn't pass right into another because of gravity (gravity makes the elements travel more than one block per frame)
        int k = 1;
        while(privategrid[i][j+k+1] == 0 && k <= grid[i][j]->getVel() && j+k < 170)
        {
            k++;
        }
        grid[i][j]->update_vel();
        grid[i][j + k] = grid[i][j];
        grid[i][j] = nullptr; 
    }
    //If block below isn`t empty, check diagonally
    else if(privategrid[i][j+1] != 0)
    {
        if(privategrid[i+1][j+1] == 0)
        {
            grid[i + 1][j + 1] = grid[i][j];
            grid[i][j] = nullptr;
        }
        else if(privategrid[i-1][j+1] == 0)
        {
            grid[i - 1][j + 1] = grid[i][j];
            grid[i][j] = nullptr;
        }                  
    }

}

void Grid::place(int id, sf::Vector2i position)
{
    if(id == 1)
    {
        Sand* new_sand = new Sand(sf::Vector2f(position.x * 4, position.y * 4));
        grid[position.x][position.y] = static_cast<Element*> (new_sand);
    }

    else if (id == 2)
    {
        //Water* new_water = new Water(sf::Vector2f(position.x * 4, position.y * 4));
        //grid[position.x][position.y] = static_cast<Element*> (new_water);
    }

}

