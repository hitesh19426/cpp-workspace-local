#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

// check whether b contains anagram of a as substring
bool contains_anagram(string a, string b)
{
   if (a.size() > b.size())
      return false;

   vector<int> mapa(26, 0), mapb(26, 0);
   for (int ch : a)
      mapa[ch - 'a']++;

   int window_size = a.size(), n = b.size();
   for (int i = 0; i < window_size; i++)
      mapb[b[i] - 'a']++;

   for (int i = 0; i + window_size - 1 < n; i++)
   {
      if (i != 0)
      {
         mapb[b[i - 1] - 'a']--;
         mapb[b[i + window_size - 1] - 'a']++;
      }

      if (mapa == mapb)
         return true;
   }

   return false;
}

int main()
{
   string a = "ab", b = "bbpobac"; // yes - ba
   // string a = "ab", b = "cbddaoo"; // no
   vector<pair<string, string>> tests{{"ab", "bbpobac"}, {"ab", "cbddaoo"}};

   for (auto test : tests)
      cout << contains_anagram(test.first, test.second) << endl;

   // cout << contains_anagram(a, b);

   return 0;
}
