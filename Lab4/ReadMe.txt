Lab4        GroupName: Fitness,           GroupMembers: Qi Yang(466235), Yixuan Cheng(467013) Jingxuan Zou(463504)
Here is how we divided our team work:
Qi Yang and Yixuan Cheng worked together to refactor codes from Lab3(here we use the version of Qi Yang's) and adding second game.
All of us designed how to test draw() and modify codes to complete extra parts.
Jingxuan Zou helped to fix errors and warnings.
Qi Yang drafted ReadMe.txt, Yixuan Cheng and Jingxuan Zou examined and modified ReadMe.txt.

Warnings and Errors:
1. signed/unsigned > mismatch
   Solution: cast the unsigned variable and store it into another signed variable before use.

2. Method "check" already has a body.
   Solution: delete the {} after check in header file where there supposed to be onnly definition of method.

3. Term does not evaluate 2 assignments.
   Solution: Mistakenly using std::max() to select the biggest number among 3 numbers while it can only take 2 arguments. So instead of using max() once, I used it twice to 
             get the biggest number from the 3 numbers.

4. Uninitialized local variable used.
   Solution: In the check funtion, at first I did not initialize the pointer to GameBase (whose name is ab) before I return it. So I corrected it by initializing ab as a nullptr.

5. Program did work correctly becasue of vector subscript out of range.
   Solution: After checking, I find out the problem is caused by a typo in a nested for loop. The first for loop uses int j to loop while the second loop uses int i to loop.
             In the second loop, I should write ++i, but I wrote ++j. Then I corrected the typo, the program worked.


Test Case:
1. Test whether the program can behave correctly when run with Lab4.exe TicTacToe and Lab4.exe Gomoku.
   Result: The program can detect which game we are saying and print out the corresponding gameboard next, waiting for the player's input.

2. Test whether the program can handle with badly formed input moves, such as 3 3.5 3-4.
   Result: The program can dectec the input move is badly formed and ask the player to input again. The output looks as the following:
           Badly formed coordinates, the form of the correct coordinates should be x,y, please enter again:
           please enter quit to end the game or coordinates to indicate the square where you want to place your piece.

3. Test whether the program can handle the situation that the input move of the currect player has already made by her or the other player.
   Result: The program can detect such situation, informing the current player the square she chose has already been taken. Then ask her to input again.
           The output listed in the following:
		   This position has already be taken, please enter again:
           White Stone's turn:
           please enter quit to end the game or coordinates to indicate the square where you want to place your piece.

4. Test whether the program can behace correctly when one of the player wants to quit.
   Result: The game exits correctly with correct information. The output is as following:
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4
3
2
1
0  B
X  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18
There are 1 turn have been made, but White Stone decided to quit.

5. Test whether the program can behave correctly with a valid input move.
   Result: The program did behave correctly.
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4
3
2
1
0  B
X  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18
White Stone's turn:
please enter quit to end the game or coordinates to indicate the square where you want to place your piece.

6. Test whether the program can handle when player input a move that is beyond the range of the gameBoard.
   Result: The program informs the player that the move she inputed is invalid and out of range and what the correct range of gameBoard is.
           The output is as following:
           Invalid Square, the range of coordinates is only between 0,0 to 18,18, please enter again:
           please enter quit to end the game or coordinates to indicate the square where you want to place your piece.

7. Test whether the program can handle when one player wins in a vertical line and exits the game then.
   Result: The program behaves correctly. The output is as following:
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4  B
3  B  W
2  B  W
1  B  W
0  B  W
X  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18
There are 9 turns have been made, and Black Stone wins.

8. Test whether the program can handle when one player wins in a horizontal line and exits the game then.
   Result: The program behaves correctly. Then output is as following:
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4
3
2
1  W  W  W  W
0  B  B  B  B  B
X  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18
There are 9 turns have been made, and Black Stone wins.

9. Test whether the program can handle when one player wins in a diagonal line and exits the game then.
   Result: The program behaves correctly. Then output is as following:
(from bottom left to up right)
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4              B
3           B
2        B
1     B
0  B  W  W  W  W
X  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18
There are 9 turns have been made, and Black Stone wins.

(from up left to bottom right)
18 B
17    B
16       B
15          B
14             B
13
12
11
10
9
8
7
6
5
4
3
2
1
0  W  W  W        W
X  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18
There are 9 turns have been made, and Black Stone wins.

10. Test whether the program can behave correctly when there is no willing move thant it would exit the game at this moment and informs it is a draw.
    Considering the default gameBoard for Gomoku is too big, we'd like to test it in a smaller gameBoard like 3x3 or 4x4 gameBoard.
	Result: The program works well and exits the game early when it notice there is no winning move left. It also worked well even if the players
	        insist to play until the gameBoard is full and still is a draw.
			The outputs for different situations are as following:
(Lab4.exe Gomoku 3 3)
2 W B W
1 W B
0 B W B
X 0 1 2
There are 8 turns have been made, but no one wins. It is a draw.
(Lab4.exe Gomoku 4 3)
3 W   B B
2 B B W W
1 W W B B
0 B B W W
X 0 1 2 3
There are 15 turns have been made, but no one wins. It is a draw.
(Lab4.exe Gomoku 4 4)
3 W B
2 B B W
1 W W B W
0 B B W B
X 0 1 2 3
There are 13 turns have been made, but no one wins. It is a draw.

11. Test whether the program can handle if we give it wrong number of arguments.
    Result: The program behaves correctly and gave us usage message on how to call the program correctly.
	        The output is as following:
Wrong number of arguments. Number of arguments should only be 2, 3 or 4, including program name.

12. Test whether the program can handle if we give it wrong arguments, such as Lab4.exe T.
    Result: The program handles it properly, the output is as following:
If you want to play TicTacToe in the default way, please enter Lab4.exe TicTacToe
If you want to play Gomoku in the default way, please enter Lab4.exe Gomoku

Extra Part:
Below is how we designed the extra part:
The methods we need change so that the program can handle arbitrary sized board and number of connecting pieces to win are the other constructor and done().
We designed another constructor to take 3 input int, the first 2 are used to assign width and height by passing into the constructor of GameBase and the last
one is used to initialize winNum, which is the unique member variable of Gomoku to indicate the number of connecting pieecs to win. When we need to decide if
one player has winned, we use the member variable to compare instead of using the specific number 5.
Therefore, our program is more generic to take arbitrary sized boards and arbitrary number of connecting pieces to win.

After testing many different combinations of board size and number of connecting pieces to win, the program worked well.
The output of additional arguments 10 and 4 is as following:
9
8
7
6
5
4
3
2
1 W W W
0 B B B B
X 0 1 2 3 4 5 6 7 8 9
There are 7 turns have been made, and Black Stone wins.

Most of test cases of extra part are similar to test cases above, here we will test how the program would hanlde 
if we input a zero or negative board size or number of connecting pieces to win.

With 3 arguments and the third one is -1, the output is:
Width or height of a board could not be less than 0.

With 4 arguments and the third one is -1 and the last one is -2, the output is:
Width or height of a board could not be less than 0.
Number of connecting pieces to win could not be less than 0 either.

