#ifndef CHARACTER_ARCHETYPE_H
#define CHARACTER_ARCHETYPE_H

#include <string>
#include <vector>

#include "Miscellaneous.h"
#include "StorageEntities.h"
#include "TextStorage.h"

class CharacterArchetype {
  public:
    CharacterArchetype(const CharacterArchetypeTemplate& table): _dictionary(NULL), _own_id(table._own_id), _name(table._name), _description(table._description), _power_mods(table._power_mods), _defense_mods(table._defense_mods) { if (_own_id == FREE_ID) { _own_id = ++_id; } else { if (_own_id > _id) { _id = _own_id; } } }
    ~CharacterArchetype() { _dictionary = NULL; }
    TextStorage* get_dictionary() const { return _dictionary; }
    size_t get_own_id() const { return _own_id; }
    size_t get_name(std::string& result) const;
    size_t get_description(std::string& result) const;
    size_t get_power_mods(std::vector<size_t>& result) const;
    size_t get_power_mods(const size_t& index, size_t& result) const;
    size_t get_defense_mods(std::vector<size_t>& result) const;
    size_t get_defense_mods(const size_t& index, size_t& result) const;
    size_t set_dictionary(TextStorage* value);
    size_t set_name(const std::string& value);
    size_t set_description(const std::string& value);
    size_t set_power_mods(const std::vector<size_t>& value);
    size_t set_power_mods(const size_t& index, const size_t& value);
    size_t set_defense_mods(const std::vector<size_t>& value);
    size_t set_defense_mods(const size_t& index, const size_t& value);
    size_t what(std::string& result) const;
    size_t short_what(std::string& result) const;

    CharacterArchetype& operator = (const CharacterArchetype& rhs) {
      _dictionary = rhs._dictionary;
      _own_id = rhs._own_id;
      _name.clear();
      _name = rhs._name;
      _description.clear();
      _description = rhs._description;
      _power_mods.clear();
      _power_mods = rhs._power_mods;
      return *this;
    }

  protected:
    TextStorage* _dictionary;
    static size_t _id;
    size_t _own_id;
    std::string _name;
    std::string _description;
    std::vector<size_t> _power_mods;
    std::vector<size_t> _defense_mods;
};

#endif
