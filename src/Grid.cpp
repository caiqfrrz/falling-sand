#include "../Headers/Grid.h"

Grid::Grid()
{
    std::cout << "oiiii";
    for(int i = 0; i < NUM_GRID; i++)
    {
        for(int j = 0; j < NUM_GRID; j++)
        {
            grid[i][j] = nullptr;
            next[i][j] = nullptr;
        }
    }
}
Grid::~Grid()
{

}
//Figure out order to do this shit correctly (bugged when placing large amount of particles, particles acting different for each side)
void Grid::execute()
{
    for(int i = NUM_GRID - 1; i >= 0; i--) {
      for(int j = 0; j < NUM_GRID - 1; j++) {
          if(grid[i][j] != nullptr) {
              grid[i][j]->update(sf::Vector2i(i, j));
          }
      }
    }
    swapAndClear();
}
void Grid::swapAndClear()
{
    for(int i = 0; i < NUM_GRID; i++)
    {
        for(int j = 0; j < NUM_GRID; j++)
        {
            grid[i][j] = next[i][j];
            next[i][j] = nullptr;
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
                grid[i][j]->reset();
            }
        }
    }
    
}

bool Grid::checkBelow(sf::Vector2i pos_grid)
{
    int i = pos_grid.x;
    int j = pos_grid.y;

        //If block below is empty, continue downwards
        if(next[i][j + 1] == nullptr && j < NUM_GRID)
        {
            //Verifies blocks below to see if the element wouldn't pass right into another because of gravity (gravity makes the elements travel more than one block per frame)
            int k = 1;
            while(next[i][j+k+1] == 0 && k <= grid[i][j]->getVel() && j+k < NUM_GRID)
            {
                k++;
            }
            grid[i][j]->update_vel();
            next[i][j + k] = grid[i][j];

            return true;
        }
        else if(next[i][j+1] != nullptr)
            return false;
        
}
bool Grid::checkDiagonaly(sf::Vector2i pos_grid)
{
    int i = pos_grid.x;
    int j = pos_grid.y;

    if(next[i+1][j+1] == nullptr)
    {
        next[i+1][j+1] = grid[i][j];
        return true;
    }
    else if(next[i-1][j+1] == nullptr)
    {
        next[i-1][j+1] = grid[i][j];
        return true;
    }
    else
        return false;
}
bool Grid::goSide(sf::Vector2i pos_grid)
{
    int i = pos_grid.x;
    int j = pos_grid.y;

    if(next[i - 1][j] == nullptr)
    {
        next[i-1][j] = grid[i][j];
        return true;
    }
    else if(next[i + 1][j] == nullptr)
    {
        next[i+1][j] = grid[i][j];
        return true;
    }
    return false;
}
bool Grid::checkDensity(sf::Vector2i pos_grid)
{
    if(grid[pos_grid.x][pos_grid.y]->getDensity() > grid[pos_grid.x][pos_grid.y + 1]->getDensity())
    {
        swapCells(pos_grid, sf::Vector2i(pos_grid.x, pos_grid.y + 1));
        grid[pos_grid.x][pos_grid.y + 1]->update(sf::Vector2i(0, 0));
        return true;
    }
    return false;
}
void Grid::stay(sf::Vector2i pos_grid)
{
    next[pos_grid.x][pos_grid.y] = grid[pos_grid.x][pos_grid.y];
}
void Grid::swapCells(sf::Vector2i pos_grid1, sf::Vector2i pos_grid)
{
    Element* temp = grid[pos_grid.x][pos_grid.y];
    grid[pos_grid.x][pos_grid.y] = grid[pos_grid1.x][pos_grid1.y];
    grid[pos_grid1.x][pos_grid1.y] = temp;
    //delete temp;
}
void Grid::place(int id, sf::Vector2i position)
{
    if(grid[position.x][position.y] == nullptr)
        switch(id)
        {
            case 1:
            {
                Sand* new_sand = new Sand(sf::Vector2f(position.x * 4, position.y * 4), this);
                grid[position.x][position.y] = static_cast<Element*> (new_sand);
                break;
            }

            case 2:
            {
                Water* new_water = new Water(sf::Vector2f(position.x * 4, position.y * 4), this);
                grid[position.x][position.y] = static_cast<Element*> (new_water);
                break;
            }
            case 3:
            {
                Rock* new_rock = new Rock(sf::Vector2f(position.x * 4, position.y * 4), this);
                grid[position.x][position.y] = static_cast<Element*> (new_rock);
                break;
            }
        }

}

