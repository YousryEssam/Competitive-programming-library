#include<bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////////
//BITS :
//Get Bit 
bool get_bit(const long long& num, const int& index) { return (1 & (num >> index)); }

//Turn bit to 1 
void change_bit_to_1(long long& num, const int& index)
{
	num = (num | ((long long)1 << index));
}

//Turn bit to 0 
void change_bit_to_0(long long& num, const int& index){
	num = (num & (~((long long)1 << index)));
}


//Flip bit

void flip_bit(long long& num, const int& index){
	num = num ^ ((long long)1 << index);
}

//Change first bit equal 0 to 1 
void change_first_equal_to_0(long long& num){
	num = num | (num + 1);
}

//Change first bit equal 1 to 0 

void change_first_equal_to_1(long long& num)
{
	num = num & (num - 1);
}


//Change all 1 until to meet 1 

void change_all_to_1_until_meet_1(long long& num)
{
	num = num | (num - 1);
}


//Change all to meet 0
void change_all_to_0_until_meet_0(long long& num)
{
	num = num & (num + 1);
}


//First bit equal to 1 

int first_bit_equal_to_1(long long& num)
{
	if (num == 0)return -1;
	return (int)log2((num & ~(num - 1)));
}


//count number of bit for large number
int countBits(long long n){
    int count=0;
    while (n) { 
        count++; 
        n >>= 1; 
    } 
    return count;
}

//count the number of ones in a number
int numberOfOnes(int x){
    int n=0;
    while(x){
        n++;
        x&=x-1;
    }
	return n;
}

//IS power of 2

bool is_Power_Of_Two(long long num){return (!(num & num - 1));}


//Turn on last consecutive zeros 

int turn_On_Last_Consecutive_Zeroes(int S) {return S | S - 1;}

//Turn of last consecutive ones 

int turn_Off_Last_Consecutive_Ones(int S) {return S & S + 1;}

//Get number of zeros of bit from 0 to n 
// Number Of zeros in pos i from 0 to N ;
int numOfZeros(int n, int i) {
	return (n >> (i + 1) << i) + min(n % (1 << (i + 1)), (1 << i));
}