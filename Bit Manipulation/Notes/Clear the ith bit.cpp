int clearBit(int num, int k){
    return (~(1 << k)) & num;
}



//For 7 => 111, I want to clear the second bit, i.e change it to 101.
//To do that I can left shift 1 by two bits, then do not operation (~), which flips everything and then do an
//AND operation. Do a dry run to understand