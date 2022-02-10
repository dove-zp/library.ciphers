/**
 * \brief cipher.caesar - Caesar Encryption and Decryption
 * \author dove-zp
 * \contact https://github.com/dove-zp
 * \version 2018/AUG/01
 * \license MIT License (Expat) 
 */

#include "caesar.h"

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
unsigned char refa(unsigned char c)
{
    return islower(c) ? 0x61 : 0x41;
}

/**
 * \brief decodes the given caesar cipher
 * \param input the string which is encoded
 * \param shift the shift key
 * \param output reference to decoded text string
 */
void decrypt(std::string input, unsigned int shift, std::string &output)
{
    for (char i : input)
    {
        output.push_back(isalpha(i) ? (i - refa(i) + (get_alpha_size() - shift)) % get_alpha_size() + refa(i) : i);
    }
}

/**
 * \brief encodes the given caesar cipher
 * \param input the string which is to be encoded
 * \param shift the shift key
 * \param output reference to encoded text string
 */
void encrypt(std::string input, unsigned int shift, std::string &output)
{
    for (char i : input)
    {
        output.push_back(isalpha(i) ? (i - refa(i) + shift) % get_alpha_size() + refa(i) : i);
    }
}

/**
 * \brief this default constructor sets the default magic numbers here
 */
cipher::caesar::caesar()
{
    set_shift(13);
}

/**
 * \brief this constructor allows the user to set the default shift key
 * \param shift the new default shift key
 */
cipher::caesar::caesar(unsigned int shift) : caesar()
{
    set_shift(shift);
}

/**
 * \brief default deconstructor
 */
cipher::caesar::~caesar()
{
}

/**
 * \brief sets the default shift key and checks if is valid
 * \param shift the new default shift key
 */
void cipher::caesar::set_shift(unsigned int shift)
{
    if (shift >= get_alpha_size())
    {
        throw std::exception("<!> error: shift size is greater than or is the same as the alphabet size!\n");
    }
    shift_ = shift;
}

/**
 * \brief used to encrypt the input
 * \param input the string which is to be encoded
 * \return the encoded string
 */
std::string cipher::caesar::encrypt(std::string input)
{
    std::string output;
    ::encrypt(input, shift_, output);
    return output;
}

/**
 * \brief used to decrypt the input
 * \param input the string which is encoded
 * \return the decoded string
 */
std::string cipher::caesar::decrypt(std::string input)
{
    std::string output;
    ::decrypt(input, shift_, output);
    return output;
}
