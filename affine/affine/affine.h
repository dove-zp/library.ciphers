/**
 * \brief cipher.affine - Affine Encryption and Decryption
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
    class affine
    {
    private:

        /**
         * \brief default key value
         */
        unsigned int key_{};

        /**
         * \brief default shift value
         */
        unsigned int shift_{};

    public:
        /**
         * \brief this default constructor sets the default magic numbers here
         */
        affine();

        /**
         * \brief this constructor allows the user to set the default shift key where the multi key is 1
         * \param shift the new default shift
         */
        affine(unsigned int shift);

        /**
         * \brief this constructor allows the user to set the default multi and shift key
         * \param key the new default multi key
         * \param shift the new default shift
         */
        affine(unsigned int key, unsigned int shift);

        /**
         * \brief default deconstructor
         */
        ~affine();

        /**
         * \brief sets the default multi key and checks if is valid
         * \param key the new default multi key
         */
        void set_key(unsigned int key);
        
        /**
         * \brief sets the default shift key and checks if is valid
         * \param shift the new default shift key
         */
        void set_shift(unsigned int shift);
        
        /**
         * \brief uses the default multi and shift key to encrypt the input
         * \param input the string which is to be encryptd
         * \return the encryptd string
         */
        std::string encrypt(std::string input);

        /**
         * \brief uses the default multi and shift key to decrypt the input
         * \param input the string which is encryptd
         * \return the decryptd string
         */
        std::string decrypt(std::string input);
    };
}
