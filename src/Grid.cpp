#include "../Headers/Grid.h"

Grid::Grid()
{
    std::cout << "oiiii";
    for(int i = 0; i < NUM_GRID; i++)
    {
        for(int j = 0; j < NUM_GRID; j++)
        {
            grid[i][j] = nullptr;
            priv_grid[i][j] = 0;
        }
    }
    std::cout << "oiiii";
}
Grid::~Grid()
{

}
//Figure out order to do this shit correctly (bugged when placing large amount of particles, particles acting different for each side)
void Grid::execute()
{
    for(int i = NUM_GRID - 1; i >= 0; i--) {
      for(int j = 0; j < NUM_GRID; j++) {
          if(grid[i][j] != nullptr) {
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
                grid[i][j]->reset();
                priv_grid[i][j] = grid[i][j]->getId();
            }
            else
                priv_grid[i][j] = 0;
        }
    }
    
}

bool Grid::checkBelow(sf::Vector2i pos_grid)
{
    int i = pos_grid.x;
    int j = pos_grid.y;

        //If block below is empty, continue downwards
        if(grid[i][j + 1] == 0 && j < NUM_GRID)
        {
            //Verifies blocks below to see if the element wouldn't pass right into another because of gravity (gravity makes the elements travel more than one block per frame)
            int k = 1;
            while(priv_grid[i][j+k+1] == 0 && k <= grid[i][j]->getVel() && j+k < NUM_GRID)
            {
                k++;
            }
            grid[i][j]->update_vel();
            grid[i][j + k] = grid[i][j];
            grid[i][j] = nullptr; 

            return true;
        }
        //If block below isn`t empty, check diagonally
        else if(grid[i][j+1] != 0)
        {
                if(grid[i+1][j+1] == 0)
                {
                    grid[i + 1][j + 1] = grid[i][j];
                    grid[i][j] = nullptr;
                    return true;
                }
                if(grid[i-1][j+1] == 0)
                {
                    grid[i - 1][j + 1] = grid[i][j];
                    grid[i][j] = nullptr;
                    return true;
                } 
                if(grid[i][j+1]->getDensity() < grid[i][j]->getDensity())
                {
                    Element* temp = grid[i][j];
                    grid[i][j] = grid[i][j + 1];
                    grid[i][j + 1] = temp;
                    
                    temp = nullptr;
                    delete temp;

                    return true;
                }
            
            return false;                
        }
        return false;
        
}
void Grid::goSide(sf::Vector2i pos_grid, bool direction)
{
    int i = pos_grid.x;
    int j = pos_grid.y;

    if(direction)
    {
        if(grid[i + 1][j] == 0)
        {
            grid[i + 1][j] = grid[i][j];
            grid[i][j] = nullptr;
        }
        else if(grid[i - 1][j] == 0)
        {
            grid[i - 1][j] = grid[i][j];
            grid[i][j] = nullptr;
        }
    }
    else
    {
        if(grid[i - 1][j] == 0)
        {
            grid[i - 1][j] = grid[i][j];
            grid[i][j] = nullptr;
        }
        else if(grid[i + 1][j] == 0)
        {
            grid[i + 1][j] = grid[i][j];
            grid[i][j] = nullptr;
        }
    }
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

