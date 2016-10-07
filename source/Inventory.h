#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"

class Inventory {
  public:
    Inventory() {}
    Inventory(InventoryTemplate& table);
    virtual ~Inventory();
    size_t get_equipment(std::vector<Item*>& result);
    size_t get_equipment(const size_t& index, Item*& result);
    size_t get_bonuses(std::vector<size_t>& result);
    size_t get_bonuses(const size_t& index, size_t& result);
    size_t set_equipment(const std::vector<Item*>& value);
    size_t set_equipment(const size_t& index, Item*& value, bool if_swap = true);
    size_t get_save_data(InventoryTemplate& result);
    size_t what(std::string& result);
  protected:
    std::vector<Item*> _equipment;
};

#endif
