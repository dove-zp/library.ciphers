# cipher.affine

#### Affine Encryption and Decryption

## About

The affine cipher is a monoalphabetic substitution cipher. The goal of this library is to create a small and portable library for the affine cipher without heavily focusing on additional programming weight. The library is a small sub library from my personal cipher library.

## Pseudo

An example pseudo of a standard english alphabet based affine cipher decoding:
```
where string decoded is empty
where int m is the length of the alphabet; ex: 26
where int a is the key number such that (1 <= a and a <= m)
where int b is the shift number such that (0 <= b and b <= m)
where int z is the resulting inverse in the range 1 to m only if ((key * i) % m) = 1
where char t(p) is the resulting table reference head for the supported character type; ex: 'A' or 'a' would 
be used in the english alphabet since each the language contains both lower and upper case
providing that the compare of p is either upper or lower 

for int i = 0 and i < input.length 
    where char p = input[i]
    where char c is empty
    if p in alphabet
        c = (z * (p - t(p)) + (m - b)) mod m + t(p)
    else
        c = p
    decoded[i] += c  
return decoded
```
An example pseudo of a standard english alphabet based affine cipher encoding:
```
where string encoded is empty
where int m is the length of the alphabet; ex: 26
where int a is the key number such that (1 <= a and a <= m)
where int b is the shift number such that (0 <= b and b <= m)
where char t(p) is the resulting table reference head for the supported character type; ex: 'A' or 'a' would 
be used in the english alphabet since each the language contains both lower and upper case
providing that the compare of p is either upper or lower 

for int i = 0 and i < input.length 
    where char p = input[i]
    where char c is empty
    if p in alphabet
        c = (a * (p - t(p)) + b) mod m + t(p) 
    else
        c = p
    encoded[i] += c  
return encoded
```

## Example

```cpp
#include "affine.h"

#include <string>
#include <iostream>

#pragma comment(lib, "affine.lib")

std::string message = "this is a text message";

cipher::affine afne(5, 14);

std::string encoded = afne.encrypt(message);
std::cout << encoded << std::endl;

std::string decoded = afne.decrypt(encoded);
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
