#include <iostream>
#include <string>
#include <vector>

// https://edabit.com/challenge/jbf8yyjMnN7bt3H5s
std::vector<std::vector<int>> multiplicationTable(int n)
{
  std::vector<std::vector<int>> table;

  for (int i = 0; i < n; i++)
  {
    table.push_back(std::vector<int>());

    for (int j = 0; j < n; j++)
      table[i].push_back(i * j);
  }

  return table;
}

// https://edabit.com/challenge/s695FkhRd3J65tmdQ
std::string doubleSwap(std::string s, char c1, char c2)
{
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == c1)
      s[i] = c2;
    else if (s[i] == c2)
      s[i] = c1;
  }

  return s;
}

// https://edabit.com/challenge/XmPeXa5fzwxkpvRhz
std::vector<int> sumOddAndEven(std::vector<int> arr)
{
  int eSum = 0;
  int uSum = 0;

  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] % 2)
      uSum += arr[i];
    else
      eSum += arr[i];
  }

  return std::vector<int> { eSum, uSum };
}

// https://edabit.com/challenge/wvEELKb9nawzRSucg - najjednostavnije rjesenje
std::vector<int> sortNumsAscending(std::vector<int> arr)
{
  bool swapped = true;

  while (swapped)
  {
    swapped = false;
    for (int i = 0; i < arr.size() - 1; i++)
    {
      if (arr[i + 1] < arr[i])
      {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        swapped = true;
      }
    }
  }

  return arr;
}

// https://edabit.com/challenge/868Q9JmTSAEhZBBrg
std::string tweakLetters(std::string s, int arr[])
{
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] + arr[i] > 'z')
      s[i] += arr[i] - 'z' + 'a' - 1;
    else if (s[i] + arr[i] < 'a')
      s[i] += arr[i] + 'z' - 'a' + 1;
    else
      s[i] += arr[i];
  }

  return s;
}

// https://edabit.com/challenge/7iT6DbY3GsHnLBPq4
std::vector<int> noOdds(std::vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
    if (arr[i] % 2) arr.erase(arr.begin() + i--);
  return arr;
}

// https://edabit.com/challenge/rscwis53jKokoKRYo
std::string ticTacToe(std::vector<std::vector<char>> inputs)
{
  bool p1 = true;
  bool p2 = true;

  for (int i = 0; i < inputs.size(); i++)
  {
    for (int j = 0; j < inputs[0].size(); j++)
      std::cout << inputs[i][j] << " ";
    std::cout << std::endl;
  }

  for (int i = 0; i < inputs.size(); i++)
  {
    // ---
    // ---
    // ---

    p1 = true;
    p2 = true;
    for (int j = 0; j < inputs[0].size(); j++)
    {
      if (inputs[i][j] != 'X')
        p1 = false;
      if (inputs[i][j] != 'O')
        p2 = false;
    }

    if (p1 || p2)
      break;

    // | | |
    // | | |
    // | | |

    p1 = true;
    p2 = true;
    for (int j = 0; j < inputs[0].size(); j++)
    {
      if (inputs[j][i] != 'X')
        p1 = false;
      if (inputs[j][i] != 'O')
        p2 = false;
    }

    if (p1 || p2)
      break;

    if (i > 0)
      continue;

    // \ # #
    // # \ #
    // # # \ 

    p1 = true;
    p2 = true;
    for (int j = 0; j < inputs[0].size(); j++)
    {
      if (inputs[j][j] != 'X')
        p1 = false;
      if (inputs[j][j] != 'O')
        p2 = false;
    }

    if (p1 || p2)
      break;

    // # # /
    // # / #
    // / # #

    p1 = true;
    p2 = true;
    for (int j = 0; j < inputs[0].size(); j++)
    {
      if (inputs[inputs[0].size() - j - 1][j] != 'X')
        p1 = false;
      if (inputs[inputs[0].size() - j - 1][j] != 'O')
        p2 = false;
    }

    if (p1 || p2)
      break;
  }

  if (p1)
    return "Player 1 wins";

  if (p2)
    return "Player 2 wins";

  return "It's a Tie";
}

// https://leetcode.com/problems/rotated-digits/description/
int rotatedDigits(int n)
{
  unsigned short out = 0;
  for (unsigned short i = 1; i <= n; i++)
  {
    unsigned char dig = 0;
    unsigned short t = i;
    unsigned short newN = 0;
    unsigned short digIndex = 1;
    bool valid = true;
    while (t > 0)
    {
      dig = t % 10;

      if (dig == 3 || dig == 4 || dig == 7)
      {
        valid = false;
        break;
      }

      switch (dig)
      {
      case 2: dig = 5; break;
      case 5: dig = 2; break;
      case 6: dig = 9; break;
      case 9: dig = 6; break;
      }

      newN += dig * digIndex;
      digIndex *= 10;
      t /= 10;
    }

    if (valid && newN != i) out++;
  }

  return out;
}

// https://leetcode.com/problems/count-number-of-homogenous-substrings/description/
long long countHomogenous(std::string s)
{
  long long count = 0;
  int subcount = 1;
  const char* arr = s.c_str();
  char lastChar = '\0';

  for (int i = 0; i < s.size(); i++)
  {
    if (arr[i] == lastChar)
    {
      subcount++;
      count += subcount;
    }
    else
    {
      lastChar = arr[i];
      subcount = 1;
      count++;
    }
  }

  return count % (10L * 10L * 10L * 10L * 10L * 10L * 10L * 10L * 10L + 7L); // 10^9 + 7
}

// https://leetcode.com/problems/odd-even-linked-list/description/
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode* next) : val(x), next(next) { }
};

ListNode* oddEvenList(ListNode* head)
{
  if (head == nullptr) return head;

  ListNode* oddSearch = head->next;
  ListNode* headCopy;
  unsigned short numElements = 0;

  for (headCopy = head; headCopy != nullptr; headCopy = headCopy->next) numElements++;

  headCopy = head;
  unsigned short iters = numElements % 2 ? numElements / 2 : numElements / 2 - 1;
  delete (&numElements);

  for (unsigned short i = 0; i < iters; i++)
  {
    ListNode* oddCopy = oddSearch;
    oddSearch = oddSearch->next->next;

    ListNode* node = oddCopy->next;
    oddCopy->next = node->next;

    node->next = headCopy->next;
    headCopy->next = node;

    headCopy = headCopy->next;
  }

  return head;
}
