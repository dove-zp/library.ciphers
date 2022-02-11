/**
 * \brief cipher.xas - XOR-ADD-SUB Encryption and Decryption
 * \author dove-zp
 * \contact https://github.com/dove-zp
 * \version 2018/AUG/01
 * \license MIT License (Expat) 
 */


#pragma once

#include <vector>

//--------------------------------------------------------------------------------------------------

namespace cipher
{
    class xas
    {
    public:
        enum OP : unsigned char
        {
            XOR = 0,
            ADD = 1,
            SUB = 2
        };

#pragma pack(push, 1)
        struct DESCRIPTOR
        {
            OP operation_code;
            unsigned char operation_parameter;
            unsigned int operation_length;
        };

        /**
         * \brief encoding xas cipher
         * \param input plain text input
         * \param key used as rules to determine how to encrypt the cipher
         */
        static void encrypt(std::vector<unsigned char>& input, std::vector<DESCRIPTOR> key);

        /**
         * \brief decoding xas cipher
         * \param input encryptd text input
         * \param key used as rules to determine how to decrypt the cipher
         */
        static void decrypt(std::vector<unsigned char>& input, std::vector<DESCRIPTOR> key);

        /**
         * \brief parse key from char vector to vector with DESCRIPTORs
         * \param product char vector to parse from
         * \param key parse product to key
         * \return return true on success or false on error
         */
        static bool parse_key(std::vector<unsigned char> const& product, std::vector<DESCRIPTOR>& key);

        private:
        /**
         * \brief creates a new inverted key based off of original key
         * \param key to inverse
         * \return interverted key
         */
        static std::vector<DESCRIPTOR> inverse_key(std::vector<DESCRIPTOR> key);

        /**
         * \brief steps through each character in input and applies shift according to key
         * \param value input to crypt
         * \param descriptor rules to follow for crypting
         * \return crypted value
         */
        static unsigned char step(unsigned char value, DESCRIPTOR const& descriptor);

        /**
         * \brief two-way cipher for both encoding and decoding
         * \param input values to crypt
         * \param key used to encrypt or decrypt
         */
        static void crypt(std::vector<unsigned char>& input, std::vector<DESCRIPTOR> const& key);
    };
}
