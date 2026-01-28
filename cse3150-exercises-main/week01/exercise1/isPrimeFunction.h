#ifndef __ISPRIMEFUNCTION_H
#define __ISPRIMEFUNCTION_H

bool isPrimeInteger(int pTest) {
    if (pTest < 2) {
        return false;
    }

    if (pTest == 2) {
        return true;
    }
    
    if (pTest % 2 == 0) {
        return false;
    }



    bool isPrime = true;

    for (int i = 3; i < pTest; i++) {
        if (pTest % i == 0) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

#endif
