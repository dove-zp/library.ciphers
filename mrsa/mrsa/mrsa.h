/**
 * \brief cipher.mrsa - Mini RSA
 * \author dove-zp
 * \version 2/JUN/2019
 * \license MIT License (Expat)
 */

#pragma once

#include <vector>
#include <string>

//--------------------------------------------------------------------------------------------------

namespace cipher
{
	class mrsa
	{
	public:
		mrsa();
		mrsa(std::pair<uint32_t, uint32_t> private_key, std::pair<uint32_t, uint32_t> public_key);

		uint32_t encrypt(uint32_t value, std::pair<uint32_t, uint32_t> public_key);
		uint32_t decrypt(uint32_t value, std::pair<uint32_t, uint32_t> private_key);

		uint32_t* encrypt(std::string message, std::pair<uint32_t, uint32_t> public_key);
		std::string decrypt(uint32_t* message, std::pair<uint32_t, uint32_t> private_key);

		std::pair<uint32_t, uint32_t> get_private_key() const;
		std::pair<uint32_t, uint32_t> get_public_key() const;

	private:
		void init();
		void generate_primes();

		void generate_public_key();
		void generate_private_key();

		uint32_t crypt(uint32_t value, uint32_t key, uint32_t prime_mod_relation);

		std::vector<uint32_t> prime_list_;

		uint32_t p;
		uint32_t q;
		uint32_t n;
		uint32_t d;
		uint32_t e;
		uint32_t phi;

		std::pair<uint32_t, uint32_t> private_key_;
		std::pair<uint32_t, uint32_t> public_key_;
	};
}
