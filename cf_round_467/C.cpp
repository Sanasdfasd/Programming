//
// Created by Avula, Sandeep on 2/25/18.
//
/// @file     segmented_sieve.cpp
/// @author   Kim Walisch, <kim.walisch@gmail.com>
/// @brief    This is a simple implementation of the segmented sieve of
///           Eratosthenes with a few optimizations. It generates the
///           primes below 10^9 in 0.9 seconds (single-threaded) on an
///           Intel Core i7-4770 CPU (3.4 GHz) from 2013.
/// @license  Public domain.

#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int last;
    for (int i=2; i<1000000000; i++)
        for (int j=2; j*j<=i; j++)
        {
            if (i % j == 0)
                break;
            else if (j+1 > sqrt(i)) {
                cout << i << " ";
                last=i;
            }

        }
    cout<<" the last eleme "<<last<<endl;
    return 0;
}

