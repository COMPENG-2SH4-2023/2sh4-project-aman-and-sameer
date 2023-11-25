#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    sizeList = 0;
    sizeArray = ARRAY_MAX_CAP;

}

objPosArrayList::~objPosArrayList()
{
    // destructor
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    
    if (sizeList < ARRAY_MAX_CAP)
    {   for (int i = sizeList; i > 0; i--)
        {
            aList[i].setObjPos(aList[i-1]); // shuffle all elements to the tail! (towards the right/top)
                                            // overrides previous element w/ current element
        }

        aList[0].setObjPos(thisPos); // inserts incoming element into first position

        sizeList++; // since we're adding a new element to the list sizeList must therefore increase 
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    aList[sizeList].setObjPos(thisPos); // no need to shuffle elements
    sizeList++; // you were iterating before you assigned a position so there was always 1 empty slot!
}

void objPosArrayList::removeHead()
{
    if (sizeList > 0)
    {
        for(int i = 0; i < sizeList - 1; i++)
        {
            aList[i].setObjPos(aList[i+1]);
        }
    }

    sizeList--;
}

void objPosArrayList::removeTail()
{
    sizeList--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[sizeList - 1]);

}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}