#include <stdio.h>
#include "BMP180.h"

int main()
{
    BMP180 myBMP = BMP180(1, 0x40, BMP180_ULTRAHIGHRES);

    return 0; 
}
