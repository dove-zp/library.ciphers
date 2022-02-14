/**
 * \brief cipher.mrsa - Mini RSA
 * \author dove-zp
 * \version 2/JUN/2019
 * \license MIT License (Expat)
 */

#include "mrsa.h"
#include <random>

//--------------------------------------------------------------------------------------------------

/**
 * \brief finds the greatest common divisor between two integers 
 * \param a input a 
 * \param b input b
 * \return greatest common divisor between a and b
 */
uint32_t gcd(uint32_t a, uint32_t b)
{
	uint32_t x = (a > b) ? a : b;
	uint32_t y = (a > b) ? b : a;
	while (true)
	{
		const uint32_t mod = x % y;
		if (mod == 0)
		{
			return y;
		}
		x = y;
		y = mod;
	}
}

/**
 * \brief euler's iterative totient - deep relationship between prime and co prime through iteration
 * \param n prime to find co prime
 * \return relatively co prime 
 */
uint32_t totient(uint32_t n)
{
	uint32_t e = 0;
	for (size_t i = 1; i < n; i++) 
	{
		if (gcd(i, n) == 1)
		{
			e++;
		}
	}
	return e;
}

/**
 * \brief euler's random totient - deep relationship between prime and co prime	through shuffling
 * \param prime input to find co prime
 * \return co prime 
 */
uint32_t coprime(uint32_t prime)
{
	uint32_t co = 0;
	while(true)
	{
		// get random value within range
		co = rand() % prime + 1;
		if (gcd(co, prime) == 1)
		{
			return co;
		}
	}
}

/**
 * \brief modulate (value ** expoment) % mod
 * \param value initial input value  
 * \param exponent iterate over series
 * \param mod modulate the result by 
 * \return modulated result
 */
uint32_t modulo(uint32_t value, uint32_t exponent, uint32_t mod)
{
	uint32_t result = 1;
	for (size_t i = 1; i <= exponent; i++) {
		result *= value;
		result %= mod;
	}
	return result;
}

/**
 * \brief modulate via the coprime
 * \param value initial input value  
 * \param mod find the of coprime and modulate the result by 
 * \return inverted modulated result
 */
uint32_t modulus_invert(uint32_t value, uint32_t mod)
{
	uint32_t exp = totient(mod) - 1;
	return modulo(value, exp, mod);
}

/**
 * \brief initial constructor generates keys
 */
cipher::mrsa::mrsa()
{
	init();
}

/**
 * \brief constructor uses pre-existing keys
 * \param private_key pre-existing key 
 * \param public_key pre-existing key 
 */
cipher::mrsa::mrsa(std::pair<uint32_t, uint32_t> private_key, std::pair<uint32_t, uint32_t> public_key)
{
	this->private_key_ = private_key;
	this->public_key_ = public_key;
}

/**
 * \brief encrypts a value
 * \param value plain text value 
 * \param public_key pair to encrypt 
 * \return encoded value
 */
uint32_t cipher::mrsa::encrypt(uint32_t value, std::pair<uint32_t, uint32_t> public_key)
{
	/*
	uint32_t c = pow(value, public_key);
	return fmod(c, n);
	*/
	return crypt(value, public_key.first, public_key.second);
}

/**
 * \brief decrypts a value
 * \param value encoded value
 * \param private_key pair to decrypt
 * \return decoded value
 */
uint32_t cipher::mrsa::decrypt(uint32_t value, std::pair<uint32_t, uint32_t> private_key)
{
	/*
	uint32_t m = pow(value, private_key);
	return fmod(m, n);
	*/
	return crypt(value, private_key.first, private_key.second);
}

/**
 * \brief encrypts a string via iteration 
 * \param message plain text message 
 * \param public_key pair to encrypt
 * \return encrypted message
 */
uint32_t* cipher::mrsa::encrypt(std::string message, std::pair<uint32_t, uint32_t> public_key)
{
	uint32_t* result = new uint32_t[message.size()];

	for (size_t i = 0; i < message.size(); i++) 
	{
		result[i] = crypt(static_cast<uint32_t>(message.at(i)), public_key.first, public_key.second);
	}
	return result;
}

/**
 * \brief decrypts a string via iteration 
 * \param message encoded message 
 * \param private_key pair to decrypt
 * \return decrypted message
 */
std::string cipher::mrsa::decrypt(uint32_t* message, std::pair<uint32_t, uint32_t> private_key)
{
	std::string result = "";

	for (size_t i = 0; i < (sizeof(message) / sizeof(uint32_t)); i++)
	{
		result.append(std::to_string(crypt(static_cast<uint32_t>(message[i]), private_key.first, private_key.second)));
	}
	return result;
}

/**
 * \brief get private key
 * \return pair private key containing d and n 
 */
std::pair<uint32_t, uint32_t> cipher::mrsa::get_private_key() const
{
	return this->private_key_;
}

/**
 * \brief get public key
 * \return pair public key containing e and n
 */
std::pair<uint32_t, uint32_t> cipher::mrsa::get_public_key() const
{
	return this->public_key_;
}

/**
 * \brief key initializer
 */
void cipher::mrsa::init()
{
	// generate a sample pool of primes
	generate_primes();

	// random relation prime pick
	std::random_device dev;
	std::mt19937 rng(dev());
	const std::uniform_int_distribution<std::mt19937::result_type> dist(2, prime_list_.size());
	p = dist(rng);
	q = dist(rng);

	// generate keys
	generate_public_key();
	generate_private_key();
}

/**
 * \brief brute forced prime generated list
 */
void cipher::mrsa::generate_primes()
{
	const size_t MAX_COUNT = 10000;
	const size_t MAX_LIMIT = 1000000;

	prime_list_.clear();
	prime_list_.push_back(2);

	size_t prime_list_size = prime_list_.size();
	for (size_t i = 3; MAX_LIMIT == 0 || i <= MAX_LIMIT; i += 2)
	{
		bool is_prime = true;
		for (int j = 0; j < prime_list_size; j++)
		{
			const uint32_t c_prime = prime_list_[j];
			if (i < c_prime * c_prime)
			{
				break;
			}

			if (i % c_prime == 0)
			{
				is_prime = false;
				break;
			}
		}
		if (is_prime)
		{
			prime_list_.push_back(i);
			prime_list_size++;
			if (MAX_COUNT != 0 && prime_list_size == MAX_COUNT)
			{
				break;
			}
		}
	}
}

/**
 * \brief generate public key and relation
 */
void cipher::mrsa::generate_public_key()
{
	// modulus after multiplying the pair two primes
	n = p * q; 

	// find non common factors of n
	phi = (p - 1) * (q - 1);

	/* 
	// encrypt from 2
	e = 2;

	// coprime ncf with modulus
	while (e < phi)
	{
		// where e must be co-prime to phi and smaller than phi 
		if (gcd(e, phi) == 1)
		{
			break;
		}
		e++;
	}
	*/

	e = coprime(phi);

	this->public_key_.first = e;
	this->public_key_.second = n;
}

/**
 * \brief generate private key and relation
 */
void cipher::mrsa::generate_private_key()
{
	/*
	// constant base 
	const uint32_t k = 2;

	// decryptor * encryptor modulus ncf == 1 && d * e = 1 + k * (totient ncf) 

	d = (1 + (k * phi)) / e;
	*/

	d = modulus_invert(e, phi);

	this->private_key_.first = d;
	this->private_key_.second = n;
}

/**
 * \brief bi-directional crypt (en / de)
 * \param value initial value to crypt
 * \param key input key 
 * \param prime_mod_relation relation of key
 * \return crypted result (en or de)
 */
uint32_t cipher::mrsa::crypt(uint32_t value, uint32_t key, uint32_t prime_mod_relation)
{
	return modulo(value, key, prime_mod_relation);
}
