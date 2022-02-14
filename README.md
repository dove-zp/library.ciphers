# cipher.sakura

#### SAKURA Encryption and Decryption

## About

A hacked together derivative of AES ECB block cipher.

## Example

```cpp
#include "sakura.h"

#include <string>
#include <iostream>

#pragma comment(lib, "sakura.lib")

uint8_t key[]=
{
    0xb4, 0xc1, 0xa6, 0x42, 0x2d, 0x20, 0x57, 0x3a, 0xf4, 0xe7, 0x59, 0x6f, 0xd3, 0x39, 0x18, 0xb9,
    0x21, 0x41, 0xde, 0x35, 0x00, 0xd3, 0x7e, 0x13, 0x63, 0x40, 0x0e, 0xa3, 0xf7, 0x2d, 0x46, 0xf6 
};

uint8_t iv[]=
{
    0x1f, 0x80, 0xff, 0xea, 0xcc, 0x5c, 0x98, 0x09, 0xdd, 0x13, 0xbb, 0xd7, 0x90, 0xa0, 0x13, 0x54,
    0xa3, 0xd5, 0x13, 0x12, 0x0d, 0x05, 0xac, 0xde, 0x40, 0xff, 0x3d, 0x44, 0x3c, 0x61, 0xa1, 0xd6 
};

char *message = "I see only evil";

cipher::sakura sakura_ecb;

bool en_success = sakura_ecb.encrypt(message, strlen(message), key, iv);
std::cout << std::to_string(message) << std::endl;

bool de_success = sakura_ecb.decrypt(message, strlen(message), key, iv);
std::cout << std::to_string(message) << std::endl;
```


## License

This project is licensed under the [MIT License (Expat)](https://tldrlegal.com/license/mit-license). See the [LICENSE.md](./LICENSE.md) file for details.

<!--  -->

## Feedback

I welcome your constructive input - both negative and positive. I will continue to try to provide updates when able. At some point you may find errors, inconsistencies, or methods that could be improved, or are missing altogether. Your feedback is critical to help improve future revisions.

The best way to reach out is by opening a new issue in this repository:

https://github.com/dove-zp/library.ciphers/issues

Please be sure to refer to what your situation is when giving feedback and if possible link the topic in question.

Many thanks.

<hr/>

<p align="center">
  <p align="center">
    <a href="https://hits.seeyoufarm.com/api/count/graph/dailyhits.svg?url=https://github.com/dove-zp/library.ciphers">
      <img src="https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2Fdove-zp%2Flibrary.ciphers&count_bg=%2379C83D&title_bg=%23555555&icon=&icon_color=%23E7E7E7&title=hits&edge_flat=true" alt="repository hits">
    </a>
    <a href="https://github.com/dove-zp/library.ciphers/releases">
      <img src="https://img.shields.io/github/downloads/dove-zp/library.ciphers/total?style=flat-square" alt="downloads"/>
    </a>
    <a href="https://github.com/dove-zp/library.ciphers/graphs/contributors">
      <img src="https://img.shields.io/github/contributors/dove-zp/library.ciphers?style=flat-square" alt="contributors"/>
    </a>
    <a href="https://github.com/dove-zp/library.ciphers/watchers">
      <img src="https://img.shields.io/github/watchers/dove-zp/library.ciphers?style=flat-square" alt="watchers"/>
    </a>
    <a href="https://github.com/dove-zp/library.ciphers/stargazers">
      <img src="https://img.shields.io/github/stars/dove-zp/library.ciphers?style=flat-square" alt="stars"/>
    </a>
    <a href="https://github.com/dove-zp/library.ciphers/network/members">
      <img src="https://img.shields.io/github/forks/dove-zp/library.ciphers?style=flat-square" alt="forks"/>
    </a>
  </p>
</p>

<p align="center">
  <a href="https://github.com/dove-zp">
    <img width="64" heigth="64" src="https://avatars.githubusercontent.com/u/89095890" alt="dove-zp"/>
  </a>  
</p>
