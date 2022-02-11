# cipher.xrot

#### XOR-ROT Encryption and Decryption

## About

The goal of xrot is to create a small and portable library for the cipher without heavily focusing on additional programming weight. The library is a small sub library from my personal cipher library. This was originally part of my shabak challege code for the first homebase challenge.

The entire shabak challenge was completed in three days with two challenges each day from both homebase and airplane. I started April 28th, 2017 @ 10:00 PM and ended April 29th, 2017 @ 1:43 AM. The additional challenge deceptionisland was released through targeted newpapers and locations; these contained a series of web exploit challenges and all were completed the follwing day under the alias "ez".

The Israel Security Agency launched a unique recruitment campaign, via their homepage, Thursday (April 27th, 2017), which  allowed the general public, as well as potential candidates for a career in their security service, to challenge themselves. The ISA has a desire to recruit the best minds from cyberspace and technology in Israel by presenting this particular challenge in fan-fiction spin off of "Rick and Morty". People who solve the challenges will be invited to apply for one of the unique technological posts at the forefront of technology and to integrate into the unique and new development tracks and careers offered by the ISA to these candidates. Shabak notes that all those interested in developing a career in the security service will significantly shorten the process of applying for various positions, so that within a few minutes a candidate can complete the process in a simple and user-friendly way.


## Example

```cpp
#include "xrot.h"

#include <string>
#include <iostream>

#pragma comment(lib, "xrot.lib")

std::vector<unsigned char> x = { 127, 30 };
cipher::xrot vtr_xrt(x);

std::vector<unsigned char> vtr_encoded = vtr_xrt.encrypt(text_string);
std::cout << "encoded: " << std::string(vtr_encoded.begin(), vtr_encoded.end()) << std::endl;

std::cout << "decoded: " << vtr_xrt.decrypt(vtr_encoded) << std::endl;
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
