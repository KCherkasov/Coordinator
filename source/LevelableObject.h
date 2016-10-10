#ifndef LEVELABLE_OBJECT_H
#define LEVELABLE_OBJECT_H

#include<string>
#include<vector>

#include "GameObject.h"

class LevelableObject: public GameObject {
  public:
    LevelableObject(const size_t& own_id = SIZE_T_DEFAULT_VALUE, const size_t& level = START_LEVEL);
    virtual ~LevelableObject() {}
    size_t get_level() const { return _level; }
    size_t set_level(const size_t& value);
  protected:
    size_t _level;
};

#endif
