#include "game.hpp"

void Game::checkTheBoardVertically(int howManyInRow,int whichBoard,int boardWidth, int boardHeight){
    int counter_cross=0;
    int counter_circle=0;
    for(int i=0;i<boardWidth;i++){
        for(int j=0;j<boardHeight;j++){
             if(c_crossAndCirclePositions[whichBoard][j][i]==1){
                counter_cross++;
                counter_circle=0;
                if(counter_cross==howManyInRow){
                    c_winner[whichBoard]=1;
                }
            }
            if(c_crossAndCirclePositions[whichBoard][j][i]==0){
                counter_circle++;
                counter_cross=0;
                if(counter_circle==howManyInRow){
                    c_winner[whichBoard]=0;
                }
            }
            if(c_crossAndCirclePositions[whichBoard][j][i]==2){
                counter_circle=0;
                counter_cross=0;
            }
        }
        counter_circle=0;
        counter_cross=0;
    }
}