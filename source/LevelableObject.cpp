#include "LevelableObject.h"

LevelableObject::LevelableObject(const size_t& own_id, const size_t& level): GameObject(own_id) {
  if (level >= START_LEVEL) {
    _level = level;
  } else {
    _level = START_LEVEL;
  }
}

size_t LevelableObject::set_level(const size_t& value) {
  if (value >= START_LEVEL) {
    _level = value;
    return RC_OK;
  } else {
    return RC_BAD_INPUT;
  }
}

