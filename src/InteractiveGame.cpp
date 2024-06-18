#include "InteractiveGame.h"

Maze::Maze() {
     maze = {
        {'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'}
    };

    // Set player initial position
    posX = 1;
    posY = 1;

    // Coins eaten starts at 0
    coinsEaten = 0;

    // Randomly spawn coins
    srand(time(NULL));
    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[i].size(); j++) {
            if (maze[i][j] == ' ' && rand() % 3 == 0) {
                maze[i][j] = '*';
                coinPositions.push_back(std::make_pair(i, j));
            }
        }
    }
}

void Maze::drawGame() {
  std::vector<std::vector<char>> updatedMaze = maze;

    system("clear");

    updatedMaze[posX][posY] = 'V'; // Assuming 'boat' is meant to represent the player

    // Draw all the coins
    for (auto& coinPos : coinPositions) {
        int x = coinPos.first;
        int y = coinPos.second;
        updatedMaze[x][y] = '*';
    }

    // Print the updated maze
    for (int i = 0; i < updatedMaze.size(); ++i) {
        for (int j = 0; j < updatedMaze[i].size(); ++j) {
            std::cout << updatedMaze[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


void Maze::movePlayer(char userInput) {
   switch (userInput) {
        case 'W':
            if (maze[posX - 1][posY] != '#') {
                --posX;
            }
            break;
        case 'A':
            if (maze[posX][posY - 1] != '#') {
                --posY;
            }
            break;
        case 'S':
            if (maze[posX + 1][posY] != '#') {
                ++posX;
            }
            break;
        case 'D':
            if (maze[posX][posY + 1] != '#') {
                ++posY;
            }
            break;
    }
    if (playerEatsCoin()) {
        ++coinsEaten;
        deleteCoin(posX, posY);
    }
}

bool Maze::playerEatsCoin() {
    for (auto& coinPos : coinPositions) {
        if (coinPos.first == posX && coinPos.second == posY) {
            return true;
        }
    }
    return false;
}

void Maze::deleteCoin(int x, int y) {
    for (auto it = coinPositions.begin(); it != coinPositions.end(); ++it) {
        if (it->first == x && it->second == y) {
            coinPositions.erase(it);
            maze[x][y] = ' ';
            break;
        }
    }
}

void Maze::playGame() {
    drawGame();

    char userInput;
    while (true) {
        std::cout << "Enter W, A, S, or D to move (When finsih press back-space && turn off caps 🤓): ";
        std::cin >> userInput;

        if (userInput == 'Q' || userInput == 'q') {
            std::cout << "Quitting game..." << std::endl;
            break;
        }

        movePlayer(userInput);

        if (playerEatsCoin()) {
            std::cout << "You collected a coin!" << std::endl;
           deleteCoin(posX, posY);
        }

        drawGame();

        if (isGameOver()) {
            displayGameOver();
            break;
        }
    }
}

 bool Maze::isGameOver() {
        return posX == maze.size() - 2 && posY == maze[0].size() - 2;
    }

 void Maze::displayGameOver() {
        if (posX == maze.size() - 2 && posY == maze[0].size() - 2) {
            std::cout << "Congratulations! You've reached the end of the maze!" << std::endl;
        } else {
            std::cout << "Game Over! You did not reach the end of the maze." << std::endl;
        }
    }

/*888888888888888888888888888888888888888888888888888888888888888888888*/

Snake::Snake() {

    // Initialize snakeBoard, letters, and LIST

    // Initialize snake with head position
    snake.push_back(std::make_pair(6, 6)); 
    snake.push_back(std::make_pair(5, 6)); 
    snake.push_back(std::make_pair(4, 6)); 
    snake.push_back(std::make_pair(3, 6));
    snake.push_back(std::make_pair(2, 6));
    snake.push_back(std::make_pair(1, 6));

   

    
    LIST = {
        {"camel", "This Animal used to travel across the Sahara desert."}
    };

   
    std::vector<std::string> keys;
    for (const auto& pair : LIST) {
        keys.push_back(pair.first);
    }
    std::random_shuffle(keys.begin(), keys.end());
    word = keys.front();
    guessedWord = std::string(word.length(), '_'); 

    // Initialize snakeBoard and letters board
    snakeBoard = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    letters = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '#', ' ', ' ', 'A', 'B', 'C', 'D', 'E', 'F', ' ', ' ', '#'},
        {'#', '#', ' ', ' ', 'G', 'H', 'I', 'J', 'K', 'L', ' ', ' ', '#'},
        {'#', '#', ' ', ' ', 'M', 'N', 'O', 'P', 'Q', 'R', ' ', ' ', '#'},
        {'#', '#', ' ', ' ', 'S', 'T', 'U', 'V', 'W', 'X', ' ', ' ', '#'},
        {'#', '#', ' ', ' ', ' ', 'Y', 'Z', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };
}



void Snake::drawGame() {
     //system("clear");

  // Clear the snakeBoard
    for (int i = 1; i < snakeBoard.size() - 1; ++i) {
        for (int j = 1; j < snakeBoard[i].size() - 1; ++j) {
            snakeBoard[i][j] = ' ';
        }
    }

    // Place snake on the board
    for (int i = 0; i < snake.size(); ++i) {
        int snakeX = snake[i].first;
        int snakeY = snake[i].second;
        if (snakeX >= 0 && snakeX < snakeBoard.size() && snakeY >= 0 && snakeY < snakeBoard[0].size()) {
            snakeBoard[snakeY][snakeX] = 'O';
        }
    }

    // Draw the snakeBoard
    for (int i = 0; i < snakeBoard.size(); ++i) {
        for (int j = 0; j < snakeBoard[i].size(); ++j) {
            std::cout << snakeBoard[i][j];
        }
        std::cout << '\n';
    }

    // Draw the letters board
    for (int i = 0; i < letters.size(); ++i) {
        for (int j = 0; j < letters[i].size(); ++j) {
            std::cout << letters[i][j];
        }
        std::cout << '\n';
    }

    // Display the guessed word
    std::cout << "Guessed Word: " << guessedWord << '\n';
}

void Snake::displayGameOver() {
      if (snake.size() > 1) {
    std::cout << "Congratulations! You've guessed the word!" << std::endl;
    } else {
        std::cout << "You lost! The correct word was " << word << std::endl;
        std::cout << "Game Over!😫" << std::endl;
        //std::this_thread::sleep_for(std::chrono::seconds(8));
        exit(0);
    }
}

bool Snake::isGameOver() {
    return guessedWord == word; 
}


bool Snake::searchWord(char userInput) {
      bool found = false;
    for (int i = 0; i < word.length(); ++i) {
        if (word[i] == userInput) {
            guessedWord[i] = userInput; // Update guessed word
            found = true;
        }
    }

    if (found) {
        for (int i = 0; i < letters.size(); ++i) {
            for (int j = 0; j < letters[i].size(); ++j) {
                if (letters[i][j] == toupper(userInput)) {
                    letters[i][j] = ' '; // Replace with a blank space
                    break;
                }
            }
        }
    }
    return found;
}

void Snake::transformSnake(bool found) {
       int newX = snake[0].first; 
    int newY = snake[0].second; 

    if (found) {
      
        snake.insert(snake.begin(), std::make_pair(newX, newY));
   
        //std::cout << "Snake grows in size!" << std::endl; 
    } else {
        snake.pop_back();
        std::cout << "Snake became weaker!" << std::endl; 
    }

   
    snakeBoard[newY][newX] = 'O';
}

void Snake::context() {
    std::cout << "Hint: " << LIST[word] << std::endl;
}

void Snake::playGame() {
      // system ("clear");
   drawGame(); 
    context();

    char user_input;
    while (!isGameOver() && snake.size() > 0) {

        std::cout << "Enter a letter: ";
        std::cin >> user_input;
        user_input = tolower(user_input); 
       
        drawGame();

        if (searchWord(user_input)) {
            std::cout << "Correct guess!" << std::endl;
            transformSnake(true); 
        } else {
            std::cout << "Incorrect guess!" << std::endl;
            transformSnake(false); 
            context();
        }

      
        drawGame();
    }

    drawGame();
    displayGameOver();
}
