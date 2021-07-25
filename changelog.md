#Changelog
## 7/20/21
- started project
- added GameBoard class
- completed board dispaly, piece placement, input checking
- completed bounds checking for board input
## 7/21/21
- moved game flow to new function, startgame()
- added Doctest for automated testing
- stated tests for piece input and maxed out columns
## 7/22/21
- added win condition checking functions
- moved input checking to separate function, isValidColumn()
- added additional tests for win conditions and valid input stream
- added win check for draw in doMoveAndChangePlayer function. Might want to break it out to make it more readable
- game works!
## 7/24/21
- added GameState class for tree search and board states
- added GameBoardMCTS:GameBoard to separate AI board from regular board
- added preliminary Node clas to prepare for tree search
- added several functions to obtain, fill, then return possible moves in GameBoardMCTS
- GameState successfully does all possible moves and saves them in a vector for AI use
- added new tests for new possible states functionality
- adjusted some constructors in GameBoardMCTS and GameBoard to fix default constructor error
