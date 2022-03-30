#include <iostream>
#include <cmath> 


unsigned short* hex2bin(unsigned short hex)
{
    //double dec = 0.0;
    unsigned short bin = 0;
    unsigned short *bvector = new unsigned short[16];
    for(int i=1;i<=16;i++)
    {
        bin = hex % 2;
        bvector[16-i] = bin;
        hex = hex / 2;
    }
    return bvector;
}

double bin2dec(unsigned short* v, int MSBvalue)
{
    double dec = 0.0;
    double a[16] = {0};
    for(int i = 0; i<=15; i++)
    {
        a[i]=(double)v[i];
    }
    for(int i = 1;i <= 12; i++)
    {
        dec = dec + a[i] * pow(2.0,MSBvalue+1-i);
    }
    dec = dec - a[0] * pow(2,MSBvalue+1);
    return dec;
}

int main()
{
    unsigned short a = 0x0;
    double b = 0;
    std::cout << "Please input  the source code number: ";
    std::cin >> std::hex >> a;
    std::cout << "Please input  the Most significant value: ";
    std::cin >> b;
    b = log(b)/log(2);
    unsigned short *test = hex2bin(a);
    double dectest = 0.0;
    for(int i = 0; i <= 15; i++)
    {
        std::cout << test[i];
    }
    std::cout <<" " << std::endl;
    dectest = bin2dec(test, b);
    std::cout << dectest << std::endl;
    delete[] test;
    return 0;
}