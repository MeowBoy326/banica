#include "Game.h"

int main()
{
    bn::Game* game = new bn::Game(1280, 720, "Banica The Game");
    game->Run(); 
    delete game;
}