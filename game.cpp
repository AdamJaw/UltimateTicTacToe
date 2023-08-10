#include "game.hpp"

Game::Game(float bigBlockWidth, float bigBlockHeight,float bigBlockOutlineThickness,int bigBlockQuantityX,int bigBlockQuantityY,float smallBlockOutlineThickness,int smallBlockQuantityX,int smallBlockQuantityY,sf::RenderWindow& window, int howManyInRow)
:   c_window(window)
{
    c_bigBlockWidth = bigBlockWidth;
    c_bigBlockHeight = bigBlockHeight;
    c_bigBlockOutlineThickness = bigBlockOutlineThickness;
    c_bigBlockQuantityX = bigBlockQuantityX;
    c_bigBlockQuantityY = bigBlockQuantityY;
    c_smallBlockQuantityX = smallBlockQuantityX;
    c_smallBlockQuantityY = smallBlockQuantityY;
    c_smallBlockWidth = ((bigBlockWidth-(2*bigBlockOutlineThickness))/smallBlockQuantityX);
    c_smallBlockHeight = ((bigBlockHeight-(2*bigBlockOutlineThickness))/smallBlockQuantityY);
    c_smallBlockOutlineThickness = smallBlockOutlineThickness;
    c_howManyInRow = howManyInRow;
    c_player_turn = 0;
    c_isGameStillGoing = true;
    c_turn_made = false;

    createBigRectangularBlocks();
    createSmallRectangularBlocks();
    createWinnerTable();
    createCrossAndCirclePositionTable();
}
void Game::createBigRectangularBlocks(){
    c_bigBlocks = new sf::RectangleShape*[c_bigBlockQuantityY];
    for(int i=0;i<c_bigBlockQuantityY;i++){
        c_bigBlocks[i] = new sf::RectangleShape[c_bigBlockQuantityX];
    }

    for(int i=0;i<c_bigBlockQuantityY;i++){
        for(int j=0;j<c_bigBlockQuantityX;j++){
            c_bigBlocks[i][j].setSize(
                sf::Vector2f(
                    (c_bigBlockHeight-(2*c_bigBlockOutlineThickness)),
                    (c_bigBlockWidth-(2*c_bigBlockOutlineThickness))
                )
            );
            //c_bigBlocks[i][j].setFillColor(sf::Color::White);
            c_bigBlocks[i][j].setOutlineThickness(c_bigBlockOutlineThickness);
            c_bigBlocks[i][j].setOutlineColor(sf::Color::Black);
            c_bigBlocks[i][j].setPosition(
                sf::Vector2f(
                    (j*(c_bigBlockWidth)+c_bigBlockOutlineThickness),
                    (i*(c_bigBlockHeight)+c_bigBlockOutlineThickness)
                )
            );
            c_bigBlocks[i][j].setTexture(nullptr);
            c_bigBlocks[i][j].setFillColor(sf::Color(255,255,255,0));
        }
    }
}

void Game::createSmallRectangularBlocks(){
    c_smallBlocks = new sf::RectangleShape**[(c_bigBlockQuantityX*c_bigBlockQuantityY)];
    for(int k=0;k<(c_bigBlockQuantityX*c_bigBlockQuantityY);k++){
        c_smallBlocks[k]=new sf::RectangleShape*[c_smallBlockQuantityY];
    }
    for(int k=0;k<(c_bigBlockQuantityX*c_bigBlockQuantityY);k++){
        for(int i=0;i<c_smallBlockQuantityY;i++){
            c_smallBlocks[k][i] = new sf::RectangleShape[c_smallBlockQuantityX];
        }
    }

    int indexCounter=0;
    for(int k=0;k<c_bigBlockQuantityY;k++){
        for(int m=0;m<c_bigBlockQuantityX;m++){
            for(int i=0;i<c_smallBlockQuantityY;i++){
                for(int j=0;j<c_smallBlockQuantityX;j++){
                    c_smallBlocks[indexCounter][i][j].setSize(
                        sf::Vector2f(
                            (c_smallBlockHeight-(2*c_smallBlockOutlineThickness)),
                            (c_smallBlockWidth-(2*c_smallBlockOutlineThickness))
                        )
                    );
                    c_smallBlocks[indexCounter][i][j].setFillColor(sf::Color::White);
                    c_smallBlocks[indexCounter][i][j].setOutlineThickness(c_smallBlockOutlineThickness);
                    c_smallBlocks[indexCounter][i][j].setOutlineColor(sf::Color::Cyan);
                    c_smallBlocks[indexCounter][i][j].setTexture(nullptr);
                    c_smallBlocks[indexCounter][i][j].setPosition(
                        sf::Vector2f(
                            ((m*(c_bigBlockWidth)+c_bigBlockOutlineThickness)+(j*(c_smallBlockWidth)+c_smallBlockOutlineThickness)),
                            ((k*(c_bigBlockHeight)+c_bigBlockOutlineThickness)+(i*(c_smallBlockHeight)+c_smallBlockOutlineThickness))
                        )
                    );
                }
            }
            indexCounter++;
        }
    }
}

void Game::createWinnerTable(){
    c_winner = new int[(c_bigBlockQuantityX*c_bigBlockQuantityY)+1]; 
    for(int i=0;i<(c_bigBlockQuantityX*c_bigBlockQuantityY)+1;i++){
        c_winner[i] = 2;
    }
}

void Game::createCrossAndCirclePositionTable(){
    c_crossAndCirclePositions = new int**[(c_bigBlockQuantityX*c_bigBlockQuantityY)+1];
    for(int i=0;i<(c_bigBlockQuantityX*c_bigBlockQuantityY);i++){
        c_crossAndCirclePositions[i] = new int*[c_smallBlockQuantityY];
    }

    for(int i=0;i<(c_bigBlockQuantityX*c_bigBlockQuantityY);i++){
        for(int j=0;j<c_smallBlockQuantityY;j++){
            c_crossAndCirclePositions[i][j] = new int[c_smallBlockQuantityX];
        }
    }

    c_crossAndCirclePositions[(c_bigBlockQuantityX*c_bigBlockQuantityY)] = new int*[c_bigBlockQuantityY];
    for(int i=0;i<c_bigBlockQuantityY;i++){
        c_crossAndCirclePositions[(c_bigBlockQuantityX*c_bigBlockQuantityY)][i] = new int[c_bigBlockQuantityX];
    }

    for(int k=0;k<(c_bigBlockQuantityX*c_bigBlockQuantityY);k++){
        for(int i=0;i<c_smallBlockQuantityY;i++){
            for(int j=0;j<c_smallBlockQuantityX;j++){
                c_crossAndCirclePositions[k][i][j] = 2;
            }
        }
    }

    for(int i=0;i<c_bigBlockQuantityY;i++){
        for(int j=0;j<c_bigBlockQuantityX;j++){
            c_crossAndCirclePositions[(c_bigBlockQuantityX*c_bigBlockQuantityY)][i][j]=2;
        }
    }
}