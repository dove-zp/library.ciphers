/**
 * \brief cipher.affine - Affine Encryption and Decryption
 * \author dove-zp
 * \contact https://github.com/dove-zp
 * \version 2018/AUG/01
 * \license MIT License (Expat) 
 */

#include "affine.h"

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
 * \brief a recursive function to obtain the gcd from the target with a given value
 * \param value given value to find gcd with
 * \param target the target to get the gcd from
 * \return the gcd value
 */
int gcd(int value, int target)
{
    if (value % target == 0)
    {
        return target;
    }
    return gcd(target, value % target);
}

/**
 * \brief obtains the inverse from the key using a modular compare
 * \param key the multi key to find the inverse of
 * \return the inverse or one to keep the cipher functional since the multi key cannot be zero
 */
int get_inverse(int key)
{
    int invert = 0;
    for (unsigned int i = 1; i < get_alpha_size(); i++)
    {
        if (((key * i) % get_alpha_size()) == 1)
        {
            invert = i;
        }
    }
    return invert;
}

/**
 * \brief decrypts the given affine cipher
 * \param input the string which is encryptd
 * \param key the multi key
 * \param shift the shift key
 * \param output reference to decryptd text string
 */
void decrypt(std::string input, unsigned int key, unsigned int shift, std::string &output)
{
    for (char i : input)
    {
        output.push_back(isalpha(i) ? (get_inverse(key) * (i - refa(i) + (get_alpha_size() - shift)) % get_alpha_size()) + refa(i) : i);
    }
}

/**
 * \brief encrypts the given affine cipher
 * \param input the string which is to be encryptd
 * \param key the multi key
 * \param shift the shift key
 * \param output reference to encryptd text string
 */
void encrypt(std::string input, unsigned int key, unsigned int shift, std::string &output)
{
    for (char i : input)
    {
        output.push_back(isalpha(i) ? ((key * (i - refa(i)) + shift) % get_alpha_size()) + refa(i) : i);
    }
}

/**
 * \brief this default constructor sets the default magic numbers here
 */
cipher::affine::affine()
{
    set_key(1);
    set_shift(13);
}

/**
 * \brief this constructor allows the user to set the default shift key where the multi key is 1
 * \param shift the new default shift
 */
cipher::affine::affine(unsigned shift) : affine()
{
    set_shift(shift);
}

/**
 * \brief this constructor allows the user to set the default multi and shift key
 * \param key the new default multi key
 * \param shift the new default shift
 */
cipher::affine::affine(unsigned key, unsigned shift) : affine()
{
    set_key(key);
    set_shift(shift);
}

/**
 * \brief default deconstructor
 */
cipher::affine::~affine()
{
}

/**
 * \brief sets the default multi key and checks if is valid
 * \param key the new default multi key
 */
void cipher::affine::set_key(unsigned int key)
{
    if ((key >= get_alpha_size()) || (key < 1))
    {
        throw std::exception("<!> error: key is an invalid size\n");
    }
    if (gcd(key, get_alpha_size()) != 1)
    {
        throw std::exception("<!> error: key is an invalid size\n");
    }
    this->key_ = key;
}

/**
 * \brief sets the default shift key and checks if is valid
 * \param shift the new default shift key
 */
void cipher::affine::set_shift(unsigned int shift)
{
    if (shift >= get_alpha_size())
    {
        throw std::exception("<!> error: shift is an invalid size\n");
    }
    this->shift_ = shift;
}

/**
 * \brief uses the default multi and shift key to encrypt the input
 * \param input the string which is to be encryptd
 * \return the encryptd string
 */
std::string cipher::affine::encrypt(std::string input)
{
    std::string output;
    ::encrypt(input, this->key_, this->shift_, output);
    return output;
}

/**
 * \brief uses the default multi and shift key to decrypt the input
 * \param input the string which is encryptd
 * \return the decryptd string
 */
std::string cipher::affine::decrypt(std::string input)
{
    std::string output;
    ::decrypt(input, this->key_, this->shift_, output);
    return output;
}
