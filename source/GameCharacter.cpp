#include "GameCharacter.h"

size_t GameCharacter::get_stats(std::vector<size_t>& result) const {
  result.clear();
  result = _stats;
  return RC_OK;
}

size_t GameCharacter::get_stats(const size_t& index, size_t& result) const {
  if (index < _stats.size()) {
    result = _stats[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t GameCharacter::set_faction_id(const size_t& value) {
  _faction_id = value;
  return RC_OK;
}

size_t GameCharacter::set_stats(const std::vector<size_t>& value) {
  if (value.size() == SI_SIZE) {
    _stats.clear();
    _stats = value;
  } else {
    return RC_BAD_SIZE;
  }
}

size_t GameCharacter::set_stats(const size_t& index, const size_t& value) {
  if (index < _stats.size()) {
    _stats[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

