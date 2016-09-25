#include "Miscellaneous.h"

size_t roll_dice(const size_t& dice) {
  srand(static_cast<size_t>(time(0)));
  if (dice != SIZE_T_DEFAULT_VALUE) {
    return rand() % dice;
  } else {
    return dice;
  }
}

template<class T>
size_t convert_to_string(const T& value, std::string& result) {
  std::ostringstream into(result);
  into << value;
  return RC_OK;
}

template<class T>
size_t convert_from_string(const std::string& from, T& result) {
  std::istringstream out(from);
  out >> result;
  return RC_OK;
}

