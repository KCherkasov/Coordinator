#include "Contract.h"

size_t Contract::_id = SIZE_T_DEFAULT_VALUE;

Contract::Contract(ContractTemplate& data, Location& location): _own_id(data._own_id), _name(data._name), _description(data._description), _level(data._level), _employer_faction(data._employer_faction), _target_faction(data._target_faction), _phase(data._phase), _life_time(data._life_time), _birth_time(data._birth_time), _rewards(data._rewards), _bonuses(data._bonuses) {
  if (_own_id == FREE_ID) {
    _own_id = ++_id;
  } else {
    if (_own_id > _id) {
      _id = _own_id;
    }
  }
  for (size_t i = 0; i < data._mercs.size(); ++i) {
    Mercenary* new_merc = new Mercenary(data._mercs[i], /* some code here to receive merc spec by spec_id */);
    _merc.push_back(new_merc);
    new_merc = NULL;
  }
  for (size_t i = 0; i < data._enemies.size(); ++i) {
    Enemy* new_enemy = new Enemy(data._enemies[i]);
    _enemies.push_back(new_enemy);
    new_enemy = NULL;
  }
}

Contract::~Contract() {
  for (size_t i = 0; i < _mercs.size(); ++i) {
    if (_mercs[i] != NULL) {
      delete _mercs[i];
    }
  }
  for (size_t i = 0; i < _enemies.size(); ++i) {
    if (_enemies[i] != NULL) {
      delete _enemies[i];
    }
  }
}


