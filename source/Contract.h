#ifndef CONTRACT_H
#define CONTRACT_H

#include "LevelableObject.h"
#include "Location.h"
#include "Enemy.h"

class Mercenary;

class Contract: public LevelableObject {
  public:
    Contract(const ContractTemplate& data, Location& location);
    virtual ~Contract();
    size_t get_location(Location& result);
    size_t get_employer_faction() const { return _employer_faction; }
    size_t get_target_faction() const { return _target_faction; }
    size_t get_phase() const { return _phase; }
    size_t get_rewards(std::vector<size_t>& result) const;
    size_t get_rewards(const size_t& index size_t& result) const;
    size_t get_bonuses(std::vector<size_t>& result) const;
    size_t get_bonuses(const size_t& index, size_t& result);
    size_t get_mercs(std::vector<Mercenary*>& result) const;
    size_t get_mercs(const size_t& index, Mercenary*& result) const;
    size_t get_enemies(std::vector<Enemy*>& result) const;
    size_t get_enemies(const size_t& index, Enemy*& result) const;
    size_t get_save_data(ContractTemplate& save_data) const;
    size_t set_location(Location& value);
    size_t set_employer_faction(const size_t& value);
    size_t set_target_faction(const size_t& value);
    size_t set_rewards(const std::vector<size_t>& value);
    size_t set_rewards(const size_t& index, const size_t& value);
    size_t set_bonuses(const std::vector<size_t>& value);
    size_t set_bonuses(const size_t& index, const size_t& value);
    size_t set_mercs(const std::vector<Mercenary*>& value);
    size_t set_mercs(const size_t& const Mercenary*& value);
    size_t set_enemies(const std::vector<Enemy*>& value);
    size_t set_enemies(const size_t& index, const Enemy*& value);
    size_t what(std::string& result);
    size_t update();
    size_t increase_phase(const size_t& shift = 1);
    size_t decrease_phase(const size_t& shift = 1);
    size_t add_merc(const Mercenary*& new_merc);
    size_t remove_merc(const size_t& index);
    size_t remove_merc(Mercenary* to_delete);
    size_t add_enemy(const Enemy*& new_enemy);
    size_t remove_enemy(const size_t& index);
    size_t remove_enemy(Enemy* to_delete);
  protected:
    Location& _location;
    static size_t _id;
    size_t _employer_faction;
    size_t _target_faction;
    size_t _phase;
    size_t _life_time;
    size_t _birth_time;
    std::vector<size_t> _rewards;
    std::vector<size_t> _bonuses;
    std::vector<Mercenary*> _mercs;
    std::vector<Enemy*> _enemies;
};

#endif
