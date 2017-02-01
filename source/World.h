#ifndef WORLD_H
#define WORLD_H

#include "WorldStorage.h"
#include "Player.h"

struct WorldTemplate {
  std::vector<ItemTemplate> _items;
  std::vector<HeroTemplate> _heroes;
  std::vector<QuestTemplate> _quests;
  PlayerTemplate _player;
  size_t _turn_number;
  
  friend bool operator == (const WorldTemplate& lhs, const WorldTemplate& rhs);
  friend bool operator < (const WorldTemplate& lhs, const WorldTemplate& rhs);
  friend bool operator > (const WorldTemplate& lhs, const WorldTemplate& rhs);
  
  WorldTemplate& operator = (const WorldTemplate& rhs) {
    _items.clear();
    _items = rhs._items;
    _heroes.clear();
    _heroes = rhs._heroes;
    _quests.clear();
    _quests = rhs._quests;
    _player = rhs._player;
    _turn_number = rhs._turn_number;
    return *this;
  };
};

class World {
  public:
    World();
    ~World();
    size_t new_game(const std::string& player_name, const std::string& player_description);
    size_t load_game(const WorldTemplate& save_data);
    
    size_t fill_storage(const std::string& texts_db_name, const std::string& templates_db_name, const std::string& type_objects_db_name);
    size_t clear_storage();
    
    size_t get_save_data(WorldTemplate& result) const;
    size_t update();
    
    size_t turn_number() const { return _turn_number; }
    
    size_t take_quest(const size_t& quest_id);
    size_t decline_quest(const size_t& quest_id);
    
    size_t assign_hero(const size_t& hero_own_id, const size_t& quest_own_id);
    size_t reject_hero(const size_t& hero_id, const size_t& quest_id);
    
    size_t hire_hero(const size_t& hero_id);
    size_t fire_hero(const size_t& hero_id);
    
  protected:
    size_t cleanup();
    size_t apply_reward(const size_t& index);
  
    WorldStorage* _storage;
    std::vector<Item*> _items;
    std::vector<Hero*> _heroes;
    std::vector<Quest*> _quests;
    Player* _player;
    size_t _turn_number;
    bool _storage_filled;
};

#endif