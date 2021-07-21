#include <bits/stdc++.h>
using namespace std;

vector<int> votingalgo(vector<int> &arr, int k)
{
   int n = arr.size();
   vector<int> can(k - 1, arr[0]);
   vector<int> count(k - 1, 0);

   for (int i = 0; i < n; i++)
   {
      bool found = false;
      for (int j = 0; j < k - 1; j++)
      {
         if (arr[i] == can[j])
         {
            count[j]++;
            found = true;
            break;
         }
      }

      if (found)
         continue;

      bool found2 = false;
      for (int j = 0; j < k - 1; j++)
      {
         if (count[j] == 0)
         {
            can[j] = arr[i];
            count[j]++;
            found2 = true;
            break;
         }
      }

      if (found2)
         continue;

      for (int j = 0; j < k - 1; j++)
         count[j]--;
   }

   fill(count.begin(), count.end(), 0);

   for (int j = 0; j < k - 1; j++)
   {
      for (int itr = 0; itr < n; itr++)
         if (arr[itr] == can[j])
            count[j]++;
   }

   set<int> s;
   for (int itr = 0; itr < k - 1; itr++)
      if (count[itr] > n / k)
         s.insert(can[itr]);

   vector<int> ans;
   for (int can : s)
      ans.push_back(can);

   return ans;
}

int main()
{
   vector<int> arr{1, 2, 3, 3, 4, 4, 1, 1, 2, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4};
   int n = arr.size();
   int k = 2; // standard voting algo

   vector<int> majority = votingalgo(arr, k);
   for (int major : majority)
      cout << major << " ";
   cout << endl;

   return 0;
}
