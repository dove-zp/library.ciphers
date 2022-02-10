/**
 * \brief cipher.rc4 - RC4 Encryption and Decryption
 * \author dove-zp
 * \contact https://github.com/dove-zp
 * \version 2018/AUG/01
 * \license MIT License (Expat) 
 */

#include "rc4.h"

#include <algorithm>

//--------------------------------------------------------------------------------------------------

/**
 * \brief constructor should not need anything
 */
cipher::rc4::rc4()
{
}

/**
 * \brief destructor fills the swap box with zeros
 */
cipher::rc4::~rc4()
{
    std::fill_n(swap_box_, sizeof(swap_box_), 0x00);
}

/**
 * \brief encodes the given message
 * \param input the original message
 * \param key used to encrypt and decrypt the message
 * \return the encoded string
 */
std::string cipher::rc4::encrypt(std::string input, std::string key)
{
    std::string output;
    std::string encoded;
    init(key);
    stream(input, output);
    for (unsigned int i = 0; i < input.length(); i++)
    {
        encoded.push_back(output[i] ^ input[i]);
    }
    return encoded;
}

/**
 * \brief decodes the given message
 * \param input the encrypted message
 * \param key used to encrypt and decrypt the message
 * \return the decoded string
 */
std::string cipher::rc4::decrypt(std::string input, std::string key)
{
    std::string output;
    std::string decoded;
    init(key);
    stream(input, output);
    for (unsigned int i = 0; i < input.length(); i++)
    {
        decoded.push_back(output[i] ^ input[i]);
    }
    return decoded;
}

/**
 * \brief creates the swapbox with the key
 * \param key used to encrypt and decrypt the message
 */
void cipher::rc4::init(std::string key)
{
    // KSA
    generate_swap_box();
    for (unsigned int i = 0, j = 0; i < sizeof(swap_box_); i++)
    {
        j = (j + swap_box_[i] + key.at(i % key.length())) % sizeof(swap_box_);
        std::swap(swap_box_[i], swap_box_[j]);
    }
}

/**
 * \brief creates the encoded message
 * \param input the input message
 * \param output the output message
 */
void cipher::rc4::stream(std::string input, std::string& output)
{
    // PRGA
    for (unsigned int x = 0, i = 0, j = 0; x < input.length(); x++)
    {
        i = (i + 1) % sizeof(swap_box_);
        j = (j + swap_box_[i]) % sizeof(swap_box_);
        std::swap(swap_box_[i], swap_box_[j]);
        output.push_back(swap_box_[(swap_box_[i] + swap_box_[j]) % sizeof(swap_box_)]);
    }
}

/**
 * \brief genereates the swapbox by filling with zeros then itterating
 */
void cipher::rc4::generate_swap_box()
{
    std::fill_n(swap_box_, sizeof(swap_box_), 0x00);
    for (int i = 0; i < sizeof(swap_box_); i++)
    {
        swap_box_[i] = i;
    }
}
