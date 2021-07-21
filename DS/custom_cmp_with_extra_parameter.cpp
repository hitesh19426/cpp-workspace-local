#include <bits/stdc++.h>
using namespace std;

int sumofdigit(int n)
{
   int sum = 0;
   while (n)
   {
      sum += n % 10;
      n /= 10;
   }
   return sum;
}

bool cmp(const int &a, const int &b)
{
   return sumofdigit(a) < sumofdigit(b);
}

int main(int argc, char const *argv[])
{
   /* code */
   vector<int> arr;
   srand(time(NULL));
   int n = 0 + rand() % 100;

   for (int i = 0; i < n; i++)
   {
      int x = rand() % 1000;
      arr.push_back(x);
   }

   for (int num : arr)
      cout << num << " ";
   cout << endl;

   stable_sort(arr.begin(), arr.end(), cmp);

   for (int num : arr)
      cout << num << " ";
   cout << endl;

   return 0;
}
