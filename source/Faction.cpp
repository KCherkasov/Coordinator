#include "Faction.h"

size_t Faction::_id = SIZE_T_DEFAULT_VALUE;

Faction::Faction(const FactionTemplate& data): _own_id(data._own_id), _name(data._name), _description(data._description), _influence(data._influence), _relationship(data._relationship) {
  if (_own_id == FREE_ID) {
    _own_id = ++_id;
  } else {
    if (_own_id > _id) {
      _id = _own_id;
    }
  }
}

size_t Faction::get_save_data(FactionTemplate& save_data) const {
  save_data._own_id = _own_id;
  save_data._name.clear();
  save_data._name = _name;
  save_data._description.clear();
  save_data._description = _description;
  save_data._influence = _influence;
  save_data._relationship = _relationship;
  return RC_OK;
}

size_t Faction::set_influence(const size_t& value) {
  _influence = value;
  return RC_OK;
}

size_t Faction::set_relationship(const size_t& value) {
  _relationship = value;
  return RC_OK;
}

size_t Faction::what(std::string& result) const {
  result.clear();
  return RC_OK;
}

size_t Faction::update() {
  return RC_OK;
}

size_t Faction::increase_influence(const size_t& amount) {
  _influence += amount;
  return RC_OK;
}

size_t Faction::increase_relationship(const size_t& amount) {
  _relationship += amount;
  return RC_OK;
}

size_t Faction::decrease_influence(const size_t& amount) {
  if (_influence >= amount) {
    _influence -= amount;
  } else {
    _influence = SIZE_T_DEFAULT_VALUE;
  }
  return RC_OK;
}

size_t Faction::decrease_relationship(const size_t& amount) {
  if (_relationship >= amount) {
    _relationship -= amount;
  } else {
    _relationship = SIZE_T_DEFAULT_VALUE;
  }
  return RC_OK;
}

size_t Faction::create_contract(Contract*& result) {
  if (result != NULL) {
    delete result;
  }
  ContractTemplate prototype;
  size_t prototype_id = roll_dice(/* contract templates database size here */);
  // some code here to receive template from the database (will be added when Storage class will be ready)
  result = new Contract(prototype, /* code to get Location class object here */);
  return RC_OK;
}
