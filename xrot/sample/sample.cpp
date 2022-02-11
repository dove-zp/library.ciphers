/**
 * \brief cipher.xrot.sample - XOR-ROT samples
 * \author dove-zp
 * \contact https://github.com/dove-zp
 * \version 2018/AUG/01
 * \license MIT License (Expat) 
 */


#include "xrot.h"

#include <iostream>

//--------------------------------------------------------------------------------------------------

void main()
{
    cipher::xrot rnd_xrt;

    std::vector<unsigned char> rnd_encoded = rnd_xrt.encrypt("kernel32.dll");

    std::cout << "encoded: " << std::string(rnd_encoded.begin(), rnd_encoded.end()) << std::endl;

    std::cout << "decoded: " << rnd_xrt.decrypt(rnd_encoded) << std::endl;

    std::cout << "xor key: " << (int) rnd_xrt.get_key()[0] << std::endl;

    std::cout << "rotate shift: " << (int)rnd_xrt.get_key()[1] << std::endl;

    std::cout << "-------------------------------------" << std::endl;

    cipher::xrot str_xrt("42");

    std::vector<unsigned char> str_encoded = str_xrt.encrypt("kernel32.dll");

    std::cout << "encoded: " << std::string(str_encoded.begin(), str_encoded.end()) << std::endl;

    std::cout << "decoded: " << str_xrt.decrypt(str_encoded) << std::endl;

    std::cout << "-------------------------------------" << std::endl;

    cipher::xrot shrt_xrt(42);

    std::vector<unsigned char> shrt_encoded = shrt_xrt.encrypt("kernel32.dll");

    std::cout << "encoded: " << std::string(shrt_encoded.begin(), shrt_encoded.end()) << std::endl;

    std::cout << "decoded: " << shrt_xrt.decrypt(shrt_encoded) << std::endl;

    std::cout << "-------------------------------------" << std::endl;

    std::vector<unsigned char> x = { 127, 30 };
    cipher::xrot vtr_xrt(x);

    std::vector<unsigned char> vtr_encoded = vtr_xrt.encrypt("kernel32.dll");

    std::cout << "encoded: " << std::string(vtr_encoded.begin(), vtr_encoded.end()) << std::endl;

    std::cout << "decoded: " << vtr_xrt.decrypt(vtr_encoded) << std::endl;

    system("pause");
}