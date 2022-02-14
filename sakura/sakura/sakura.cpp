/**
 * \brief cipher.sakura - SAKURA Encryption and Decryption
 * \author dove-zp
 * \version 3/JUN/2019
 * \license MIT License (Expat)
 */

#include "sakura.h"

#include <Windows.h>
#include <cstdlib>

//--------------------------------------------------------------------------------------------------

#define ALIGN(VALUE,ALIGNMENT) (((VALUE+ALIGNMENT-1)/ALIGNMENT)*ALIGNMENT)

cipher::sakura::sakura()
{
}

cipher::sakura::~sakura()
{
}

bool cipher::sakura::decrypt(void* buffer, size_t length, uint8_t* key, uint8_t* iv)
{
	auto* ptr_buffer = static_cast<uint8_t*>(buffer);

	if (length & 0x1F)
	{
		return false;
	}

	const size_t count = length / 32;

	for (size_t i = 0; i < count; i++)
	{
		decrypt_block(ptr_buffer, key);

		if (iv)
		{
			xor_block(ptr_buffer, iv);
		}

		ptr_buffer += 32;
	}
	return true;
}

bool cipher::sakura::encrypt(void* buffer, size_t length, uint8_t* key, uint8_t* iv)
{
	auto* ptr_buffer = static_cast<uint8_t*>(buffer);

	if (length & 0x1F)
	{
		return false;
	}

	const size_t count = length / 32;

	for (size_t i = 0; i < count; i++)
	{
		encrypt_block(ptr_buffer, key);

		if (iv)
		{
			xor_block(ptr_buffer, iv);
		}

		ptr_buffer += 32;
	}
	return true;
}

void* cipher::sakura::padding(void* buffer, size_t length, uint32_t* aligns)
{
	const size_t aligned_length = ALIGN(length, 32);
	void* ptr_aligned_allocated = malloc(aligned_length);

	if (!ptr_aligned_allocated)
	{
		return ptr_aligned_allocated;
	}

	memset(ptr_aligned_allocated, 0, aligned_length);
	memcpy(ptr_aligned_allocated, buffer, length);

	*aligns = aligned_length;
	return ptr_aligned_allocated;
}

void cipher::sakura::xor_block(void* buffer, uint8_t* key)
{
	auto* ptr_buffer = static_cast<uint8_t*>(buffer);

	for (size_t i = 0; i < 32; i++)
	{
		ptr_buffer[i] ^= key[i];
	}
}

void cipher::sakura::encrypt_block(void* buffer, uint8_t* key)
{
	auto* ptr_buffer = static_cast<uint8_t*>(buffer);

	uint8_t swapbox[256] = {};
	uint8_t sub_key[32] = {};

	// copy key to sub_key
	memcpy(sub_key, key, 32);

	// alloc swapbox
	for (size_t i = 0; i < 256; i++)
	{
		swapbox[i] = static_cast<uint8_t>(i);
	}

	// swap shift keys and box
	for (size_t i = 0, j = 0; i < 256; i++)
	{
		j = (j + swapbox[i] + key[i & 0x1F] - key[key[i & 0x1F] & 0x1F] + swapbox[j]) & 0xFF;
		
		const uint8_t swap = swapbox[i];
		swapbox[i] = swapbox[j];
		swapbox[j] = swap;
	}

	// shift xor to buffer
	for (size_t i = 0, j = 0; i < 32; i++)
	{
		j = (j + swapbox[i] + swapbox[j] - swapbox[(swapbox[i] + j) & 0xFF]) & 0xFF;
		ptr_buffer[i] ^= swapbox[(swapbox[i] + swapbox[j]) & 0xFF];
	}

	// swap sub_key via swapbox shift then xor
	for (size_t i = 0, j = 0; i < 0x40000; i++)
	{
		j = (j + key[i & 0x1F] - sub_key[i & 0x1F] + swapbox[(key[j & 0x1F] + swapbox[j & 0xFF]) & 0xFF] - key[j & 0x1F]) & 0x1F;
		
		const uint8_t swap = sub_key[i & 0x1F];
		sub_key[i & 0x1F] = sub_key[j];
		sub_key[j] = swap;

		sub_key[j] ^= sub_key[(sub_key[i & 0x1F] + swapbox[i & 0xFF] - sub_key[j]) & 0x1F];
	}

	for (size_t i = 0, j = 0; i < 32; i++)
	{
		j = (j + swapbox[i] + sub_key[i] - sub_key[(swapbox[j] + sub_key[j]) & 0x1F]) & 0x1F;

		ptr_buffer[i] += sub_key[i];
		ptr_buffer[i] -= sub_key[(swapbox[j] + sub_key[j]) & 0x1F];
	}
}

void cipher::sakura::decrypt_block(void* buffer, uint8_t* key)
{
	auto* ptr_buffer = static_cast<uint8_t*>(buffer);

	uint8_t swapbox[256] = {};
	uint8_t sub_key[32] = {};

	// copy key to sub_key
	memcpy(sub_key, key, 32);

	// alloc swapbox
	for (size_t i = 0; i < 256; i++)
	{
		swapbox[i] = static_cast<uint8_t>(i);
	}

	// swap shift keys and box
	for (size_t i = 0, j = 0; i < 256; i++)
	{
		j = (j + swapbox[i] + key[i & 0x1F] - key[key[i & 0x1F] & 0x1F] + swapbox[j]) & 0xFF;

		const uint8_t swap = swapbox[i];
		swapbox[i] = swapbox[j];
		swapbox[j] = swap;
	}

	// swap sub_key via swapbox shift then xor
	for (size_t i = 0, j = 0; i < 0x40000; i++)
	{
		j = (j + key[i & 0x1F] - sub_key[i & 0x1F] + swapbox[(key[j & 0x1F] + swapbox[j & 0xFF]) & 0xFF] - key[j & 0x1F]) & 0x1F;

		const uint8_t swap = sub_key[i & 0x1F];
		sub_key[i & 0x1F] = sub_key[j];
		sub_key[j] = swap;

		sub_key[j] ^= sub_key[(sub_key[i & 0x1F] + swapbox[i & 0xFF] - sub_key[j]) & 0x1F];
	}

	for (size_t i = 0, j = 0; i < 32; i++)
	{
		j = (j + swapbox[i] + sub_key[i] - sub_key[(swapbox[j] + sub_key[j]) & 0x1F]) & 0x1F;

		ptr_buffer[i] += sub_key[(swapbox[j] + sub_key[j]) & 0x1F];
		ptr_buffer[i] -= sub_key[i];
	}

	// shift xor to buffer
	for (size_t i = 0, j = 0; i < 32; i++)
	{
		j = (j + swapbox[i] + swapbox[j] - swapbox[(swapbox[i] + j) & 0xFF]) & 0xFF;

		ptr_buffer[i] ^= swapbox[(swapbox[i] + swapbox[j]) & 0xFF];
	}
}
