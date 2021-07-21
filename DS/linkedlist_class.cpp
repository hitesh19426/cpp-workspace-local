#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

struct Node
{
   int val;
   Node *next;

   Node() : val(-1), next(nullptr){};
   Node(int val) : val(val), next(nullptr){};
   Node(int val, Node *next) : val(val), next(next){};
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

void odd_even(Node *head, Node **oddhead, Node **evenhead)
{
   Node *oddtail = head, *eventail = head->next;
   Node *oddptr = head, *evenptr = head->next;
   *oddhead = head, *evenhead = head->next;

   do
   {
      oddptr = oddptr->next->next;
      oddtail->next = oddptr;
      oddtail = oddptr;

   } while (oddptr->next && oddptr->next->next);

   do
   {
      evenptr = evenptr->next->next;
      eventail->next = evenptr;
      eventail = evenptr;
   } while (evenptr->next && evenptr->next->next);

   oddtail->next = nullptr;
   eventail->next = nullptr;

   printUsingNext(*oddhead);
   printUsingNext(*evenhead);
}

Node *reverse(Node *head)
{
   if (head == nullptr || head->next == nullptr)
      return head;

   Node *cur = head, *prev = nullptr;
   while (cur)
   {
      Node *next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
   }
   return prev;
}

Node *merge(Node *oddhead, Node *evenhead)
{
   Node *odd = oddhead, *even = evenhead;
   Node *head = nullptr, *ptr = nullptr;
   while (even)
   {
      if (head == nullptr)
      {
         head = ptr = odd;
         ptr->next = even;
         ptr = even;
      }
      else
      {
         ptr->next = odd;
         ptr->next->next = even;
         ptr = even;
      }

      odd = odd->next;
      even = even->next;
   }

   if (odd->next)
      ptr->next = odd;

   return head;
}

Node *reverse_even(Node *head)
{
   if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
      return head;
   if (head->next->next->next == nullptr)
      return head;

   Node *oddhead, *evenhead;
   odd_even(head, &oddhead, &evenhead);

   printUsingNext(oddhead);
   printUsingNext(evenhead);
   // cout << endl;

   evenhead = reverse(evenhead);
   printUsingNext(evenhead);
   // cout << endl;

   head = merge(oddhead, evenhead);
   return head;
}

int main()
{
   int arr[] = {10, 8, 25, 15, 20, 7, 3, 2};
   // int arr[] = {10, 8};
   // int n = sizeof(arr) / sizeof(arr[0]);
   int n = 5;

   Node *head = new Node(arr[0]);
   Node *tail = head;
   for (int i = 1; i < n; i++)
   {
      tail->next = new Node(arr[i]);
      tail = tail->next;
   }
   cout << "Original List: \n";
   printUsingNext(head);
   // cout << endl;

   head = reverse_even(head);
   printUsingNext(head);
}
