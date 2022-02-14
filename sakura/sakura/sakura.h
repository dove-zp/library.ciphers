/**
 * \brief cipher.sakura - SAKURA Encryption and Decryption
 * \author dove-zp
 * \version 3/JUN/2019
 * \license MIT License (Expat)
 */

#pragma once

#include <cstdint>

//--------------------------------------------------------------------------------------------------

namespace cipher
{
	class sakura
	{
	public:

		sakura();

		~sakura();


		static bool decrypt(void* buffer, size_t length, uint8_t* key, uint8_t* iv);

		static bool encrypt(void* buffer, size_t length, uint8_t* key, uint8_t* iv);

	private:
		static void* padding(void* buffer, size_t length, uint32_t* aligns);

		static void xor_block(void* buffer, uint8_t* key);

		static void encrypt_block(void* buffer, uint8_t* key);

		static void decrypt_block(void* buffer, uint8_t* key);
	};
}
