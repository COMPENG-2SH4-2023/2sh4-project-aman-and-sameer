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
}

void GetInput(void)
{
   
    if(MacUILib_hasChar() != 0){
        game->setInput(MacUILib_getChar());
    }

}

void RunLogic(void)
{
    
    if(game->getInput() == 27){
        game->setExitTrue();
    }

    playerObj->movePlayer();
    playerObj->updatePlayerDir();
    

    game->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 
    
    objPos myPos;
    playerObj->getPlayerPos(myPos); 

    
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
            
            else 
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }      

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
