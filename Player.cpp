#include "Player.h"
#include "GameMechs.h"
#include "objPosArrayList.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    objPos tempPos;
    tempPos.setObjPos((mainGameMechsRef->getBoardSizeX())/2, (mainGameMechsRef->getBoardSizeY())/2, '@');

    playerPosList = new objPosArrayList();
    
    playerPosList->insertHead(tempPos);


}


Player::~Player()
{
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // BREAKPOINT Check for input Processing w/ Aman, defo not via getChar()
    char input = mainGameMechsRef->getInput();
    if(input != 0)  // if not null character
    {
        switch(input)
        {            

            case 27:
                mainGameMechsRef->setExitTrue();

            case 'a':
                if(myDir != RIGHT){
                    myDir = LEFT;
                }
                break;
            
            case 'd':
                if(myDir != LEFT){
                    myDir = RIGHT;
                }
                break;
            
            case 'w':
                if(myDir != DOWN){
                    myDir = UP;
                }
                break;
            
            case 's':
                if(myDir != UP){
                    myDir = DOWN;
                }
                break;
            
        }

        mainGameMechsRef->clearInput();
        
    }

}

void Player::movePlayer()
{
    objPos currentHead;

    playerPosList->getHeadElement(currentHead);
    if (myDir != STOP)
    {
        switch(myDir)
        {
            case LEFT:
                if (myDir != RIGHT)  // Only move if not moving in the opposite direction
                    currentHead.y -= 1;
                break;
            case RIGHT:
                if (myDir != LEFT)  // Only move if not moving in the opposite direction
                    currentHead.y += 1;
                break;
            case UP:
                if (myDir != DOWN)  // Only move if not moving in the opposite direction
                    currentHead.x -= 1;
                break;
            case DOWN:
                if (myDir != UP)  // Only move if not moving in the opposite direction
                    currentHead.x += 1;
                break;
        }
    }

    if(currentHead.x > mainGameMechsRef->getBoardSizeX()-2){
        currentHead.x = 1;
        }else if(currentHead.x < 1){
            currentHead.x = mainGameMechsRef->getBoardSizeX()-2;
        }else if(currentHead.y > mainGameMechsRef->getBoardSizeY()-2){
            currentHead.y = 1;
        }else if(currentHead.y < 1){
            currentHead.y = mainGameMechsRef->getBoardSizeY()-2;
    }

    playerPosList->insertHead(currentHead);
    playerPosList->removeTail();

}

bool Player::checkFoodConsumption() 
{
    objPos tempFood;

    mainGameMechsRef->getFoodPos(tempFood);

    objPos tempHead;

    playerPosList->getElement(tempHead, 0);

    bool overlap;
    overlap = tempFood.isPosEqual(&tempHead);

    if(overlap){
        return true;
    }

    else {
        return false;
    }


}

void Player::increasePlayerLength()
{
    objPos tempHead;
    playerPosList->getHeadElement(tempHead);
    playerPosList->insertHead(tempHead);
}
