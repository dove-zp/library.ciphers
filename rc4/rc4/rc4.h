/**
 * \brief cipher.rc4 - RC4 Encryption and Decryption
 * \author dove-zp
 * \contact https://github.com/dove-zp
 * \version 2018/AUG/01
 * \license MIT License (Expat) 
 */

#pragma once

#include <string>

//--------------------------------------------------------------------------------------------------

namespace cipher
{
    class rc4
    {
    public:

        /**
         * \brief constructor should not need anything
         */
        rc4();

        /**
         * \brief destructor fills the swap box with zeros
         */
        ~rc4();

        /**
         * \brief encodes the given message
         * \param input the original message
         * \param key used to encrypt and decrypt the message
         * \return the encoded string
         */
        std::string encrypt(std::string input, std::string key);

        /**
         * \brief decodes the given message
         * \param input the encrypted message
         * \param key used to encrypt and decrypt the message
         * \return the decoded string
         */
        std::string decrypt(std::string input, std::string key);

    private:
        unsigned char swap_box_[256] = {0};
        
        /**
         * \brief creates the swapbox with the key
         * \param key used to encrypt and decrypt the message
         */
        void init(std::string key);

        /**
         * \brief creates the encoded message
         * \param input the input message
         * \param output the output message
         */
        void stream(std::string input, std::string& output);

        /**
         * \brief genereates the swapbox by filling with zeros then itterating
         */
        void generate_swap_box();
    };
}
