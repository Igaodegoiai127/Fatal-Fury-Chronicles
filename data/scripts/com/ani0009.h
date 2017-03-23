int ani0009(void vTarget, int iAni, int iType)
{
    //Set animation and return 1 if valid.

    if (getentityproperty(vTarget, "animvalid", iAni))          //Animation valid?
    {
        if (iType == -1)                                        //Type -1?
        {
            changeentityproperty(vTarget, "animation", iAni);   //Set animation with entity property.
        }
        else
        {
            performattack(vTarget, iAni, iType);                //Set animation with perform attack command.
        }
        return 1;                                               //Return 1.

        changeplayerproperty(vTarget, "playkeys", 0);           //Clear key event.
    }
    return 0;
}

