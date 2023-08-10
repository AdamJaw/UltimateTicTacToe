#include <SFML/Graphics.hpp>
#include "game.hpp"
#include <iostream>

int main(){
    sf::RenderWindow window(sf::VideoMode(900,900),"Two Dimensional Tic-Tac-Toe",sf::Style::Close);
    sf::Texture textureCross;
    sf::Texture textureCircle;
    sf::RectangleShape endScreen;
    sf::RectangleShape txtTest;
    sf::Text text;
    sf::Font font;
    font.loadFromFile("comicSans.ttf");
    endScreen.setFillColor(sf::Color(0,255,0,0));
    endScreen.setSize(sf::Vector2f(900.0f,900.0f));
    textureCross.setSmooth(true);
    textureCircle.setSmooth(true);
    textureCross.loadFromFile("img/cross.bmp");
    textureCircle.loadFromFile("img/circle.bmp");
    Game game(300,300,10,3,3,1,3,3,window,3);
    while(window.isOpen()){
        sf::Event evnt;
        while(window.pollEvent(evnt)){
            switch (evnt.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    sf::Vector2i MousePos = sf::Mouse::getPosition(window);
                    if(game.c_isGameStillGoing){
                        if(game.setActualIndexes(MousePos)){
                            if(game.c_player_turn==1){
                            game.turnOfPlayer(textureCircle);
                            }
                            if(game.c_player_turn==0){
                                game.turnOfPlayer(textureCross);
                            }
                            if(game.c_turn_made==true){
                                if(game.c_player_turn==1){
                                    game.c_player_turn=0;
                                }else game.c_player_turn=1;
                                game.c_turn_made=false;
                            }
                            game.checkTheBoardForWinner(game.c_howManyInRow,game.returnIndexOfTheBigBoard(game.c_actualBigBoardIndexX,game.c_actualBigBoardIndexY),game.c_smallBlockQuantityX,game.c_smallBlockQuantityY);
                            for(int i=0;i<(game.c_bigBlockQuantityX*game.c_bigBlockQuantityY);i++){
                                if(game.c_winner[i]==0){
                                    game.drawBigCross(textureCross,game.returnTheCoordinateXOfBigBoard(i),game.returnTheCoordinateYOfBigBoard(i));
                                    game.c_crossAndCirclePositions[game.c_bigBlockQuantityX*game.c_bigBlockQuantityY][game.returnTheCoordinateYOfBigBoard(i)][game.returnTheCoordinateXOfBigBoard(i)]=game.c_winner[i];
                                }
                                if(game.c_winner[i]==1){
                                    game.drawBigCircle(textureCircle,game.returnTheCoordinateXOfBigBoard(i),game.returnTheCoordinateYOfBigBoard(i));
                                    game.c_crossAndCirclePositions[game.c_bigBlockQuantityX*game.c_bigBlockQuantityY][game. returnTheCoordinateYOfBigBoard(i)][game.returnTheCoordinateXOfBigBoard(i)]=game.c_winner[i];
                                }
                            }
                            game.checkTheBoardForWinner(game.c_howManyInRow,game.c_bigBlockQuantityX*game.c_bigBlockQuantityY,game.c_bigBlockQuantityX,game.c_bigBlockQuantityY);
                            if((game.c_winner[game.c_bigBlockQuantityX*game.c_bigBlockQuantityY]==1)||(game.c_winner[game.c_bigBlockQuantityX*game.c_bigBlockQuantityY]==0)){
                                endScreen.setFillColor(sf::Color(0,255,0,128));
                                game.c_isGameStillGoing=false;
                            }
                        }
                    }
                    break;
            }
        }
        game.displaySmallRectangularBlocks();
        game.displayBigRectangularBlocks();
        window.draw(endScreen);
        if(!game.c_isGameStillGoing){
            text.setFont(font);
            if(game.c_winner[game.c_bigBlockQuantityX*game.c_bigBlockQuantityY]==0){
                text.setString("Cross Wins!");
            }else text.setString("Circle Wins!");
            text.setCharacterSize(50);
            text.setOrigin(text.getLocalBounds().left+(text.getLocalBounds().width/2),text.getLocalBounds().top+(text.getLocalBounds().height/2));
            text.setPosition(sf::Vector2f(window.getView().getCenter()));
            txtTest.setPosition(window.getView().getCenter());
            txtTest.setSize(sf::Vector2f(text.getLocalBounds().left+(text.getLocalBounds().width),text.getLocalBounds().top+(text.getLocalBounds().height)));
            txtTest.setOrigin(text.getLocalBounds().left+(text.getLocalBounds().width/2),text.getLocalBounds().top+(text.getLocalBounds().height/2));
            txtTest.setFillColor(sf::Color::Black);

            window.draw(txtTest);
            window.draw(text);
        }
        window.display();
    }
    return 0;
}
