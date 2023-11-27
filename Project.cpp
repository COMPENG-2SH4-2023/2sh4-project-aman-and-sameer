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
    
    

    srand(time(NULL));
    
    game->generateFood(myPos);
    
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

}

void DrawScreen(void)
{
    
    MacUILib_clearScreen(); 
    
    objPos foodPos;
    playerObj->getPlayerPos(myPos); 

    game->getFoodPos(foodPos);

    
    for (int i = 0; i < game->getBoardSizeX(); i++) 
    {
        for (int j = 0; j < game->getBoardSizeY(); j++) 
        {
            if (i == 0 || i == game->getBoardSizeX() - 1 || j == 0 || j == game->getBoardSizeY()- 1) 
            {
                MacUILib_printf("#");
            } 
            
            else if (i == myPos.x && j == myPos.y) 
            {
               MacUILib_printf("%c", myPos.symbol);
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
