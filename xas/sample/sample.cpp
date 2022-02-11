/**
 * \brief cipher.xas.sample - XOR-ADD-SUB Encryption and Decryption sample
 * \author dove-zp
 * \contact https://github.com/dove-zp
 * \version 2018/AUG/01
 * \license MIT License (Expat) 
 */


#include "xas.h"

#include <string>
#include <iostream>
#include <vector>

//--------------------------------------------------------------------------------------------------

void main()
{
    std::string text_string = "kernel32.dll";
    std::vector<unsigned char> text_vector(text_string.begin(), text_string.end());


    cipher::xas::encrypt(text_vector, {  { cipher::xas::OP::ADD, 1, 2 },
                                        { cipher::xas::OP::XOR, 3, 4 },
                                        { cipher::xas::OP::SUB, 5, 6 } });

    std::cout << "expected input  : " << text_string << std::endl;
    std::cout << "expected result : lfqmfo.-)_gg" << std::endl;
    std::cout << "encrypted result: " << std::string(text_vector.begin(), text_vector.end()) << std::endl << std::endl;


    cipher::xas::decrypt(text_vector, {  { cipher::xas::OP::ADD, 1, 2 },
                                        { cipher::xas::OP::XOR, 3, 4 },
                                        { cipher::xas::OP::SUB, 5, 6 } });

    std::cout << "expected input  : lfqmfo.-)_gg" << std::endl;
    std::cout << "expected result : " << text_string << std::endl;
    std::cout << "decrypted result: " << std::string(text_vector.begin(), text_vector.end()) << std::endl << std::endl;


    system("pause");
}