#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    
    playerPos.x = (mainGameMechsRef->getBoardSizeX())/2;
    playerPos.y = (mainGameMechsRef->getBoardSizeY())/2;
    playerPos.symbol = '*';

}


Player::~Player()
{
 // make later
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);
}

void Player::updatePlayerDir()
{
    // BREAKPOINT Check for input Processing w/ Aman, defo not via getChar()
    char input = mainGameMechsRef->getInput();
    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
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
    if (myDir != STOP)
    {
        switch(myDir)
        {
            case LEFT:
                if (myDir != RIGHT)  // Only move if not moving in the opposite direction
                    playerPos.y -= 1;
                break;
            case RIGHT:
                if (myDir != LEFT)  // Only move if not moving in the opposite direction
                    playerPos.y += 1;
                break;
            case UP:
                if (myDir != DOWN)  // Only move if not moving in the opposite direction
                    playerPos.x -= 1;
                break;
            case DOWN:
                if (myDir != UP)  // Only move if not moving in the opposite direction
                    playerPos.x += 1;
                break;
        }
    }
}

