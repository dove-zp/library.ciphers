/**
 * \brief cipher.avgad - Avgad Encryption and Decryption
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
    class avgad
    {
    public:

        /**
         * \brief default constructor
         */
        avgad();
        
        /**
         * \brief default deconstructor
         */
        ~avgad();

        /**
         * \brief uses to decrypt the input
         * \param input the string which is encoded
         * \return the decoded string
         */
        std::string decrypt(std::string input);

        /**
         * \brief used to encrypt the input
         * \param input the string which is to be encoded
         * \return the encoded string
         */
        std::string encrypt(std::string input);
    };
}
