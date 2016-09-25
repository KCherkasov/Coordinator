#ifndef ITEM_H
#define ITEM_H

#include "LevelableObject.h"
#include "StorageEntities.h"

class Item: public LevelableObject {
  public:
    Item(const ItemTemplate& table, const size_t& level = START_LEVEL, const size_t& owner_id = FREE_ID, const size_t& rarity = IR_COMMON);
    virtual ~Item() {}
    size_t get_owner_id() { return _owner_id; }
    size_t get_rarity() { return _rarity; }
    size_t get_kind() { return _kind; }
    size_t get_price() { return _price; }
    size_t get_bonuses(std::vector<size_t>& result);
    size_t get_bonuses(const size_t& index, size_t& result);
    size_t get_slots(std::vector<bool>& result);
    size_t get_slots(const size_t& index, bool& result);
    size_t set_owner_id(const size_t& value);
    size_t set_rarity(const size_t& value);
    size_t set_kind(const size_t& value);
    size_t set_price(const size_t& value);
    size_t set_bonuses(const std::vector<size_t>& value);
    size_t set_bonuses(const size_t& index, const size_t& value);
    size_t set_slots(const std::vector<bool>& value);
    size_t set_slots(const size_t& index, const bool& value);
    size_t what(std::string& result);
    size_t update();   

    Item& operator = (const Item& rhs) {
      _own_id = rhs._own_id;
      if (!_name.empty()) {
        _name.clear();
      }
      _name = rhs._name;
      if (!_description.empty()) {
        _description.clear();
      }
      _description = rhs._description;
      _level = rhs._level;
      _owner_id = rhs._owner_id;
      _rarity = rhs._rarity;
      _kind = rhs._kind;
      _price = rhs._price;
      if (!_bonuses.empty()) {
        _bonuses.clear();
      }
      _bonuses = rhs._bonuses;
      if (!_slots.empty()) {
        _slots.clear();
      }
      _slots = rhs._slots;
      return *this;
    }

  protected:
    size_t _owner_id;
    size_t _rarity;
    size_t _kind;
    size_t _price;
    std::vector<size_t> _bonuses;
    /std::vector<bool> _slots;
    
    static size_t _id;
};

#endif
