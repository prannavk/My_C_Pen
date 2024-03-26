#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <bits/stdc++.h>
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
long long maxv = 1e9;

string digits;
long long len = 10000;
string intToString(int N) {
    string str;
    while(N) {
        int temp = (N%10);
        str += temp + '0';
        N /= 10;
    }
    reverse(str.begin(), str.end());
    return str;
}

void stringLine() {
    for(int i = 0; i <= len; i++)
        digits += intToString(i);
}

int main() {
    stringLine();
    int N;
    cin>>N;
    printf("%c\n", digits[N-1]);
    return 0;
}