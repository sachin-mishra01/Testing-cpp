#include <iostream>
using namespace std;
int division(int a, int b, int count = 0)
{
  if (a == b)
  {
    return count+1;
  }
  if (a > b)
  { count+=1;
    division((a - b), b, count);
  }
  else
  {
    return count;
  }
}
int main()
{
  int a, b;
  cout << "Enter two number for division :";
  cin >> a >> b;
  cout << "The result " << division(a, b);
  return 0;
}