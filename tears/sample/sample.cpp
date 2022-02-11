/**
* \brief cipher.tears.sample - simple tear cipher examples
 * \author dove-zp
 * \contact https://github.com/dove-zp
 * \version 2018/AUG/01
 * \license MIT License (Expat) 
 */


#include <string>
#include <cstdlib>
#include <iostream>

#include "../tears/tears.h"
#include "../tears/bad_tears.h"

//--------------------------------------------------------------------------------------------------

void main()
{

    cipher::tears<int> int_trs;
    int int_encoded = int_trs.encrypt(0x100);
    std::cout << "0x100 == 0x" << std::hex << int_trs.decrypt(int_encoded) << std::endl;

    cipher::bad_tears<uint32_t> uint_trs;
    uint32_t uint_encoded = uint_trs.encrypt(0x1A1);
    std::cout << "0x1a1 == 0x" << std::hex << uint_trs.decrypt(uint_encoded) << std::endl;

    system("pause");
}
