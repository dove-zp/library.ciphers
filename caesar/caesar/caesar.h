/**
 * \brief cipher.caesar - Caesar Encryption and Decryption
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
    class caesar
    {
    private:
        /**
         * \brief default shift value
         */
        unsigned int shift_;

    public:

        /**
         * \brief this default constructor sets the default magic numbers here
         */
        caesar();

        /**
         * \brief this constructor allows the user to set the default shift key
         * \param shift the new default shift key
         */
        caesar(unsigned int shift);

        /**
         * \brief default deconstructor
         */
        ~caesar();

        /**
         * \brief sets the default shift key and checks if is valid
         * \param shift the new default shift key
         */
        void set_shift(unsigned int shift);

        /**
         * \brief used to encrypt the input
         * \param input the string which is to be encoded
         * \return the encoded string
         */
        std::string encrypt(std::string input);
        
        /**
         * \brief used to decrypt the input
         * \param input the string which is encoded
         * \return the decoded string
         */
        std::string decrypt(std::string input);


    };
}
