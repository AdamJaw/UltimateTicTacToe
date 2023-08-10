#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

class Game{
public:
    float c_bigBlockWidth;
    float c_bigBlockHeight;
    float c_bigBlockOutlineThickness;
    int c_bigBlockQuantityX;
    int c_bigBlockQuantityY;
    sf::RectangleShape **c_bigBlocks;
    float c_smallBlockWidth;
    float c_smallBlockHeight;
    float c_smallBlockOutlineThickness;
    int c_smallBlockQuantityX;
    int c_smallBlockQuantityY;
    sf::RectangleShape ***c_smallBlocks;
    sf::RenderWindow& c_window;
    int ***c_crossAndCirclePositions;
    int c_player_turn;
    bool c_turn_made;
    int *c_winner;
    int c_actualBigBoardIndexX;
    int c_actualBigBoardIndexY;
    int c_actualSmallBoardIndexX;
    int c_actualSmallBoardIndexY;
    int c_howManyInRow;
    int c_isGameStillGoing;

private:
    void createBigRectangularBlocks();
    void createSmallRectangularBlocks();
    void createWinnerTable();
    void createCrossAndCirclePositionTable();
public:
    Game(float,float,float,int,int,float,int,int,sf::RenderWindow&,int);
    int pixelsToBigBoardCoordinate(int,int,int);
    int pixelsToSmallBoardCoordinate(int,int,int,int,int);
    void displayBigRectangularBlocks();
    void displaySmallRectangularBlocks();
    void checkTheBoardDiagonallyFromLeft(int,int,int,int);
    void checkTheBoardDiagonallyFromRight(int,int,int,int);
    void checkTheBoardHorizontally(int,int,int,int);
    void checkTheBoardVertically(int,int,int,int);
    int returnIndexOfTheBigBoard(int,int);
    bool checkIfFieldAlreadyTaken(int,int,int);
    void drawSmallSignOnField(int,int,int,sf::Texture&);
    bool setActualIndexes(sf::Vector2i);
    void checkTheBoardForWinner(int,int,int,int);
    void drawBigCross(sf::Texture&,int,int);
    void drawBigCircle(sf::Texture&,int,int);
    int returnTheCoordinateXOfBigBoard(int);
    int returnTheCoordinateYOfBigBoard(int);
    void turnOfPlayer(sf::Texture&);
};

#endif //GAME_H