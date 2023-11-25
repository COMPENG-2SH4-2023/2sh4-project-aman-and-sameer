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
    switch(input)
        {
            // w key
            case 119:
                if (myDir != DOWN)  // Only change direction if not currently moving down
                {
                    myDir = UP;
                }
                break;
            // a
            case 97:
                if (myDir != RIGHT)  // Only change direction if not currently moving right
                {
                    myDir = LEFT;
                }
                break;
            
             // s
            case 115:
                if (myDir != UP)  // Only change direction if not currently moving up
                {
                    myDir = DOWN;
                }
                break;
            // d
            case 100:
                if (myDir != LEFT)  // Only change direction if not currently moving left
                {
                    myDir = RIGHT;
                }
                break;

            default:
                break;
            
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
                    playerPos.x -= 1;
                break;
            case RIGHT:
                if (myDir != LEFT)  // Only move if not moving in the opposite direction
                    playerPos.x += 1;
                break;
            case UP:
                if (myDir != DOWN)  // Only move if not moving in the opposite direction
                    playerPos.y -= 1;
                break;
            case DOWN:
                if (myDir != UP)  // Only move if not moving in the opposite direction
                    playerPos.y += 1;
                break;
        }
    }
}

