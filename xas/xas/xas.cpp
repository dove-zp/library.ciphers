/**
 * \brief cipher.xas - XOR-ADD-SUB Encryption and Decryption
 * \author dove-zp
 * \contact https://github.com/dove-zp
 * \version 2018/AUG/01
 * \license MIT License (Expat) 
 */


#include "xas.h"

//--------------------------------------------------------------------------------------------------

void cipher::xas::encrypt(std::vector<unsigned char>& input, std::vector<DESCRIPTOR> key)
{
    crypt(input, key);
}

void cipher::xas::decrypt(std::vector<unsigned char>& input, std::vector<DESCRIPTOR> key)
{
    crypt(input, inverse_key(key));
}

bool cipher::xas::parse_key(std::vector<unsigned char> const& product, std::vector<DESCRIPTOR>& key)
{
    if ((product.size() % sizeof(DESCRIPTOR)) != 0)
    {
        return false;
    }

    for (std::size_t i = 0; i < product.size(); i += sizeof(DESCRIPTOR))
    {
        key.push_back({ static_cast<OP>(product[i]), static_cast<unsigned char>(product[i + 1]), *reinterpret_cast<const unsigned int*>(&product[i + 2]) });
    }

    return true;
}

std::vector<cipher::xas::DESCRIPTOR> cipher::xas::inverse_key(std::vector<DESCRIPTOR> key)
{
    std::vector<DESCRIPTOR> new_key = {};
    for (DESCRIPTOR descriptor : key)
    {
        DESCRIPTOR d = descriptor;
        switch (descriptor.operation_code)
        {
            case XOR:
            {
                d.operation_code = XOR;
                break;
            }
            case ADD:
            {
                d.operation_code = SUB;
                break;
            }
            case SUB:
            {
                d.operation_code = ADD;
                break;
            }
            default:
            {
                // TODO throw exception
                break;
            }
        }
        new_key.push_back(d);
    }
    return new_key;
}

unsigned char cipher::xas::step(unsigned char value, DESCRIPTOR const& descriptor)
{
    switch (descriptor.operation_code)
    {
        case XOR:
        {
            return (value ^ descriptor.operation_parameter);
        }
        case ADD:
        {
            return (value + descriptor.operation_parameter);
        }
        case SUB:
        {
            return (value - descriptor.operation_parameter);
        }
        default:
        {
            // TODO throw exception
            break;
        }
    }
    return 0;
}

void cipher::xas::crypt(std::vector<unsigned char>& input, std::vector<DESCRIPTOR> const& key)
{
    for (std::size_t i = 0, j = 0, direction = 0; i < key.size(); j += key.at(i).operation_length, i++)
    {
        for (std::size_t k = 0; k < key.at(i).operation_length; k++)
        {
            if ((j + k) != 0 && (((j + k) % input.size()) == 0))
            {
                direction++;
            }

            const std::size_t direction_delta = (direction * input.size());
            std::size_t offset = 0;

            if ((direction % 2) == 0)
            {
                offset = (j + k - direction_delta);
            }
            else
            {
                const std::size_t reverse_delta = (((j + k) - direction_delta) + 1);
                offset = (input.size() - reverse_delta);
            }

            input[offset] = step(input.at(offset), key.at(i));
        }
    }
}
