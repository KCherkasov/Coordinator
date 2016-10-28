#ifndef HERO_CLASS_H
#define HERO_CLASS_H

#include <string>
#include <vector>

#include "CharacterArchetype.h"

class HeroClass {
  public:
    HeroClass(const HeroClassTemplate& table, const CharacterArchetype& archetype): _own_id(table._own_id), _archetype(archetype), _name(table._name), _description(table._description), _stat_bonuses(table._stat_bonuses), _att_power_modifiers(table._att_power_modifiers), _defense_modifiers(table._defense_modifiers) { if (_own_id == FREE_INDEX) { _own_id = ++_id; } else { if (_own_id > _id) { _id = _own_id; } } }
    ~HeroClass() {}
    size_t get_own_id() { return _own_id; }
    size_t get_name(std::string& result) const;
    size_t get_description(std::string& result) const;
    size_t get_power_mods(std::vector<size_t>& result) const;
    size_t get_power_mods(const size_t& index, size_t& result) const;
    size_t get_defense_mods(std::vector<size_t>& result) const;
    size_t get_defense_mods(const size_t& index, size_t& result) const;
    size_t get_stat_bonuses(std::vector<size_t>& result) const;
    size_t get_stat_bonuses(const size_t& index, size_t& result) const;
    size_t get_att_power_modifers(std::vector<size_t>& result) const;
    size_t get_att_power_modifiers(const size_t& index, size_t& result) const;
    size_t get_defense_modifiers(std::vector<size_t>& result) const;
    size_t get_defense_modifiers(const size_t& index, size_t& result) const;
    size_t set_name(const std::string& value);
    size_t set_description(const std::string& value);
    size_t set_stat_bonuses(const std::vector<size_t>& value);
    size_t set_stat_bonuses(const size_t& index, const size_t& value);
    size_t set_att_power_modifers(const std::vector<size_t>& value);
    size_t set_att_power_modifiers(const size_t& index, const size_t& value);
    size_t set_defense_modifiers(const std::vector<size_t>& value);
    size_t set_defense_modifiers(const size_t& index, const size_t& value);
    size_t what(std::string& result) const;
    size_t short_what(std::string& result) const;

    HeroClass& operator = (const HeroClass& rhs) {
      _archetype = rhs._archetype;
      _own_id = rhs._own_id;
      if (!_name.empty()) {
        _name.clear();
      }
      _name = rhs._name;
      if (!_description.empty()) {
        _description.clear();
      }
      if (!_stat_bonuses.empty()) {
        _stat_bonuses.clear();
      }
      _stat_bonuses = rhs._stat_bonuses;
      if (!_att_power_modifiers.empty() {
        _att_power_modifiers.clear();
      }
      _att_power_modifiers = rhs._att_power_modifiers;
      if (!_defense_modifiers.empty() {
        _defense_modifiers.clear();
      }
      _defense_modifiers = rhs._defense_modifiers;
      return *this;
    }

  protected:
    static size_t _id;
    CharacterArchetype& _archetype;
    size_t _own_id;
    std::string _name;
    std::string _description;
    std::vector<size_t> _stat_bonuses;
    std::vector<size_t> _att_power_modifiers;
    std::vector<size_t> _defense_modifiers;
};

#endif
