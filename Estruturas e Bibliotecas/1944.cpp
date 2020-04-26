#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<string> pilha;

void initPilha()
{
  if (pilha.empty())
  {
    pilha.push("F A C E");
  }
}

int palindromo(string word1, string word2)
{
  int i = 0;
  stack<char> pilha1;
  while (i < word1.length())
  {
    pilha1.push(word1[i]);
    i++;
  }
  i = 0;
  while (i < word2.length())
  {
    if (pilha1.empty())
      break;
    if (word2[i] == pilha1.top())
      pilha1.pop();
    i++;
  }
  return pilha1.empty();
}

int main()
{
  int n, i = 0, winner = 0;
  string word;
  scanf("%i ", &n);
  while (i < n)
  {
    initPilha();
    getline(cin, word);
    if (palindromo(word, pilha.top()))
    {
      pilha.pop();
      winner++;
    }
    else
      pilha.push(word);
    i++;
  }
  cout << winner << endl;

  return 0;
}