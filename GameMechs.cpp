#include "GameMechs.h"


GameMechs::GameMechs()
{
    boardSizeX = 15;
    boardSizeY = 30;
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    foodPos.setObjPos(-1,-1,'o');

}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;

    foodPos.setObjPos(-1,-1,'o');
        

}

// do you need a destructor?




bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

char GameMechs::getInput()
{
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

void GameMechs::generateFood(objPos blockOff)
{
    
    bool overlaps = true;
    int targetX,targetY;

    do {
        
        overlaps = false;
        targetX = (rand()%(boardSizeX-2)) + 1; //adds 1 to make sure it doesn't generate on left border
        targetY = (rand()%(boardSizeY-2)) + 1;

        if(blockOff.x == targetX && blockOff.y == targetY){
            overlaps = true;
        }

    } while(overlaps);
    
    foodPos.x = targetX;
    foodPos.y = targetY;

    

}

void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos = foodPos;
}


