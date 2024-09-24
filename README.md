# Sudoku Generator and Solver

This project is a Sudoku puzzle generator implemented in C++, utilizing the backtracking algorithm and a randomizer to generate Sudoku puzzles of various sizes. It also offers three difficulty levels to cater to different players' preferences.

## Introduction

Sudoku is a popular logic-based number puzzle game. The objective is to fill a grid with digits from 1 to 9 (or any desired size), ensuring that each column, each row, and each of the subgrids contains all of the digits from 1 to 9. This project aims to generate Sudoku puzzles automatically with the ability to adjust the size and difficulty level.

## Features

- Generate Sudoku puzzles of desired size (e.g., 4x4, 9x9, 16x16, etc.).
- Utilizes the backtracking algorithm to ensure the generated puzzle has a unique solution.
- Offers three difficulty levels: easy, medium, and hard.
- Uses a randomizer to create a variety of puzzles within the same difficulty level.
- Automatically validates the generated puzzle to ensure it is solvable and meets the requirements of a standard Sudoku puzzle.
- Also solve desired puzzle using the solver

## Usage

1. Clone this repository to your local machine:

```sh
git clone https://github.com/jayantp2003/Sudoku-Generator.git

```

2. Compile the source code using a C++ compiler of your choice:

```sh
g++ generator.cpp

```

3. Run the executable with the desired options.

```text
./a.exe 
```

4. Compile the source code using a C++ compiler of solver:

```sh
g++ solve.cpp
```

That's it! Have fun generating Sudoku puzzles with different sizes and difficulty levels and solving them. Enjoy solving them!
