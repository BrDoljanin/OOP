#include <iostream>
#include "Game.h"

Game::Game(const std::string& t, const std::string& player_name) : title(t), igrac(player_name) {}

void Game::print() const {
    std::cout << title << "\n";
    igrac.print();
}
