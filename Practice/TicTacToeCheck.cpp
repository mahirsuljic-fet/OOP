#include <iostream>
#include <ostream>
#include <string>
#include <vector>

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

int main(int argc, char *argv[])
{
  std::cout << ticTacToe({{'X', 'O', 'O'},
                          {'O', 'X', 'O'},
                          {'O', '#', 'X'}})
            << std::endl;

  std::cout << ticTacToe({{'X', 'O', 'O'},
                          {'O', 'X', 'O'},
                          {'O', '#', 'O'}})
            << std::endl;

  std::cout << ticTacToe({{'X', 'O', 'O'},
                          {'O', 'X', 'O'},
                          {'O', 'O', '#'}})
            << std::endl;

  std::cout << ticTacToe({{'X', 'O', 'O'},
                          {'X', 'X', 'O'},
                          {'X', 'O', '#'}})
            << std::endl;

  std::cout << ticTacToe({{'X', '#', 'O'},
                          {'X', 'X', 'O'},
                          {'#', 'O', '#'}})
            << std::endl;

  std::cout << ticTacToe({{'X', 'X', 'X'},
                          {'X', 'O', 'O'},
                          {'O', 'O', 'X'}})
            << std::endl;

  std::cout << ticTacToe({{'X', 'O', 'O'},
                          {'X', 'O', 'O'},
                          {'O', 'X', 'X'}})
            << std::endl;

  std::cout << ticTacToe({{'X', 'O', 'O'},
                          {'X', 'O', 'O'},
                          {'#', 'X', 'X'}})
            << std::endl;

  std::cout << ticTacToe({{'X', 'O', 'O'},
                          {'O', 'O', 'O'},
                          {'#', 'X', 'X'}})
            << std::endl;

  return 0;
}
