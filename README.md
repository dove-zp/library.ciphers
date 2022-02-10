# cipher.rc4

#### RC4 Encryption and Decryption

## About

The goal of rc4 is to create a small and portable library for the cipher without heavily focusing on additional programming weight. The library is a small sub library from my personal cipher library.

## Example

```cpp
#include "rc4.h"

#include <string>
#include <iostream>

#pragma comment(lib, "rc4.lib")

std::string key = "good";
std::string message = "I will fear no evil";

cipher::rc4 rc_four;

std::string encoded = rc_four.encrypt(message, key);
std::cout << encoded << std::endl;

std::string decoded = rc_four.decrypt(encoded, key);
std::cout << decoded << std::endl;
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