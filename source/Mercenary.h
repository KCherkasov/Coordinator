#ifndef MERCENARY_H
#define MERCENARY_H

#include "GameCharacter.h"
#include "Inventory.h"
#include "MercSpec.h"

class Mercenary: public GameCharacter {
  public:
    Mercenary(const MercenaryTemplate& data, MercSpec& spec);
    virtual ~Mercenary() {}
    size_t get_spec(MercSpec& value);
    size_t get_experience(std::vector<size_t>& result);
    size_t get_experience(const size_t& index, size_t& result);
    size_t get_personality(std::vector<size_t>& result);
    size_t get_personality(const size_t& index, size_t& result);
    size_t get_equipment(Inventory& result);
    size_t get_save_data(MercenaryTemplate& save_data);
    size_t set_spec(MercSpec& value);
    size_t set_experience(const std::vector<size_t>& value);
    size_t set_experience(const size_t& index, const size_t& value);
    size_t set_personality(const std::vector<size_t>& value);
    size_t set_personality(const size_t& index, const size_t& value);
    size_t what(std::string& result);
    size_t update();
  protected:
    MercSpec& _spec;
    std::vector<size_t> _experience;
    std::vector<size_t> _personality;
    Inventory _equipment;
    static size_t _id;
}

#endif
