/**
 * \brief cipher.xor - XOR Encryption and Decryption
 * \author dove-zp
 * \contact https://github.com/dove-zp
 * \version 2018/AUG/01
 * \license MIT License (Expat) 
 */

#include "xor.h"
#include <random>

//--------------------------------------------------------------------------------------------------

cipher::xor::xor() : xor(std::to_string(__rdtsc()))
{
}

cipher::xor::xor(std::string key)
{
    set_key(key);
}

cipher::xor::~xor()
{
}

std::string cipher::xor::get_key()
{
    return this->key_;
}

void cipher::xor::set_key(std::string key)
{
    this->key_ = key;
}

std::string cipher::xor::encrypt(std::string input)
{
    std::string output;
    encrypt(input, output);
    return output;
}

std::string cipher::xor::decrypt(std::string input)
{
    std::string output;
    decrypt(input, output);
    return output;
}

void cipher::xor::encrypt(std::string input, std::string& output)
{
    for (unsigned int i = 0, key_index = 0; i < input.length(); i++)
    {
        output.push_back(input.at(i) ^ this->key_[key_index++]);
        if (key_index == this->key_.length())
        {
            key_index = 0;
        }
    }
}

void cipher::xor::decrypt(std::string input, std::string& output)
{
    for (unsigned int i = 0, key_index = 0; i < input.length(); i++)
    {
        output.push_back(input.at(i) ^ this->key_[key_index++]);
        if (key_index == this->key_.length())
        {
            key_index = 0;
        }
    }
}
