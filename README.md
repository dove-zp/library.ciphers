# cipher.xas

#### XOR-ADD-SUB Encryption and Decryption

## About

The goal of xas is to create a small and portable library for the cipher without heavily focusing on additional programming weight. The library is a small sub library from my personal cipher library. This was originally part of my shabak challege code for the second and third homebase challenges.

The entire shabak challenge was completed in three days with two challenges each day from both homebase and airplane. I started April 28th, 2017 @ 10:00 PM and ended April 29th, 2017 @ 1:43 AM. The additional challenge deceptionisland was released through targeted newpapers and locations; these contained a series of web exploit challenges and all were completed the follwing day under the alias "ez".

The Israel Security Agency launched a unique recruitment campaign, via their homepage, Thursday (April 27th, 2017), which  allowed the general public, as well as potential candidates for a career in their security service, to challenge themselves. The ISA has a desire to recruit the best minds from cyberspace and technology in Israel by presenting this particular challenge in fan-fiction spin off of "Rick and Morty". People who solve the challenges will be invited to apply for one of the unique technological posts at the forefront of technology and to integrate into the unique and new development tracks and careers offered by the ISA to these candidates. Shabak notes that all those interested in developing a career in the security service will significantly shorten the process of applying for various positions, so that within a few minutes a candidate can complete the process in a simple and user-friendly way.

## Known Issues

* If the key is spread over too large of a size length when the input param size length is too small, known as multiple layer overflowing and overlapping, causes the encoding will be fine but the decoding will have a slightly shifted result in the overflowed and overlapped area. This was seen in the third homebase challenge upon using my speedy tools named 'hunter' and 'crack' to bruteforce the encoded text and also find the legit key using xor, sub, add weaknesses. A slight modification to the result has to be preformed in order to obtain the correct keys.

## Example

```cpp
#include "xas.h"

#include <string>
#include <iostream>

#pragma comment(lib, "xas.lib")

std::string text_string = "kernel32.dll";
std::vector<unsigned char> text_vector(text_string.begin(), text_string.end());


cipher::xas::encrypt(text_vector, { { cipher::xas::OP::ADD, 1, 2 },
                                    { cipher::xas::OP::XOR, 3, 4 },
                                    { cipher::xas::OP::SUB, 5, 6 } });

std::cout << "expected input  : " << text_string << std::endl;
std::cout << "expected result : lfqmfo.-)_gg" << std::endl;
std::cout << "encoded result  : " << std::string(text_vector.begin(), text_vector.end()) << std::endl << std::endl;


cipher::xas::decrypt(text_vector, { { cipher::xas::OP::ADD, 1, 2 },
                                    { cipher::xas::OP::XOR, 3, 4 },
                                    { cipher::xas::OP::SUB, 5, 6 } });

std::cout << "expected input  : lfqmfo.-)_gg" << std::endl;
std::cout << "expected result : " << text_string << std::endl;
std::cout << "decoded result  : " << std::string(text_vector.begin(), text_vector.end()) << std::endl << std::endl;
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
