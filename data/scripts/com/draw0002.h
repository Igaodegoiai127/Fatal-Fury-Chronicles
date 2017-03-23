
int draw0002(float fRatio, float fVector){    

    /*
    draw0002
    Damon Vaughn Caskey
    05/30/2008
    Returns whole integer from incoming location vector after applying fRatio. Primarly for integrating scaling (see draw0001)
    with bind function (which must be given whole numbers for location offsets).

    fRatio: Ratio to apply. WIll almost always be the current scale ratio of a caller.
    fVector:   Vector to be scaled and rounded.
    */

    int iNeg = 0; //Negative flag.
    
    //Negative number? If so, the conversions below won't work. Temporarily convert to positive integer.
    if (fVector < 0){
        iNeg    = 1;            //Set negative flag.
        fVector = fVector * -1; //Convert to positive integer.
    }

    fVector += 0.0;                //Vector must be a float, convert here to make sure.
    fVector *= fRatio;             //Apply scale ratio.
    fVector %= (++fVector);        //Remove decimal (binds fail if not passed a whole integer).
    if (!fVector) { fVector = 1; } //If calculation produces 0, set to 1.
    
    //Vector was a temporary posative. Convert back to negative.
    if (iNeg){
        fVector = -fVector; //Convert to negative integer.
    }

    return fVector; //Return value.
}
