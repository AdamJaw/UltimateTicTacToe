#include "game.hpp"
#include <SFML/Graphics.hpp>

int Game::returnIndexOfTheBigBoard(int boardX,int boardY){
    return (boardY*c_bigBlockQuantityX+boardX);
}

int Game::returnTheCoordinateXOfBigBoard(int bigBoardIndex){
    int X = bigBoardIndex%c_bigBlockQuantityX;
    return X;
}
int Game::returnTheCoordinateYOfBigBoard(int bigBoardIndex){
    int Y = bigBoardIndex/c_bigBlockQuantityX;
    return Y;
}

bool Game::checkIfFieldAlreadyTaken(int tmpZ, int tmpY, int tmpX){
    if((c_crossAndCirclePositions[tmpZ][tmpY][tmpX]==1)||(c_crossAndCirclePositions[tmpZ][tmpY][tmpX]==0)){
        return true;
    }else return false;
}

bool Game::setActualIndexes(sf::Vector2i MousePos){
    c_actualBigBoardIndexX = pixelsToBigBoardCoordinate(MousePos.x,c_bigBlockOutlineThickness,c_bigBlockWidth);
    c_actualBigBoardIndexY = pixelsToBigBoardCoordinate(MousePos.y,c_bigBlockOutlineThickness,c_bigBlockHeight);
    c_actualSmallBoardIndexX = pixelsToSmallBoardCoordinate(MousePos.x,c_bigBlockOutlineThickness,c_bigBlockWidth,c_smallBlockOutlineThickness,c_smallBlockWidth);
    c_actualSmallBoardIndexY = pixelsToSmallBoardCoordinate(MousePos.y,c_bigBlockOutlineThickness,c_bigBlockHeight,c_smallBlockOutlineThickness,c_smallBlockHeight);
    if((c_actualBigBoardIndexX==(-1))||(c_actualBigBoardIndexY==(-1))||(c_actualSmallBoardIndexX==(-1))||(c_actualSmallBoardIndexY==(-1))){
        return false;
    }
    return true;
}

void Game::checkTheBoardForWinner(int howManyInRow,int whichBoard,int boardWidth, int boardHeight){
    checkTheBoardDiagonallyFromLeft(howManyInRow,whichBoard,boardWidth,boardHeight);
    checkTheBoardDiagonallyFromRight(howManyInRow,whichBoard,boardWidth,boardHeight);
    checkTheBoardHorizontally(howManyInRow,whichBoard,boardWidth,boardHeight);
    checkTheBoardVertically(howManyInRow,whichBoard,boardWidth,boardHeight);
}

void Game::turnOfPlayer(sf::Texture& texture){
    if((checkIfFieldAlreadyTaken(returnIndexOfTheBigBoard(c_actualBigBoardIndexX,c_actualBigBoardIndexY),c_actualSmallBoardIndexY,c_actualSmallBoardIndexX))==false){
        c_crossAndCirclePositions[returnIndexOfTheBigBoard(c_actualBigBoardIndexX,c_actualBigBoardIndexY)][c_actualSmallBoardIndexY][c_actualSmallBoardIndexX]=c_player_turn;
        drawSmallSignOnField(returnIndexOfTheBigBoard(c_actualBigBoardIndexX,c_actualBigBoardIndexY),c_actualSmallBoardIndexY,c_actualSmallBoardIndexX, texture);
        c_turn_made=true;
    }
}