#include <iostream>
#include <string>
#include <stack>

using namespace std;

void result(stack<int> pill)
{
  if (pill.empty())
    cout << "Yes\n";
  else
    cout << "No\n";
}

stack<int> clear(stack<int> pill)
{
  while (!pill.empty())
    pill.pop();
  return pill;
}

void verify(int qtdCol)
{
  stack<int> pilha, trem;
  int next, vagao, i;
  while (true)
  {
    i = 0;
    next = qtdCol;
    pilha = clear(pilha);
    trem = clear(trem);
    while (i < qtdCol)
    {
      cin >> vagao;
      if (vagao == 0)
        return;
      trem.push(vagao);

      i++;
    }

    while (!trem.empty())
    {
      pilha.push(trem.top());

      while (pilha.top() == next)
      {
        pilha.pop();
        next--;
        if (pilha.empty())
          break;
      }

      trem.pop();
    }

    result(pilha);
  }
}

int main()
{
  int n;
  while (true)
  {
    cin >> n;
    if (n == 0)
      break;
    verify(n);
    cout << endl;
  }

  return 0;
}