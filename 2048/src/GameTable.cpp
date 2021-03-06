/*
 * Game2048.cpp
 *
 *  Created on: May 2, 2014
 *      Author: libesz
 *
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---O---+---O---+---O---+---O---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---O---+---O---+---O---+---O---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---O---+---O---+---O---+---O---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---O---+---O---+---O---+---O---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 * 0,0
 *
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---O---O---O---O---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---O---O---O---O---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---O---O---O---O---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---O---O---O---O---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 * 0,0
 *
 *  O---+---+---O---+---+---O---+---+---O
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  O---+---+---O---+---+---O---+---+---O
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  O---+---+---O---+---+---O---+---+---O
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  O---+---+---O---+---+---O---+---+---O
 * 0,0
 *
 */

#include <GameTable.h>
#include <stdexcept>
#include <ctime>
#include <algorithm>

namespace FadeCube {

const std::array<int, 11> GameTable::validValues{{2,4,8,16,32,64,128,256,512,1024,2048}};

GameTable::GameTable(CubeProp newCubeProp, int newGridX, int newGridY) :
    cubeProp(newCubeProp), gridX(newGridX), gridY(newGridY), freePlaces(0), score(
        0) {
  slots.resize(gridX);
  for (int i = 0; i < gridX; i++) {
    slots[i].resize(gridY);
    for (int j = 0; j < gridY; j++) {
      slots[i][j] = 0;
    }
  }
  rng.seed(time(0));
}

int GameTable::getSlotValue(int row, int col) const {
  std::lock_guard<std::mutex> lock(sLock);

  return slots[row][col];
}

GameTable::~GameTable() {
  // TODO Auto-generated destructor stub
}

void GameTable::checkValue(int value) {
  if (std::find(validValues.begin(), validValues.end(), value)
      == validValues.end())
    throw std::runtime_error("invalid value");
}

void GameTable::setSlotValue(int row, int col, int value) {
  checkValue(value);
  std::lock_guard<std::mutex> lock(sLock);
  slots[row][col] = value;
}

void GameTable::generateAtRandomEmptyPlace() {
  std::vector<int*> emptySlots;
  for (int i = 0; i < gridX; i++)
    for (int j = 0; j < gridY; j++)
      if (!slots[i][j])
        emptySlots.push_back(&slots[i][j]);

  if (!emptySlots.size())
    throw std::runtime_error("no free place");

  freePlaces = emptySlots.size() - 1;
  std::uniform_int_distribution<int> genPlace(0, emptySlots.size() - 1);
  std::lock_guard<std::mutex> lock(sLock);
  *emptySlots[genPlace(rng)] = validValues[0];
}

int GameTable::getGridX() const {
  return gridX;
}

int GameTable::getGridY() const {
  return gridY;
}

/* merge functions are borrowed from clinew, thanks for it!
 * https://github.com/clinew/2048
 */

GameResult GameTable::boardDone() const {
  int i;
  int j;
  int k;

// Check for winning number.
  for (i = 0; i < gridX; i++) {
    for (j = 0; j < gridY; j++) {
      if (slots[i][j] == validValues.back()) {
        return GameResult::WIN;
      }
    }
  }

//Check for zeroes
  for (i = 0; i < gridX; i++) {
    for (j = 0; j < gridY; j++) {
      if(!slots[i][j]) {
        return GameResult::UNKNOWN;
      }
    }
  }

// Check for possible horizontal merge.
  for (i = 0; i < gridX; i++) {
    j = -1;
    while ((k = ++j + 1) < gridY) {
      if (slots[i][j] == slots[i][k]) {
        return GameResult::UNKNOWN;
      }
    }
  }

// Check for possible verical merge.
  for (i = 0; i < gridY; i++) {
    j = -1;
    while ((k = ++j + 1) < gridX) {
      if (slots[j][i] == slots[k][i]) {
        return GameResult::UNKNOWN;
      }
    }
  }

// No possible merges.
  return GameResult::LOSE;
}

bool GameTable::mergeDown() {
  std::lock_guard<std::mutex> lock(sLock);

  int i;
  int j;
  int k;
  bool valid = false;

// Merge elements downwards.
  for (i = 0; i < gridY; i++) {
    j = gridX - 1;
    while (1) {
// Find two potential elements to merge.
      while (j >= 0 && !slots[j][i]) {
        j--;
      }
      k = j - 1;
      while (k >= 0 && !slots[k][i]) {
        k--;
      }
      if (k < 0) {
        break;
      }

// Try to merge the tiles.
      if (slots[j][i] == slots[k][i]) {
        score += slots[k][i];
        slots[k][i] += slots[k][i];
        slots[j][i] = 0;
        j = k - 1;
        valid = true;
      } else {
        j = k;
      }
    }

  }

// Return whether an item was merged or not.
  return valid;
}

bool GameTable::mergeUp() {
  std::lock_guard<std::mutex> lock(sLock);

  int i;
  int j;
  int k;
  bool valid = false;

// Merge elements upwards.
  for (i = 0; i < gridY; i++) {
    j = 0;
    while (1) {
// Find two potential tiles to merge.
      while (j < gridX && !slots[j][i]) {
        j++;
      }
      k = j + 1;
      while (k < gridX && !slots[k][i]) {
        k++;
      }
      if (k >= gridX) {
        break;
      }

// Try to merge the tiles.
      if (slots[j][i] == slots[k][i]) {
        score += slots[j][i];
        slots[j][i] += slots[j][i];
        slots[k][i] = 0;
        j = k + 1;
        valid = true;
      } else {
        j = k;
      }
    }
  }

// Return whether an item was merged or not.
  return valid;
}

bool GameTable::mergeLeft() {
  std::lock_guard<std::mutex> lock(sLock);

  int i;
  int j;
  int k;
  bool valid = false;

// Merge items leftwards.
  for (i = 0; i < gridX; i++) {
    j = 0;
    while (1) {
// Two two potential tiles to merge.
      while (j < gridY && !slots[i][j]) {
        j++;
      }
      k = j + 1;
      while (k < gridY && !slots[i][k]) {
        k++;
      }
      if (k >= gridY) {
        break;
      }

// Try to merge the tiles.
      if (slots[i][j] == slots[i][k]) {
        score += slots[i][j];
        slots[i][j] += slots[i][j];
        slots[i][k] = 0;
        j = k + 1;
        valid = true;
      } else {
        j = k;
      }
    }
  }

// Return whether a tile was merged or not.
  return valid;
}

bool GameTable::mergeRight() {
  std::lock_guard<std::mutex> lock(sLock);

  int i;
  int j;
  int k;
  bool valid = false;

// Merge items rightward.
  for (i = 0; i < gridX; i++) {
    j = gridX - 1;
    while (1) {
// Find potential tiles to merge.
      while (j >= 0 && !slots[i][j]) {
        j--;
      }
      k = j - 1;
      while (k >= 0 && !slots[i][k]) {
        k--;
      }
      if (k < 0) {
        break;
      }

// Try to merge the tiles.
      if (slots[i][j] == slots[i][k]) {
        score += slots[i][j];
        slots[i][k] += slots[i][k];
        slots[i][j] = 0;
        j = k - 1;
        valid = true;
      } else {
        j = k;
      }
    }
  }

// Return whether a tile was merged or not.
  return valid;
}

bool GameTable::shiftDown() {
  std::lock_guard<std::mutex> lock(sLock);

  int i;
  int j;
  unsigned k;
  bool valid = false;

// Shift tiles down the columns.
  for (i = 0; i < gridX; i++) {
// Find the last free tile in the column.
    k = gridY - 1;
    while (k > 0 && slots[k][i]) {
      k--;
    }

// Shift tiles down the column.
    for (j = k - 1; j >= 0; j--) {
      if (slots[j][i]) {
        slots[k--][i] = slots[j][i];
        slots[j][i] = 0;
        valid = true;
      }
    }
  }

// Return move status.
  return valid;
}

bool GameTable::shiftUp() {
  std::lock_guard<std::mutex> lock(sLock);

  int i;
  int j;
  int k;
  bool valid = false;

// Shift tiles up the columns.
  for (i = 0; i < gridY; i++) {
// Find first free tile in the column.
    k = 0;
    while (k < gridX && slots[k][i]) {
      k++;
    }

// Shift tiles up the column.
    for (j = k + 1; j < gridX; j++) {
      if (slots[j][i]) {
        slots[k++][i] = slots[j][i];
        slots[j][i] = 0;
        valid = true;
      }
    }
  }

// Return move status.
  return valid;
}

bool GameTable::shiftLeft() {
  std::lock_guard<std::mutex> lock(sLock);

  int i;
  int j;
  int k;
  bool valid = false;

// Shift tiles left across the rows.
  for (i = 0; i < gridX; i++) {
// Find the first free tile in the row.
    k = 0;
    while (k < gridY && slots[i][k]) {
      k++;
    }

// Shift tiles left across the row.
    for (j = k + 1; j < gridY; j++) {
      if (slots[i][j]) {
        slots[i][k++] = slots[i][j];
        slots[i][j] = 0;
        valid = true;
      }
    }
  }

// Return move status.
  return valid;
}

bool GameTable::shiftRight() {
  std::lock_guard<std::mutex> lock(sLock);

  int i;
  int j;
  unsigned k;
  bool valid = false;

// Shift tiles right across the rows.
  for (i = 0; i < gridX; i++) {
// Find the last free tile in the row.
    k = gridY - 1;
    while (k > 0 && slots[i][k]) {
      k--;
    }

// Shift tiles right across the row.
    for (j = k - 1; j >= 0; j--) {
      if (slots[i][j]) {
        slots[i][k--] = slots[i][j];
        slots[i][j] = 0;
        valid = true;
      }
    }
  }

// Return move status.
  return valid;
}

int GameTable::getScore() const {
  return score;
}

int GameTable::getFreePlaces() const {
  return freePlaces;
}

} /* namespace FadeCube */
