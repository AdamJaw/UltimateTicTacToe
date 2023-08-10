#include "game.hpp"

void Game::checkTheBoardDiagonallyFromRight(int howManyInRow,int whichBoard,int boardWidth, int boardHeight){
    int j,k;
    int counter_cross_upper;
    int counter_circle_upper;
    int counter_cross_lower;
    int counter_circle_lower;

    for(int i=0;i<boardWidth;i++){
        
        j=0;
        k=(boardWidth-i)-1;
        counter_cross_upper=0;
        counter_circle_upper=0;

        while((k>=0)&&(j<boardHeight)){
            if(c_crossAndCirclePositions[whichBoard][k][j]==1){
                counter_cross_upper++;
                counter_circle_upper=0;
                if(counter_cross_upper==howManyInRow){
                    c_winner[whichBoard]=1;
                }
            }
            if(c_crossAndCirclePositions[whichBoard][k][j]==0){
                counter_cross_upper=0;
                counter_circle_upper++;
                if(counter_circle_upper==howManyInRow){
                    c_winner[whichBoard] = 0;
                }                
            }
            if(c_crossAndCirclePositions[whichBoard][k][j]==2){
                counter_circle_upper=0;
                counter_cross_upper=0;
            }
            k--;
            j++;
        }

        j=i;
        k=boardWidth-1;
        counter_cross_lower=0;
        counter_circle_lower=0;

        while((k>=0)&&(j<boardHeight)){
            if(c_crossAndCirclePositions[whichBoard][k][j]==1){
                counter_cross_lower++;
                counter_circle_lower=0;
                if(counter_cross_lower==howManyInRow){
                    c_winner[whichBoard]=1;
                }
            }
            if(c_crossAndCirclePositions[whichBoard][k][j]==0){
                counter_circle_lower++;
                counter_cross_lower=0;
                if(counter_circle_lower==howManyInRow){
                    c_winner[whichBoard]=0;
                }
            }
            if(c_crossAndCirclePositions[whichBoard][k][j]==2){
                counter_circle_lower=0;
                counter_cross_lower=0;
            }
            k--;
            j++;
        }
    }
}