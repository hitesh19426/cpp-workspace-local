#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

// struct Node
// {
//    /* data */
//    int val;
//    Node *next;

//    Node() : val(-1), next(nullptr){};
//    Node(int val) : val(val), next(nullptr){};
//    Node(int val, Node *next) : val(val), next(next){};
// };

struct Node
{
   int val;
   Node *next, *arbi;

   Node() : val(-1), next(nullptr), arbi(nullptr){};
   Node(int val) : val(val), next(nullptr), arbi(nullptr){};
   Node(int val, Node *next) : val(val), next(next), arbi(nullptr){};
};

void printUsingNext(Node *head)
{
   if (head == nullptr)
      return;
   Node *ptr = head;
   while (ptr != nullptr)
   {
      cout << ptr->val << " ";
      ptr = ptr->next;
   }

   cout << endl;
}

void printUsingRandom(Node *head)
{
   if (head == nullptr)
      return;

   Node *ptr = head;
   while (ptr)
   {
      cout << ptr->val << " ";
      ptr = ptr->arbi;
   }
   cout << endl;
}

void assignRandom(Node *head)
{
   if (head == nullptr || head->next == nullptr)
      return;

   Node *curr = head;
   while (curr)
   {
      curr->arbi = curr->next;
      curr = curr->next;
   }
}

Node *merge(Node *head1, Node *head2)
{
   Node *ptr1 = head1, *ptr2 = head2, *ptr = nullptr, *sorted = nullptr;

   while (ptr1 && ptr2)
   {
      if (ptr1->val < ptr2->val)
      {
         if (sorted == nullptr)
            ptr = sorted = ptr1;
         else
            ptr->arbi = ptr1, ptr = ptr1;
         ptr1 = ptr1->arbi;
      }
      else
      {
         if (sorted == nullptr)
            ptr = sorted = ptr2;
         else
            ptr->arbi = ptr2, ptr = ptr2;
         ptr2 = ptr2->arbi;
      }
   }

   if (ptr1)
      ptr->arbi = ptr1;
   if (ptr2)
      ptr->arbi = ptr2;

   return sorted;
}

Node *mergeSort(Node *head)
{
   if (head == nullptr || head->arbi == nullptr)
      return head;

   Node *slow = head, *fast = head->arbi, *next_head = nullptr;
   while (fast && fast->arbi)
   {
      slow = slow->arbi;
      fast = fast->arbi->arbi;
   }
   next_head = slow->arbi;
   slow->arbi = nullptr;

   Node *list1 = mergeSort(head);
   Node *list2 = mergeSort(next_head);

   Node *merged = merge(list1, list2);

   return merged;
}

int main()
{
   int arr[] = {10, 8, 25, 15, 20, 7, 3, 2};
   // int arr[] = {10, 8};
   int n = sizeof(arr) / sizeof(arr[0]);

   Node *head = new Node(arr[0]);
   Node *tail = head;
   for (int i = 1; i < n; i++)
   {
      tail->next = new Node(arr[i]);
      tail = tail->next;
   }
   // printUsingNext(head);

   Node *head2 = new Node(arr[0]);
   Node *tail2 = head2;
   for (int i = 1; i < n; i++)
   {
      tail2->next = new Node(arr[i]);
      tail2 = tail2->next;
   }
   printUsingNext(head2);
   // printUsingRandom(head2);

   assignRandom(head2);

   Node *random_head = mergeSort(head2);
   printUsingRandom(random_head);
}
