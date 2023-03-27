#include "Game.h"

int main()
{
    bnc::Game* game = new bnc::Game(1280, 720, "Banica The Game");
    game->Run(); 
    delete game;
}