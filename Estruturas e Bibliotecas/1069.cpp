#include <iostream>
#include <string>
#include <stack>
#define MAX = 1000;

using namespace std;

stack<char> pilha;

void clear()
{
  while (!pilha.empty())
  {
    pilha.pop();
  }
}

int main()
{
  int n, i = 0, diamante = 0;
  string mina;
  char lixo;

  scanf("%i ", &n);
  while (i < n)
  {
    clear();
    diamante = 0;
    getline(cin, mina);
    for (int i = 0; i < mina.length(); i++)
    {
      if (mina[i] == '<')
      {
        pilha.push(mina[i]);
      }
      else if (mina[i] == '>' && !pilha.empty())
      {
        pilha.pop();
        diamante++;
      }
    }
    cout << diamante << endl;
    i++;
  }
  return 0;
}