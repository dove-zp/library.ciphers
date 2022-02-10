/**
 * \brief cipher.albam - Albam Encryption and Decryption
 * \author dove-zp
 * \contact https://github.com/dove-zp
 * \version 2018/AUG/01
 * \license MIT License (Expat) 
 */

#include "albam.h"

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
 * \brief decodes the given albam cipher
 * \param input the string which is encoded
 * \param output reference to decoded text string
 */
void decrypt(std::string input, std::string &output)
{
    for (int i = 0; i < input.length(); i++)
    {
        output.push_back(isalpha(input.at(i)) ? (((input.at(i) - refa(input.at(i))) + (get_alpha_size() / 2)) % get_alpha_size()) + refa(input.at(i)) : input.at(i));
    }
}

/**
 * \brief encodes the given albam cipher
 * \param input the string which is to be encoded
 * \param output reference to encoded text string
 */
void encrypt(std::string input, std::string &output)
{
    for (int i = 0; i < input.length(); i++)
    {
        output.push_back(isalpha(input.at(i)) ? (((input.at(i) - refa(input.at(i))) + (get_alpha_size() / 2)) % get_alpha_size()) + refa(input.at(i)) : input.at(i));
    }
}

/**
 * \brief default constructor
 */
cipher::albam::albam()
{
}

/**
 * \brief default deconstructor
 */
cipher::albam::~albam()
{
}

/**
 * \brief uses the default multi and shift key to encrypt the input
 * \param input the string which is to be encoded
 * \return the encoded string
 */
std::string cipher::albam::encrypt(std::string input)
{
    std::string output;
    ::encrypt(input, output);
    return output;
}

/**
 * \brief uses the default multi and shift key to decrypt the input
 * \param input the string which is encoded
 * \return the decoded string
 */
std::string cipher::albam::decrypt(std::string input)
{
    std::string output;
    ::decrypt(input, output);
    return output;
}
