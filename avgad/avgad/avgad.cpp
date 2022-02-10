/**
 * \brief cipher.avgad - Avgad Encryption and Decryption
 * \author dove-zp
 * \contact https://github.com/dove-zp
 * \version 2018/AUG/01
 * \license MIT License (Expat) 
 */

#include "avgad.h"

//--------------------------------------------------------------------------------------------------

/**
 * \brief a simple way to return the alphabet size
 * \return the alphabet size of 26
 */
unsigned int get_alpha_size()
{
    return 26;
}

/**
 * \brief a simple way to determine the reference point
 * \param c the input character to check
 * \return depending on the case it will return 'A' or 'a' as the reference point character
 */
char refa(unsigned char c)
{
    return islower(c) ? 0x61 : 0x41;
}

/**
 * \brief decodes the given avgad cipher
 * \param input the string which is encoded
 * \param output reference to decoded text string
 */
void decrypt(std::string input, std::string &output)
{
    for (char i : input)
    {
        output.push_back(isalpha(i) ? ((i - refa(i) == 0) ? (get_alpha_size() - 1) + refa(i) : ((i - refa(i) - 1) % get_alpha_size()) + refa(i)) : i);
    }
}

/**
 * \brief encodes the given avgad cipher
 * \param input the string which is to be encoded
 * \param output reference to encoded text string
 */
void encrypt(std::string input, std::string &output)
{
    for (char i : input)
    {
        output.push_back(isalpha(i) ? ((i - refa(i) + 1) % get_alpha_size()) + refa(i) : i);
    }
}

/**
 * \brief default constructor
 */
cipher::avgad::avgad()
{
}

/**
 * \brief default deconstructor
 */
cipher::avgad::~avgad()
{
}

/**
 * \brief uses to decrypt the input
 * \param input the string which is encoded
 * \return the decoded string
 */
std::string cipher::avgad::decrypt(std::string input)
{
    std::string output;
    ::decrypt(input, output);
    return output;
}

/**
 * \brief used to encrypt the input
 * \param input the string which is to be encoded
 * \return the encoded string
 */
std::string cipher::avgad::encrypt(std::string input)
{
    std::string output;
    ::encrypt(input, output);
    return output;
}
