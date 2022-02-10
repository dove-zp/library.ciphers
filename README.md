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

## Developer

* ["dove-zp"][ref-self]

## License

This project is licensed under the [MIT License (Expat)][ref-lic]. See the [LICENSE.md](./LICENSE.md) file for details.

[ref-self]: https://github.com/dove-zp
[ref-lic]: https://tldrlegal.com/license/mit-license
