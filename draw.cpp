#include "game.hpp"

void Game::drawSmallSignOnField(int z,int y,int x,sf::Texture& texture){
    c_smallBlocks[z][y][x].setTexture(&texture);
}

void Game::drawBigCross(sf::Texture &texture,int x, int y){
    c_bigBlocks[y][x].setTexture(&texture);
    c_bigBlocks[y][x].setFillColor(sf::Color(255,255,255,255));
}

void Game::drawBigCircle(sf::Texture &texture,int x, int y){
    c_bigBlocks[y][x].setTexture(&texture);
    c_bigBlocks[y][x].setFillColor(sf::Color(255,255,255,255));
}