/**
 * \brief cipher.tsec - Template Security
 * \author dove-zp
 * \contact https://github.com/dove-zp
 * \version 2018/AUG/01
 * \license MIT License (Expat) 
 */


#pragma once

#include <Windows.h>
#include <exception>

//--------------------------------------------------------------------------------------------------

namespace cipher
{
    template <class T>
    struct _data
    {
        T data;
        unsigned __int8 key_;
        unsigned __int8 fake_pointer_a_;
        unsigned __int8 fake_pointer_b_;
        unsigned __int16 checksum_;
    };

    template <class T>
    class tsec
    {
    public:
        tsec();
        tsec(T data);
        ~tsec();

        T get_data();
        unsigned __int16 set_data(T data);

    private:
        unsigned __int32 fake_pointer_a_;
        unsigned __int32 fake_pointer_b_;
        _data<T>* secdata_;
        void init(T data);
        unsigned __int8 set_key(unsigned __int8 index);
    };
}

template <class T>
cipher::tsec<T>::tsec()
{
    init(0);
}

template <class T>
cipher::tsec<T>::tsec(T data)
{
    init(data);
}

template <class T>
cipher::tsec<T>::~tsec()
{
    if (this->secdata_ != nullptr)
    {
        free(this->secdata_);
    }
    else
    {
        throw std::exception("<ERROR> Unable to Clear Data");
    }
}

template <class T>
T cipher::tsec<T>::get_data()
{
    T decrypted_data = 0;
    unsigned __int16 checksum = 0;
    for (unsigned __int8 i = 0; i < (sizeof(T) + 1); i++)
    {
        unsigned __int8 key = this->set_key(i);
        if (i > 0)
        {
            if (i > 1) // bitwise or 
            {
                checksum = ((8 * checksum) | (key + (checksum >> 13)));
            }
            else
            {
                checksum = ((key + 4) | 0xD328);
            }
        }
        if (i < sizeof(T))
        {
            if (!key) // no key
            {
                key = 42;
            }
            reinterpret_cast<unsigned __int8*>(&decrypted_data)[i] = reinterpret_cast<unsigned __int8*>(&this->secdata_->data)[i] ^ key;
        }
    }
    if ((this->secdata_->checksum_ != checksum) ||
        (LOBYTE(this->fake_pointer_a_) != this->secdata_->fake_pointer_a_) ||
        (LOBYTE(this->fake_pointer_b_) != this->secdata_->fake_pointer_b_))
    {
        throw std::exception("<ERROR> Failed to Obtain Data");
    }

    return decrypted_data;
}

template <class T>
unsigned __int16 cipher::tsec<T>::set_data(T data)
{
    this->secdata_->key_ = static_cast<unsigned __int8>(rand());
    this->secdata_->checksum_ = static_cast<unsigned __int16>(39525);

    for (unsigned __int8 i = 0; i < (sizeof(T) + 1); i++)
    {
        unsigned __int8 key = this->set_key(i);
        if (i > 0)
        {
            this->secdata_->checksum_ = ((8 * this->secdata_->checksum_) | (key + (this->secdata_->checksum_ >> 13)));
        }

        if (i < sizeof(T))
        {
            if (!key)
            {
                key = 42;
            }
            reinterpret_cast<unsigned __int8*>(&this->secdata_->data)[i] = reinterpret_cast<unsigned __int8*>(&data)[i] ^ key;
        }
    }
    return this->secdata_->checksum_;
}

template <class T>
void cipher::tsec<T>::init(T data)
{
    this->secdata_ = reinterpret_cast<_data<T>*>(malloc(12));
    this->fake_pointer_a_ = static_cast<unsigned int>(reinterpret_cast<unsigned int>(&this[-0x00003FF8]) + rand());
    this->fake_pointer_b_ = static_cast<unsigned int>(reinterpret_cast<unsigned int>(&this[-0x00003FF8]) + rand());
    this->secdata_->fake_pointer_a_ = static_cast<unsigned __int8>(LOBYTE(this->fake_pointer_a_));
    this->secdata_->fake_pointer_b_ = static_cast<unsigned __int8>(LOBYTE(this->fake_pointer_b_));
    this->set_data(data);
}

template <class T>
unsigned __int8 cipher::tsec<T>::set_key(unsigned __int8 index)
{
    unsigned __int8 key = 0;

    if (index == 0)
    {
        key = this->secdata_->key_;
    }
    else
    {
        key = reinterpret_cast<unsigned __int8*>(&this->secdata_->data)[index - 1] + key + 42;
    }

    return key;
}
