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

    while(game->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    game = new GameMechs(15,30);
    playerObj = new Player(game);

    objPosArrayList* snakeBody = playerObj->getPlayerPos();
    

    srand(time(NULL));
    
    game->generateFood(snakeBody);
    
}

void GetInput(void)
{
    
    game->setInput(game->getInput());
    

}

void RunLogic(void)
{
    
    playerObj->movePlayer();
    playerObj->updatePlayerDir();

    game->clearInput();

    objPosArrayList* snakeBody = playerObj->getPlayerPos();

    if (playerObj->checkFoodConsumption())
    {
        game->incrementScore();
        playerObj->increasePlayerLength();
        game->generateFood(snakeBody);

    } 

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

    
    for (int i = 0; i < game->getBoardSizeX(); i++) 
    {
        for (int j = 0; j < game->getBoardSizeY(); j++) 
        {
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

            if (i == 0 || i == game->getBoardSizeX() - 1 || j == 0 || j == game->getBoardSizeY()- 1) 
            {
                MacUILib_printf("#");
            } 
            
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
    MacUILib_printf("%d\n", foodPos.x);
    MacUILib_printf("%d\n", foodPos.y);
    MacUILib_printf("%d\n", foodPos.symbol);

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
