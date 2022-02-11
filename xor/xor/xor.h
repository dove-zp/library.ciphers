/**
 * \brief cipher.xor - XOR Encryption and Decryption
 * \author dove-zp
 * \contact https://github.com/dove-zp
 * \version 2018/AUG/01
 * \license MIT License (Expat) 
 */

#pragma once

#include <string>
#include <array>

//--------------------------------------------------------------------------------------------------

namespace cipher
{

    //----------------------------------------------------------------------------------------------
    // NOTE: XOR                                                                (LOCATION MARK) TODO
    //----------------------------------------------------------------------------------------------

    class xor
    {
    public:
        xor();
        xor(std::string key);

        ~xor();

        std::string get_key();
        void set_key(std::string key);

        std::string encrypt(std::string input);
        std::string decrypt(std::string input);

    private:
        std::string key_;

        void encrypt(std::string input, std::string &output);
        void decrypt(std::string input, std::string &output);
    };

    //----------------------------------------------------------------------------------------------
    // NOTE: XOR::META                                                          (LOCATION MARK) TODO
    //----------------------------------------------------------------------------------------------

    //----------------------------------------------------------------------------------------------
    // NOTE: XOR::TEMPLATE                                                      (LOCATION MARK) TODO
    //----------------------------------------------------------------------------------------------

    namespace tpl
    {
        template <typename, typename>
        class __XOR_t;

        template <typename Char, std::size_t ... Characters>
        class __XOR_t<Char, std::index_sequence<Characters...>>
        {
        public:
            constexpr __XOR_t(Char const * const String): value_{ Char(String[Characters] ^ (xor_key_ + Characters))... } {}

            constexpr std::array<Char, sizeof...(Characters)+1U> decrypt() const
            {
                return{ { Char(value_[Characters] ^ (xor_key_ + Characters)) ..., Char(0) } };
            }

            Char const * encrypt() const
            {
                return value_;
            }
        private:
            Char value_[sizeof...(Characters)+1U];

            // TODO: import tpl random generator() <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
            static constexpr Char xor_key_ = Char(static_cast<unsigned __int16>(tpl::rand(0xF, 0xFFFF)));
        };

        template <typename T, std::size_t N>
        constexpr auto xor(T(&str)[N])
        {
            return __XOR_t<T, decltype(std::make_index_sequence<N - 1U>{})>(str);
        }
    }
}