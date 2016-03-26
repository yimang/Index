#ifndef INDEXPAGER_H
  #define INDEXPAGER_H

#include "pager.h"
#include <map>

using namespace std;

class IndexPager: public Pager
{
  map<string, int> WordKey;
  multimap<string, int> Indices;
  string parseWord(const string word, vector<int> &v);
  void pushText();
public:
  IndexPager();
  virtual void read(istream &in);
}; //IndexPager

#endif
