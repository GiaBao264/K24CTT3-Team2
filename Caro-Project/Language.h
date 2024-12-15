#ifndef _Language_H_
#define _Language_H_
#include "Library.h"

using namespace std;

// Declare maps as extern to allow linkage across multiple files  
extern map<string, string> english, vietnamese;
extern map<string, string>* selectedLanguage;


void language(int Xi, int Yi);
void dict();

#endif
