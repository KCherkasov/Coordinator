#ifndef MERCENARY_H
#define MERCENARY_H

#include "GameCharacter.h"
#include "Inventory.h"
#include "MercSpec.h"

class Mercenary: public GameCharacter {
  public:
    Mercenary(const MercenaryTemplate& data, MercSpec& spec);
    virtual ~Mercenary() {}
    size_t get_spec(MercSpec& result) const;
    size_t get_experience(std::vector<size_t>& result) const;
    size_t get_experience(const size_t& index, size_t& result) const;
    size_t get_personality(std::vector<size_t>& result) const;
    size_t get_personality(const size_t& index, size_t& result) const;
    size_t get_history(std::vector<size_t>& result) const;
    size_t get_history(const size_t& index, size_t& result) const;
    size_t get_equipment(Inventory& result) const;
    size_t get_save_data(MercenaryTemplate& save_data) const;
    size_t set_spec(MercSpec& value);
    size_t set_experience(const std::vector<size_t>& value);
    size_t set_experience(const size_t& index, const size_t& value);
    size_t set_personality(const std::vector<size_t>& value);
    size_t set_personality(const size_t& index, const size_t& value);
    size_t set_history(const std::vector<size_t>& value);
    size_t set_history(const size_t& index, const size_t& value);
    size_t what(std::string& result) const;
    size_t update();
    size_t add_history(const size_t& index, const size_t& amount = 1);
    size_t add_experience(const size_t& amount);
  protected:
    static size_t _id;
    MercSpec& _spec;
    std::vector<size_t> _experience;
    std::vector<size_t> _personality;
    std::vector<size_t> _history;
    Inventory _equipment;
}

#endif
