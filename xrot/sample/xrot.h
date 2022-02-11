/**
 * \brief cipher.xrot - XOR-ROT Encryption and Decryption
 * \author dove-zp
 * \contact https://github.com/dove-zp
 * \version 2018/AUG/01
 * \license MIT License (Expat) 
 */


#pragma once

#include <string>
#include <vector>

//--------------------------------------------------------------------------------------------------

namespace cipher
{
    class xrot
    {
    public:
        xrot();

        xrot(std::vector<unsigned char> key);

        xrot(std::string key);

        xrot(unsigned char key);

        void set_key(std::vector<unsigned char> key);

        void set_key(std::string key);

        std::vector<unsigned char> get_key();

        std::vector<unsigned char> encrypt(std::string plain_text);

        std::string decrypt(std::vector<unsigned char> cipher_text);

    private:
        std::vector<unsigned char> key_;

        std::vector<unsigned char> random();
    };
}
