#ifndef WORLD_H
#define WORLD_H

#include "WorldStorage.h"
#include "Player.h"

struct WorldTemplate {
  std::vector<HeroTemplate> _heroes;
  std::vector<QuestTemplate> _quests;
  PlayerTemplate _player;
  size_t _turn_number;
  
  friend bool operator == (const WorldTemplate& lhs, const WorldTemplate& rhs);
  friend bool operator < (const WorldTemplate& lhs, const WorldTemplate& rhs);
  friend bool operator > (const WorldTemplate& lhs, const WorldTemplate& rhs);
  
  WorldTemplate& operator = (const WorldTemplate& rhs) {
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
    size_t new_game(const std::string& player_name);
    size_t load_game(const WorldTemplate& save_data);
    
    size_t fill_storage(const std::string& texts_db_name, const std::string& templates_db_name, const std::string& type_objects_db_name);
    size_t clear_storage();
    
    size_t update();
    
  protected:
    size_t cleanup();
  
    WorldStorage* _storage;
    std::vector<Hero*> _heroes;
    std::vector<Quest*> _quests;
    Player* _player;
    size_t _turn_number;
    bool _storage_filled;
};

#endif