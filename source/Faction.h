#ifndef FACTION_H
#define FACTION_H

#include "GameObject.h"

class Faction: public GameObject {
  public:
    Faction(const FactionTemplate& data);
    virtual ~Faction() {}
    size_t get_influence() const { return _influence; }
    size_t get_relationship() const { return _relationship; }
    size_t get_save_data(FactionTemplate& save_data) const;
    size_t set_influence(const size_t& value);
    size_t set_relationship(const size_t& value);
    size_t what(std::string& result) const;
    size_t update();
    size_t increase_influence(const size_t& amount);
    size_t increase_relationship(const size_t& amount);
    size_t decrease_influence(const size_t& amount);
    size_t decrease_relationship(const size_t& amount);
  protected:
    static size_t _id;
    size_t _influence;
    size_t _relationship;
};

#endif
