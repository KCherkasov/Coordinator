#ifndef QUEST_H
#define QUEST_H

#include "LevelableObject.h"
#include "Location.h"
#include "Faction.h"
#include "Enemy.h"

class Hero;

struct QuestReward {
  size_t _level;
  size_t _cash;
  size_t _fees;
  size_t _experience;
  std::vector<size_t> _loot;
};

class Quest: public LevelableObject {
  public:
    Quest(const QuestTemplate& data, Location& location, Faction& employer, Faction& target);
    virtual ~Quest();
    size_t get_location(Location& result);
    size_t get_employer_faction() const { return _employer_faction; }
    size_t get_target_faction() const { return _target_faction; }
    size_t get_phase() const { return _phase; }
    size_t get_damage() const { return _damage; }
    size_t get_rewards(std::vector<size_t>& result) const;
    size_t get_rewards(const size_t& index size_t& result) const;
    size_t get_bonuses(std::vector<size_t>& result) const;
    size_t get_bonuses(const size_t& index, size_t& result);
    size_t get_heroes(std::vector<Hero*>& result) const;
    size_t get_heroes(const size_t& index, Hero*& result) const;
    size_t get_party_size() const { return _heroes.size(); }
    size_t get_enemies(std::vector<Enemy*>& result) const;
    size_t get_enemies(const size_t& index, Enemy*& result) const;
    size_t get_enemies_count() const { return _enemies.size(); }
    size_t get_save_data(QuestTemplate& save_data) const;
    size_t set_location(Location& value);
    size_t set_employer_faction(const size_t& value);
    size_t set_target_faction(const size_t& value);
    size_t set_rewards(const std::vector<size_t>& value);
    size_t set_rewards(const size_t& index, const size_t& value);
    size_t set_bonuses(const std::vector<size_t>& value);
    size_t set_bonuses(const size_t& index, const size_t& value);
    size_t set_heroes(const std::vector<Hero*>& value);
    size_t set_heroes(const size_t& const Hero*& value);
    size_t set_enemies(const std::vector<Enemy*>& value);
    size_t set_enemies(const size_t& index, const Enemy*& value);
    size_t what(std::string& result) const;
    size_t short_what(std::string& result) const;
    size_t update();
    size_t increase_phase(const size_t& shift = 1);
    size_t decrease_phase(const size_t& shift = 1);
    size_t add_hero(const Hero*& new_hero);
    size_t remove_hero(const size_t& index);
    size_t remove_hero(Hero* to_delete);
    size_t add_enemy(const Enemy*& new_enemy);
    size_t remove_enemy(const size_t& index);
    size_t remove_enemy(Enemy* to_delete);
    size_t give_reward(QuestReward&  reward, const bool& with_rep_dmg);
  protected:
    
    size_t add_loot(const size_t& loot_id) { _loot.push_back(loot_id); return RC_OK; }
    size_t remove_loot(const size_t& index);
    size_t clear_loot() { _loot.clear(); return RC_OK; }
    size_t count_fees();
    
    Location& _location;
    static size_t _id;
    Faction& _employer_faction;
    Faction& _target_faction;
    size_t _phase;
    size_t _life_time;
    size_t _damage;
    std::vector<size_t> _rewards;
    std::vector<size_t> _bonuses;
    std::vector<Hero*> _heroes;
    std::vector<Enemy*> _enemies;
    std::vector<size_t> _loot;
};

#endif

// 09.01.2016
// TO-DO - write a QuestReward class/struct that will be passed outside the quest 
// when it's completed and will contain all the data needed to transfer the cash,
// count the fees and generate looted items