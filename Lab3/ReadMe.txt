Lab3: Jingxuan Zou

warning C4018:  '>': signed/unsigned mismatch
warning C4715:  'TicTacToeGame::play': not all control paths return a value

1. success case with vertical identical:
Please input the position coordinate or 'quit':1,1
4
3
2
1   X
0
  0 1 2 3 4

Player X: 1,1
Please input the position coordinate or 'quit':2,1
4
3
2
1   X O
0
  0 1 2 3 4

Player O: 2,1
Please input the position coordinate or 'quit':1,2
4
3
2   X
1   X O
0
  0 1 2 3 4

Player X: 1,1;1,2
Please input the position coordinate or 'quit':2,2
4
3
2   X O
1   X O
0
  0 1 2 3 4

Player O: 2,1;2,2
Please input the position coordinate or 'quit':1,3
4
3   X
2   X O
1   X O
0
  0 1 2 3 4

Player X: 1,1;1,2;1,3
Player X wins the game.

2. success case with diagonal
Please input the position coordinate or 'quit':1,3
4
3   X
2
1
0
  0 1 2 3 4

Player X: 1,3
Please input the position coordinate or 'quit':1,1
4
3   X
2
1   O
0
  0 1 2 3 4

Player O: 1,1
Please input the position coordinate or 'quit':2,2
4
3   X
2     X
1   O
0
  0 1 2 3 4

Player X: 1,3;2,2
Please input the position coordinate or 'quit':2,1
4
3   X
2     X
1   O O
0
  0 1 2 3 4

Player O: 1,1;2,1
Please input the position coordinate or 'quit':3,1
4
3   X
2     X
1   O O X
0
  0 1 2 3 4

Player X: 1,3;2,2;3,1
Player X wins the game.

3. draw case
Please input the position coordinate or 'quit':1,1
4
3
2
1   X
0
  0 1 2 3 4

Player X: 1,1
Please input the position coordinate or 'quit':1,2
4
3
2   O
1   X
0
  0 1 2 3 4

Player O: 1,2
Please input the position coordinate or 'quit':2,2
4
3
2   O X
1   X
0
  0 1 2 3 4

Player X: 1,1;2,2
Please input the position coordinate or 'quit':2,3
4
3     O
2   O X
1   X
0
  0 1 2 3 4

Player O: 1,2;2,3
Please input the position coordinate or 'quit':1,3
4
3   X O
2   O X
1   X
0
  0 1 2 3 4

Player X: 1,1;2,2;1,3
Please input the position coordinate or 'quit':3,1
4
3   X O
2   O X
1   X   O
0
  0 1 2 3 4

Player O: 1,2;2,3;3,1
Please input the position coordinate or 'quit':2,1
4
3   X O
2   O X
1   X X O
0
  0 1 2 3 4

Player X: 1,1;2,2;1,3;2,1
Please input the position coordinate or 'quit':3,3
4
3   X O O
2   O X
1   X X O
0
  0 1 2 3 4

Player O: 1,2;2,3;3,1;3,3
Please input the position coordinate or 'quit':3,2
4
3   X O O
2   O X X
1   X X O
0
  0 1 2 3 4

Player X: 1,1;2,2;1,3;2,1;3,2
9 turns were played. There are no winning moves remain.

4. quit case
Please input the position coordinate or 'quit':2,2
4
3
2     X
1
0
  0 1 2 3 4

Player X: 2,2
Please input the position coordinate or 'quit':quit
1 turns were played. The user quit.

5. wrong user input
Please input the position coordinate or 'quit':1,4
Please input the position coordinate or 'quit':haha
Please input the position coordinate or 'quit':33
Please input the position coordinate or 'quit':1,2
4
3
2   X
1
0
  0 1 2 3 4

Player X: 1,2
Please input the position coordinate or 'quit':1,2
Please input the position coordinate or 'quit':

6. wrong argument statement
H:\Repository\lab3-aprileezou\Lab3\Debug>Lab3.exe TicTacTo
usage:lab3<Lab3.exe>: The command line should be only 'TicTacToe'.

H:\Repository\lab3-aprileezou\Lab3\Debug>Lab3.exe Tic Tac
usage:lab3<Lab3.exe>: The command line should be only 'TicTacToe'.