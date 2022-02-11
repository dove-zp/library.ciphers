/**
 * \brief cipher.tsec.sample - Template Security Sample
 * \author dove-zp
 * \contact https://github.com/dove-zp
 * \version 2018/AUG/01
 * \license MIT License (Expat) 
 */

#include "../tsec/tsec.h"

#include <iostream>

//--------------------------------------------------------------------------------------------------

void main()
{
    cipher::tsec<int> x(222);

    std::cout << x.get_data() << std::endl;

    x.set_data(444);

    std::cout << x.get_data() << std::endl;

    system("pause");
}