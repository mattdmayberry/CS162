///
/***********************************************
 * Filter.h
 * Created by Matthew D Mayberry on 5/2/15
 * CS162_400_S2015_Lab5
 ***********************************************/
///

#ifndef FILTER_H
#define FILTER_H
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;


/////////////////////////////////////////////////
/***********************************************
 *               class Filter                  *
 ***********************************************/
/////////////////////////////////////////////////

class Filter
{
    
protected:
    
    
public:
    void doFilter(ifstream &in, ofstream &out);
    virtual char transform(char ch) = 0;
    
};

/////////////////////////////////////////////////
/***********************************************
 *             class Unchanged                 *
 ***********************************************/
/////////////////////////////////////////////////

class Unchanged : public Filter

{
protected:
    char unch;
    
public:
    Unchanged();
    char transform(char ch);
    
};

/////////////////////////////////////////////////
/***********************************************
 *             class Encryption                *
 ***********************************************/
/////////////////////////////////////////////////

class Encryption : public Filter

{
protected:
    int key;
    
public:
    Encryption();
    Encryption(int k);
    int getKey();
    char transform(char ch);
};

/////////////////////////////////////////////////
/***********************************************
 *              class Uppercase                *
 ***********************************************/
/////////////////////////////////////////////////

class Uppercase : public Filter

{
protected:
    char ch_upper;
    
public:
    Uppercase();
    char transform(char ch);
    
};

/////////////////////////////////////////////////
/***********************************************
*              class Ciphertext                *
***********************************************/
/////////////////////////////////////////////////

class Ciphertext : public Filter

{
protected:
    int key;
    
public:
    Ciphertext();
    Ciphertext(int k);
    void doFilter(ifstream &in, ofstream &out);
    char uppercase(char ch);
    int getKey();
    char encrypt(char ch);
    char transform(char ch);
};

#endif 

