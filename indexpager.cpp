#include <sstream>
#include <algorithm> 
#include <vector>
#include <map>
#include "indexpager.h"
using namespace std;

IndexPager::IndexPager(): Pager()
{
  
} // Pager()

string IndexPager::parseWord(const string word, vector<int> &v)
{
  string s(word + ' ' + intToString(*v.begin())); //puts first line in
  int prev = *v.begin(); //causes first skip in for loop
  vector<int>::iterator itr;
  
  for(itr = v.begin(); itr != v.end(); itr++)
  {
    if(*itr == prev); //skip duplicates
    
    else // if in sequence
      if(*itr == prev + 1)
    {
      while((*itr == prev + 1 || *itr == prev) && itr != v.end()) 
        prev = *itr++; //go through squence or duplicates
      s.append('-' + intToString(prev));
      itr--;
    }//consecutives
    
    else s.append(", " + intToString(*itr)); // new index
    
    prev = *itr;
  }//all vector indecies
  
  s += '.';
  return s;
}//with vector of indicies and word key(count) outputs proper line

void IndexPager::read(istream &in)
{
  string s, buff;
  string::iterator sitr;
  int line = 0;
  
  while(getline(in, buff))
  {
    sitr = buff.begin();
    
    while(sitr != buff.end())
    {
      s.clear();
      
      while (!isalpha(*sitr) && sitr != buff.end()) sitr++; //skip nonalpha
      
      while (isalpha(*sitr) && sitr != buff.end()) s += *sitr++;
      
      if(!s.empty()) Indices.insert(pair<string, int>(s, line));
      
    }//till end of line
    
    line++;
  }// initializes WordKey and Indices
  
  pushText();
}  // read()

void IndexPager::pushText()
{
  vector<int> v;
  string s, buff;
  multimap<string, int>::iterator itr = Indices.begin();
  buff = itr->first;
  
  for(; itr != Indices.end(); itr++)
  {
    if(buff != itr->first)
    {
      sort(v.begin(), v.end());
      s = parseWord(buff, v); //gives line for each word
      text.push_back(s);
      buff = itr->first;
      v.clear();
    }//pushes line to Text when new word is found
    
    v.push_back(itr->second); // adds indices to vector
  } // for every index
  
  sort(v.begin(), v.end()); // for last word
  s = parseWord(buff, v);
  text.push_back(s);
} // pushText