#pragma once
#include "../Managers/Graphic_Manager.h"
#include "Grid.h"
#include "Radius.h"


#include <iostream>


class World
{
private:
    Graphic_Manager* pGM;
    Grid grid;
    Radius radius;
public:
    World();
    ~World();
    void execute();
    void loop_event();
};