#include "Food.h"
#include "GameMechs.h"
#include "objPosArrayList.h"

Food::Food() 
{
    foodBucket = new objPos[SIZE_BUCKET];
    specialFoodIndices = new int[SPECIAL_FOOD_COUNT];
    filledSpots = 0;
    sizeBucket = SIZE_BUCKET;
    generateSpecialFoodIndices();  // Function to randomly choose special food indices
}

Food::~Food() 
{
    delete[] foodBucket;
    delete[] specialFoodIndices;
}

void Food::generateFood(objPosArrayList &blockOff) 
{

    // Check if the current food is special
    bool isSpecial = isSpecialFood();

    // Randomly choose positions until a non-overlapping one is found
    do {
        overlaps = false;
        targetX = (rand() % (boardSizeX - 2)) + 1;
        targetY = (rand() % (boardSizeY - 2)) + 1;

        for (int i = 0; i < blockOff.getSize(); i++) {
            objPos tempObj;
            blockOff.getElement(tempObj, i);

            if (tempObj.x == targetX && tempObj.y == targetY) {
                overlaps = true;
                break;
            }
        }
    } while (overlaps);

    // Assign non-overlapping coordinates to food array
    foodBucket[k].x = targetX;
    foodBucket[k].y = targetY;
    foodBucket[k].isSpecial = isSpecial;

    // Increment filledSpots only if the generated food is not special
    if (!isSpecial) {
        filledSpots++;
    }
}

bool Food::isSpecialFood() 
{
    // Determine if the current food should be special based on pre-generated indices
    for (int i = 0; i < SPECIAL_FOOD_COUNT; i++) {
        if (filledSpots == specialFoodIndices[i]) {
            return true;
        }
    }
    return false;
}

void Food::generateSpecialFoodIndices() 
{

    // Randomly choose indices to assign as special food
    for (int i = 0; i < SPECIAL_FOOD_COUNT; i++) {
        specialFoodIndices[i] = rand() % SIZE_BUCKET;
    }
}

void Food::getFoodPos(objPos returnPos[]) 
{

    // Copy food positions from foodBucket into the returnPos array
    for (int i = 0; i < filledSpots; ++i) {
        returnPos[i] = foodBucket[i];
    }
}

