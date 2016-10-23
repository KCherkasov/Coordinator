#ifndef HERO_H
#define HERO_H

#include "GameCharacter.h"
#include "Inventory.h"
#include "HeroClass.h"

class Quest;

class Hero: public GameCharacter {
  public:
    Hero(const HeroTemplate& data, MercSpec& spec);
    virtual ~Hero();
    size_t get_class(HeroClass& result) const;
    size_t get_experience(std::vector<size_t>& result) const;
    size_t get_experience(const size_t& index, size_t& result) const;
    size_t get_personality(std::vector<size_t>& result) const;
    size_t get_personality(const size_t& index, size_t& result) const;
    size_t get_history(std::vector<size_t>& result) const;
    size_t get_history(const size_t& index, size_t& result) const;
    size_t get_equipment(Inventory& result) const;
    size_t get_save_data(MercenaryTemplate& save_data) const;
    size_t set_class(HeroClass& value);
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
    size_t add_quest(Quest* to_add);
    size_t remove_quest(const size_t& index);
    size_t remove_quest(Quest* to_remove);
  protected:
    static size_t _id;
    size_t level_up();
    HeroClass& _class;
    std::vector<size_t> _experience;
    std::vector<size_t> _personality;
    std::vector<size_t> _history;
    std::vector<Contract*> _contracts;
    Inventory _equipment;
}

#endif
