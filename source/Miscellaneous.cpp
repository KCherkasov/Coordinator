#include "Miscellaneous.h"

size_t roll_dice(const size_t& dice) {
  srand(static_cast<size_t>(time(0)));
  if (dice != SIZE_T_DEFAULT_VALUE) {
    return rand() % dice;
  } else {
    return dice;
  }
}

