#ifndef PLAYER_H
#define PLAYER_H

#include "LevelableObject.h"

class Hero;

class Player: public LevelableObject {
  public:
    Player(const std::string& name, const std::string& description);
    Player(const PlayerTemplate& data, const std::vector<Hero*> heroes);
    virtual ~Player() {}
    size_t get_cash() const { return _cash; }
    size_t get_experience(std::vector<size_t>& result) const;
    size_t get_experience(const size_t& index, size_t& result) const;
    size_t get_history(std::vector<size_t>& result) const;
    size_t get_history(const size_t& index, size_t& result) const;
    size_t get_heroes(std::vector<Hero*>& result) const;
    size_t get_heroes(const size_t& index, Hero*& result) const;
    Hero* get_heroes(const size_t& index) const { if (index < _heroes.size()) { return _heroes[index]; } else { return NULL; } }
    size_t get_heroes_count() const { return _heroes.size(); }
    size_t get_save_data(PlayerTemplate& result) const;
    size_t what(std::string& result) const;
    size_t short_what(std::string& result) const;
    size_t set_cash(const size_t& value);
    size_t set_experience(const std::vector<size_t>& value);
    size_t set_experience(const size_t& index, const size_t& value);
    size_t set_history(const std::vector<size_t>& value);
    size_t set_history(const size_t& index, const size_t& value);
    size_t add_hero(Hero* to_add);
    size_t remove_hero(const size_t& index);
    size_t remove_hero(Hero* to_remove);
    size_t add_cash(const size_t& amount);
    size_t remove_cash(const size_t& amount);
    size_t add_experience(const size_t amount);
    size_t remove_experience(const size_t& amount);
    size_t add_history(const size_t& index, const size_t& amount = 1);
    size_t remove_history(const size_t& index, const size_t& amount = 1);
    
  protected:
    static size_t _id;
    size_t _cash;
    std::vector<size_t> _experience;
    std::vector<size_t> _history;
    std::vector<Hero*> _heroes;
    
    size_t level_up();
};

#endif