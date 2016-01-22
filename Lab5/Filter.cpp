///
/***********************************************
 * Filter.cpp
 * Created by Matthew D Mayberry on 5/2/15
 * CS162_400_S2015_Lab5
 ***********************************************/
///

#include "Filter.h"
#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;

/////////////////////////////////////////////////
/***********************************************
 *               class Filter                  *
 ***********************************************/
/////////////////////////////////////////////////

void Filter::doFilter(ifstream &in, ofstream &out)
{
    char c;
    while (in.get(c))
    {
        char t = this->transform(c);
        out << t;
    }
}


/////////////////////////////////////////////////
/***********************************************
 *             class Unchanged                 *
 ***********************************************/
/////////////////////////////////////////////////


/* Unchanged default constructor
 ***********************************************/
Unchanged::Unchanged()
{
    unch = '\0';
}


/* transform: passes through ch value to output unchanged
 ***********************************************/
char Unchanged::transform(char ch)
{
    char a;
    a = ch;
    return a;
}


////////////////////////////////////////////////
/***********************************************
 *             class Encryption                *
 ***********************************************/
/////////////////////////////////////////////////


/* Encrypytion default constructor
***********************************************/
Encryption::Encryption()
{
    key = 0;
}

/* Encrypytion default constructor with shift
 ***********************************************/
Encryption::Encryption(int k)
{
    key = k;
}

/* getKey: returns key when called
 ***********************************************/
int Encryption::getKey()
{
    return key;
}

/* transform: encrypts input message
   using user input shift key
 ***********************************************/
char Encryption::transform(char ch)
{
    
    const char upper_alph[26] = {'A','B','C','D','E','F',
                                 'G','H','I','J','K',
                                 'L','M','N','O','P',
                                 'Q','R','S','T','U',
                                 'V','W','X','Y','Z'};
    
    const char lower_alph[26] = {'a','b','c','d','e','f',
                                 'g','h','i','j','k',
                                 'l','m','n','o','p',
                                 'q','r','s','t','u',
                                 'v','w','x','y','z'};
    
    char a = ch;
    int shift;
    shift = this->getKey();
    
    if(isupper(a))
    {
        for(int i = 0; i < 26; i++)
            if(upper_alph[i] == a)
            {
                a = (upper_alph[(i + shift) % 26]);
                break;
            }
    }
    else
    {
        for(int i = 0; i < 26; i++)
            if(lower_alph[i] == a)
            {
                a = (lower_alph[(i + shift) % 26]);
                break;

            }
    }
    
    return a;
}

/////////////////////////////////////////////////
/***********************************************
 *              class Uppercase                *
 ***********************************************/
/////////////////////////////////////////////////


/* Uppercase default constructor
 ***********************************************/
Uppercase::Uppercase()
{
    ch_upper = '\0';
}


/* transform: checks if ch is lower and outputs upper
 ***********************************************/
char Uppercase::transform(char ch)
{
    char a = ch;
    a = toupper(a);
    return a;
}


/////////////////////////////////////////////////
/***********************************************
 *              class Ciphertext                *
 ***********************************************/
/////////////////////////////////////////////////


/* Ciphertext default constructor
 ***********************************************/
Ciphertext::Ciphertext()
{
    key = 0;
}

/* Ciphertext default constructor with shift
 ***********************************************/
Ciphertext::Ciphertext(int k)
{
    key = k;
}


/* doFilter: creates custom output, putting chars in blocks of five
 ***********************************************/
void Ciphertext::doFilter(ifstream &in, ofstream &out)
{
    char c;
    int count = 1;
    while (in.get(c))
    {
        if(count % 6 != 0)
        {
            if(c != ' ')
            {
                char t = this->transform(c);
                out << t;
                count++;
            }
        
            else
            {
                in.get(c);
            }
        }
       
        else
        {
            out << " ";
            count++;
        }
    }
}


/* transform: sends ch to Uppercase::transform
 and then to Encryption::transform
 ***********************************************/
char Ciphertext::transform(char ch)
{
    char a = ch;
    a = this->uppercase(a);
    a = this->encrypt(a);
    return a;
}

/* uppercase: checks if ch is lower and outputs upper
 ***********************************************/
char Ciphertext::uppercase(char ch)
{
    char a = ch;
    a = toupper(a);
    return a;
}


/* getKey: returns key when called
 ***********************************************/
int Ciphertext::getKey()
{
    return key;
}

/* encrypt: encrypts input message
 using user input shift key
 ***********************************************/
char Ciphertext::encrypt(char ch)
{
    {
        const char upper_alph[26] = {'A','B','C','D','E','F',
                                     'G','H','I','J','K',
                                     'L','M','N','O','P',
                                     'Q','R','S','T','U',
                                     'V','W','X','Y','Z'};
        
        const char lower_alph[26] = {'a','b','c','d','e','f',
                                     'g','h','i','j','k',
                                     'l','m','n','o','p',
                                     'q','r','s','t','u',
                                     'v','w','x','y','z'};
        
        char a = ch;
        int shift;
        shift = this->getKey();
        
        if(isupper(a))
        {
            for(int i = 0; i < 26; i++)
                if(upper_alph[i] == a)
                {
                    a = (upper_alph[(i + shift) % 26]);
                    break;
                }
        }
        else
        {
            for(int i = 0; i < 26; i++)
                if(lower_alph[i] == a)
                {
                    a = (lower_alph[(i + shift) % 26]);
                    break;
                    
                }
        }
        
        return a;
    }
}


