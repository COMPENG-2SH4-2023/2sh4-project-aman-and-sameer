#include "GameMechs.h"
#include "MacUILib.h"


GameMechs::GameMechs()
{
    
    // Generate Dimensions + Inital Game Conditions
    boardSizeX = 15;
    boardSizeY = 30;
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    foodPos.setObjPos(-1,-1,'o'); // Initial food spawn

}

GameMechs::GameMechs(int boardX, int boardY) // If user wishes to specify dimensions
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




// End game if exitFlag and loseFlag = True

bool GameMechs::getExitFlagStatus() 
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() {
    return loseFlag;
}

char GameMechs::getInput()
{

    if(MacUILib_hasChar()){
        input = MacUILib_getChar();
    }
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

void GameMechs::generateFood(objPosArrayList &blockOff)
{
    
    bool overlaps = true;
    int targetX,targetY;

    do {
        
        overlaps = false;
        targetX = (rand()%(boardSizeX-2)) + 1; //adds 1 to make sure it doesn't generate on left border
        targetY = (rand()%(boardSizeY-2)) + 1;

        for(int i=0;i<blockOff.getSize();i++){
            objPos tempObj;
            blockOff.getElement(tempObj, i);

            if(tempObj.x == targetX && tempObj.y == targetY){
                overlaps = true;
            }

        }


    } while(overlaps);
    
    foodPos.x = targetX;
    foodPos.y = targetY;

    

}

void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos = foodPos;
}

