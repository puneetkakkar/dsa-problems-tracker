#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  void reverseArray(vector<int> &numbers)
  {
    if (numbers.size() == 0)
    {
      exit(0);
    }

    auto startIt = numbers.begin();
    auto lastIt = numbers.end() - 1;
    while (startIt < lastIt)
    {
      swapNumbers(numbers, startIt, lastIt);
      ++startIt;
      --lastIt;
    }

    cout << "Reversed Array " << endl;
    displayVector(numbers);
    cout << endl;
  }

  void swapNumbers(vector<int> &numbers, vector<int>::iterator startIt, vector<int>::iterator lastIt)
  {
    *startIt = *startIt + *lastIt;
    *lastIt = *startIt - *lastIt;
    *startIt = *startIt - *lastIt;
  }

  void displayVector(vector<int> &vec)
  {
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
      cout << *it << " ";
    }

    cout << endl;
  }
};

int main()
{
  Solution s;
  vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
  cout << "Original Array " << endl;
  s.displayVector(vec);
  s.reverseArray(vec);

  return 0;
}