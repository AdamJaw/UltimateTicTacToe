#include "game.hpp"

int Game::pixelsToBigBoardCoordinate(int screenCoordinate, int outlineThickness, int blockSize){
    int startingRange=outlineThickness;
    int endingRange=blockSize-outlineThickness;
    int outOfRangeFirstBeginning=0;
    int outOfRangeFirstEnding=outlineThickness;
    int outOfRangeSecondBeginning=blockSize-outlineThickness;
    int outOfRangeSecondEnding=blockSize;
    int indexCounter=0;

    while(true){
        if((screenCoordinate>startingRange)&&(screenCoordinate<endingRange)){
            return indexCounter;
        }
        if(((screenCoordinate>=outOfRangeFirstBeginning)&&(screenCoordinate<=outOfRangeFirstEnding))||((screenCoordinate>=outOfRangeSecondBeginning)&&(screenCoordinate<=outOfRangeSecondEnding))){
            return (-1);
        }
        else{
            startingRange+=blockSize;
            endingRange+=blockSize;
            outOfRangeFirstBeginning+=blockSize;
            outOfRangeFirstEnding+=blockSize;
            outOfRangeSecondBeginning+=blockSize;
            outOfRangeSecondEnding+=blockSize;
            indexCounter++;
        }
    }
}

int Game::pixelsToSmallBoardCoordinate(int screenCoordinate, int outlineThicknessBig, int blockSizeBig, int outlineThicknessSmall, int blockSizeSmall){
    int bigBoardCoordinate=pixelsToBigBoardCoordinate(screenCoordinate,outlineThicknessBig,blockSizeBig);
    int startingRange=(blockSizeBig*bigBoardCoordinate)+outlineThicknessBig+outlineThicknessSmall;
    int endingRange=(blockSizeBig*bigBoardCoordinate)+outlineThicknessBig+blockSizeSmall-outlineThicknessSmall;
    int outOfRangeFirstBeginning=(blockSizeBig*bigBoardCoordinate)+outlineThicknessBig;
    int outOfRangeFirstEnding=(blockSizeBig*bigBoardCoordinate)+outlineThicknessBig+outlineThicknessSmall;
    int outOfRangeSecondBeginning=(blockSizeBig*bigBoardCoordinate)+outlineThicknessBig+blockSizeSmall-outlineThicknessSmall;
    int outOfRangeSecondEnding=(blockSizeBig*bigBoardCoordinate)+outlineThicknessBig+blockSizeSmall;
    int indexCounter=0;

    while(true){
        if((screenCoordinate>startingRange)&&(screenCoordinate<endingRange)){
            return indexCounter;
        }
        if(((screenCoordinate>=outOfRangeFirstBeginning)&&(screenCoordinate<=outOfRangeFirstEnding))||((screenCoordinate>=outOfRangeSecondBeginning)&&(screenCoordinate<=outOfRangeSecondEnding))){
            return (-1);
        }
        else{
            startingRange+=blockSizeSmall;
            endingRange+=blockSizeSmall;
            outOfRangeFirstBeginning+=blockSizeSmall;
            outOfRangeFirstEnding+=blockSizeSmall;
            outOfRangeSecondBeginning+=blockSizeSmall;
            outOfRangeSecondEnding+=blockSizeSmall;
            indexCounter++;
        }
    }
}
