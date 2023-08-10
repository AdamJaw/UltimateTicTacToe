#include "game.hpp"

void Game::checkTheBoardHorizontally(int howManyInRow,int whichBoard,int boardWidth,int boardHeight){
    int counter_cross=0;
    int counter_circle=0;
    for(int i=0;i<boardHeight;i++){
        for(int j=0;j<boardWidth;j++){
            if(c_crossAndCirclePositions[whichBoard][i][j]==1){
                counter_cross++;
                counter_circle=0;
                if(counter_cross==howManyInRow){
                    c_winner[whichBoard]=1;
                }
            }
            if(c_crossAndCirclePositions[whichBoard][i][j]==0){
                counter_circle++;
                counter_cross=0;
                if(counter_circle==howManyInRow){
                    c_winner[whichBoard]=0;
                }
            }
            if(c_crossAndCirclePositions[whichBoard][i][j]==2){
                counter_circle=0;
                counter_cross=0;
            }
        }
        counter_circle=0;
        counter_cross=0;
    }
}