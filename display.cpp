#include "game.hpp"
#include "SFML/Graphics.hpp"

void Game::displayBigRectangularBlocks(){
    for(int i=0;i<c_bigBlockQuantityY;i++){
        for(int j=0;j<c_bigBlockQuantityX;j++){
            c_window.draw(c_bigBlocks[i][j]);
        }
    }
}

void Game::displaySmallRectangularBlocks(){
    for(int k=0;k<(c_bigBlockQuantityX*c_bigBlockQuantityY);k++){
        for(int i=0;i<c_smallBlockQuantityY;i++){
            for(int j=0;j<c_smallBlockQuantityX;j++){
               c_window.draw(c_smallBlocks[k][i][j]);
            }
        }
    }
}