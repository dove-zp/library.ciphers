/**
 * \brief cipher.atbash - Atbash Encryption and Decryption
 * \author dove-zp
 * \contact https://github.com/dove-zp
 * \version 2018/AUG/01
 * \license MIT License (Expat) 
 */


#include "atbash.h"

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
 * \brief decodes the given atbash cipher
 * \param input the string which is encoded
 * \param output reference to decoded text string
 */
void decrypt(std::string input, std::string &output)
{
    for (char i : input)
    {
        output.push_back(isalpha(i) ? ((get_alpha_size() - 1) * (i - refa(i) + 1) % get_alpha_size()) + refa(i) : i);
    }
}

/**
 * \brief encodes the given atbash cipher
 * \param input the string which is to be encoded
 * \param output reference to encoded text string
 */
void encrypt(std::string input, std::string &output)
{
    for (char i : input)
    {
        output.push_back(isalpha(i) ? (((get_alpha_size() - 1) * (i - refa(i)) + (get_alpha_size() - 1)) % get_alpha_size()) + refa(i) : i);
    }
}

/**
 * \brief default constructor
 */
cipher::atbash::atbash()
{
}

/**
 * \brief default deconstructor
 */
cipher::atbash::~atbash()
{
}

/**
 * \brief used to decrypt the input
 * \param input the string which is encoded
 * \return the decoded string
 */
std::string cipher::atbash::decrypt(std::string input)
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
std::string cipher::atbash::encrypt(std::string input)
{
    std::string output;
    ::encrypt(input, output);
    return output;
}