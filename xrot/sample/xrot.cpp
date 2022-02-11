/**
 * \brief cipher.xrot - XOR-ROT Encryption and Decryption
 * \author dove-zp
 * \contact https://github.com/dove-zp
 * \version 2018/AUG/01
 * \license MIT License (Expat) 
 */


#include "xrot.h"

#include <random>
#include <iterator>
#include <algorithm>

//--------------------------------------------------------------------------------------------------

cipher::xrot::xrot() : xrot(this->random())
{
}

cipher::xrot::xrot(std::vector<unsigned char> key)
{
    this->set_key(key);
}

cipher::xrot::xrot(std::string key)
{
    this->set_key(key);
}

cipher::xrot::xrot(unsigned char key)
{
    this->set_key(std::to_string(key));
}

void cipher::xrot::set_key(std::vector<unsigned char> key)
{
    this->key_.clear();
    this->key_ = key;
}

void cipher::xrot::set_key(std::string key)
{
    this->key_.clear();
    std::copy(key.c_str(), key.c_str() + key.length(), std::back_inserter(key_));
}

std::vector<unsigned char> cipher::xrot::get_key()
{
    return this->key_;
}

std::vector<unsigned char> cipher::xrot::encrypt(std::string plain_text)
{
    std::vector<unsigned char> result;

    const unsigned char xor_key = this->key_[0];
    const unsigned char number_of_bits_to_rotate = this->key_[1];

    std::transform(plain_text.begin(), plain_text.end(), std::back_inserter(result), [&](const unsigned char byte) -> int
    {
        const unsigned char xored = byte ^ xor_key;
        const unsigned char shifted = _rotl8(xored, number_of_bits_to_rotate);

        return shifted;
    });

    return result;
}

std::string cipher::xrot::decrypt(std::vector<unsigned char> cipher_text)
{
    std::vector<unsigned char> result;

    const unsigned char xor_key = this->key_[0];
    const unsigned char number_of_bits_to_rotate = this->key_[1];

    std::transform(cipher_text.cbegin(), cipher_text.cend(), std::back_inserter(result), [&](const unsigned char byte) -> int
    {
        const unsigned char shifted = _rotr8(byte, number_of_bits_to_rotate);
        const unsigned char xored = shifted ^ xor_key;

        return xored;
    });

    return std::string(result.begin(), result.end());
}

std::vector<unsigned char> cipher::xrot::random()
{
    std::random_device random_d;
    std::mt19937 generate{ random_d() };
    std::uniform_int_distribution<uint32_t> get_random;
    std::vector<unsigned char> random_vector;

    for (int i = 0; i < 2; i++)
    {
        random_vector.push_back(static_cast<unsigned char>(get_random(generate)));
    }

    return random_vector;
}
