#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

#define SIZE_BUCKET 5


class Food
{
    private:
        objPosArrayList* foodBucket;

        

    public:
        Food();
        ~Food();

        void generateFood(blockOff:objPos);
        bool isSpecialFood();
        void generateSpecialFoodIndices();
        void getFoodPos(returnPos:&objPos);
};

#endif