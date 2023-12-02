#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "objPos.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs* game;
Player* playerObj;
objPos myPos;



void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(game->getExitFlagStatus() == false)  // run game while exitFlag = False (no head + tail collision)
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp(); // deallocate dynamic variables + all sorts of cleanup

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    game = new GameMechs(15,30);
    playerObj = new Player(game);
    objPosArrayList* snakeBody = playerObj->getPlayerPos();
    srand(time(NULL));
    game->generateFood(*snakeBody); // pass in ptr to player array
    
}

void GetInput(void)
{
    
    game->setInput(game->getInput());
    

}

void RunLogic(void)
{
    
    
    

    objPosArrayList* snakeBody = playerObj->getPlayerPos(); // receive position of all segments
    playerObj->updatePlayerDir();
    playerObj->movePlayer();
    game->clearInput(); // clear input so same input not processed multiple times


    

    

}

void DrawScreen(void)
{
    
    MacUILib_clearScreen(); 
    
    objPosArrayList* playerBody = playerObj->getPlayerPos();
    objPos tempBody;
    bool drawn;

    objPos foodPos;
    game->getFoodPos(foodPos);

    int score;
    score = game->getScore();

    // generate board
    for (int i = 0; i < game->getBoardSizeX(); i++) 
    {
        for (int j = 0; j < game->getBoardSizeY(); j++) 
        {
            
            // print player snake on board, iterate over all elements and print
            drawn = false;
            for(int x=0; x<playerBody->getSize();x++){
                playerBody->getElement(tempBody,x);

                if(tempBody.x == i && tempBody.y == j){
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }

            if(drawn){
                continue;
            }
            
            // border conditions
            if (i == 0 || i == game->getBoardSizeX() - 1 || j == 0 || j == game->getBoardSizeY()- 1) 
            {
                MacUILib_printf("#");
            } 
            // food spawning
            else if (i == foodPos.x && j == foodPos.y) 
            {
               MacUILib_printf("%c", foodPos.symbol);
            } 
            
            else 
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }      
    // display score
    MacUILib_printf("Score: %d\n", score);

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    // print losing message
    if(game->getLoseFlagStatus() == true){
        MacUILib_printf("Game over. You scored %d points! Well done!", game->getScore());
    }

  
    MacUILib_uninit();
}
