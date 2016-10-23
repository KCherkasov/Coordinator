#ifndef HERO_CLASS_H
#define HERO_CLASS_H

#include <string>
#include <vector>

#include "Miscellaneous.h"
#include "StorageEntities.h"
#include "Storage.h"

class HeroClass {
  public:
    HeroClass(const HeroClassTemplate& table): _own_id(table._own_id) _name(table._name), _description(table._description), _base_merc_stats(table._base_merc_stats) { if (_own_id == FREE_INDEX) { _own_id = ++_id; } else { if (_own_id > _id) { _id = _own_id; } } }
    ~HeroClass() {}
    size_t get_own_id() { return _own_id; }
    size_t get_name(std::string& result) const;
    size_t get_description(std::string& result) const;
    size_t get_power_mods(std::vector<size_t>& result) const;
    size_t get_power_mods(const size_t& index, size_t& result) const;
    size_t set_name(const std::string& value);
    size_t set_description(const std::string& value);
    size_t set_power_mods(const std::vector<size_t>& value);
    size_t set_power_mods(const size_t& index, const size_t& value);
    size_t what(std::string& result) const;

    HeroClass& operator = (const HeroClass& rhs) {
      _own_id = rhs._own_id;
      if (!_name.empty()) {
        _name.clear();
      }
      _name = rhs._name;
      if (!_description.empty()) {
        _description.clear();
      }
      if (!_base_merc_stats.empty()) {
        _base_merc_stats.clear();
      }
      _base_merc_stats = rhs._base_merc_stats;
      return *this;
    }

  protected:
    static size_t _id;
    size_t _own_id;
    std::string _name;
    std::string _description;
    std::vector<size_t> _power_mods;
};

#endif
