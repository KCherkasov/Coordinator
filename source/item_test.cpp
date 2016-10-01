#include <ctime>
#include <cstdlib>

#include "Item.h"
#include "test_tools/test_tools.h"


const char* TEST_SMALL_SEPARATOR = "\n<< ---------------------------------------------------------------------- >>\n";
const char* TEST_BIG_SEPARATOR = "\n<< ====================================================================== >>\n";

size_t make_item_template(ItemTemplate& table) {
  Logger::write<const char*>("making item template table.");
  printf("making item template table.");
  table._own_id = roll_dice() + 1;
  Logger::write<const char*>(".");
  printf(".");
  std::string buffer;
  buffer.clear();
  buffer.append("Test item");
  table._name.clear();
  Logger::write<const char*>(".");
  printf(".");
  table._name = buffer;
  buffer.clear();
  buffer.append("Test item description");
  table._description.clear();
  table._description = buffer;
  Logger::write<const char*>(".");
  printf(".");
  buffer.clear();
  table._level = roll_dice() + START_LEVEL;
  Logger::write<const char*>(".");
  printf(".");
  table._owner_id = roll_dice();
  Logger::write<const char*>(".");
  printf(".");
  table._rarity = roll_dice(IR_SIZE);
  Logger::write<const char*>(".");
  printf(".");
  table._kind = roll_dice(IK_SIZE);
  Logger::write<const char*>(".");
  printf(".");
  table._price = roll_dice(PERCENT_CAP * 10);
  Logger::write<const char*>(".");
  printf(".");
  table._bonuses.clear();
  table._bonuses.resize(SI_SIZE);
  for (size_t i = 0; i < table._bonuses.size(); ++i) {
    table._bonuses[i] = roll_dice(PERCENT_CAP);
    Logger::write<const char*>(".");
    printf(".");
  }
  table._slots.clear();
  table._slots.resize(IS_SIZE);
  for (size_t i = 0; i < table._slots.size(); ++i) {
    table._slots[i] = roll_dice() % 2 == SIZE_T_DEFAULT_VALUE;
    Logger::write<const char*>(".");
    printf(".");
  }
  Logger::write<const char*>("done\n");
  printf("done.\n");
  return RC_OK;
}

size_t test(const size_t& rounds = PERCENT_CAP * 3) {
  size_t fails_count = SIZE_T_DEFAULT_VALUE;
  for (size_t i = 0; i < rounds; ++i) {
    printf(TEST_BIG_SEPARATOR);
    Logger::write<const char*>(TEST_BIG_SEPARATOR);
    printf("Item class test number %d:\n", i + 1);
    Logger::write<const char*>("Item class test number ");
    Logger::write<size_t>(i + 1);
    Logger::write<const char*>(":\n");
    Tester::reset();
    ItemTemplate table;
    make_item_template(table);
    Item* subject = new Item(table);
    size_t buffer;
    std::string str_buffer;
    std::vector<size_t> s_vector_buffer;
    std::vector<bool> b_vector_buffer;
    Logger::write<const char*>("#-- get_own_id(size_t&) method test: ");
    printf("#-- get_own_id(size_t&) method test: ");
    buffer = subject->get_own_id();
    Tester::test<size_t>(table._own_id, buffer);
    Logger::write<const char*>("#-- get_name(std::string&) method test: ");
    printf("#-- get_name(std::string&) method test: ");
    str_buffer.clear();
    subject->get_name(str_buffer);
    Tester::test<std::string>(table._name, str_buffer);
    str_buffer.clear();
    Logger::write<const char*>("#-- get_description(std::string&) method test: ");
    printf("#-- get_description(std::string&) method test: ");
    subject->get_description(str_buffer);
    Tester::test<std::string>(table._description, str_buffer);
    str_buffer.clear();
    Logger::write<const char*>("#-- get_level(size_t&) method test: ");
    printf("#-- get_level(size_t&) method test: ");
    buffer = subject->get_level();
    Tester::test<size_t>(table._level, buffer);
    Logger::write<const char*>("#-- get_owner_id(size_t&) method test: ");
    printf("#-- get_owner_id(size_t&) method test: ");
    buffer = subject->get_owner_id();
    Tester::test(table._owner_id, buffer);
    Logger::write<const char*>("#-- get_rarity(size_t&) method test: ");
    printf("#-- get_rarity(size_t&) method test: ");
    buffer = subject->get_rarity();
    Tester::test<size_t>(table._rarity, buffer);
    Logger::write<const char*>("#-- get_kind(size_t&) method test: ");
    printf("#-- get_kind(size_t&) method test: ");
    buffer = subject->get_kind();
    Tester::test<size_t>(table._kind, buffer);
    Logger::write<const char*>("#-- get_price(size_t&) method test: ");
    printf("#-- get_price(size_t&) method test: ");
    buffer = subject->get_price();
    Tester::test<size_t>(table._price, buffer);
    Logger::write<const char*>("#-- get_bonuses(std::vector<size_t>&) method test: ");
    printf("#-- get_bonuses(std::vector<size_t>&) method test: ");
    s_vector_buffer.clear();
    subject->get_bonuses(s_vector_buffer);
    Tester::test(table._bonuses, s_vector_buffer);
    s_vector_buffer.clear();
    Logger::write<const char*>("#-- get_bonuses(size_t&) method test:\n");
    printf("#-- get_bonuses(size_t&) method test:\n");
    for (size_t j = 0; j < table._bonuses.size(); ++j) {
      printf("#---- element number %d test: ", j);
      Logger::write<const char*>("#---- element number ");
      Logger::write<size_t>(j);
      Logger::write<const char*>(" test: ");    
      subject->get_bonuses(j, buffer);
      Tester::test<size_t>(table._bonuses[j], buffer);
    }
    bool b_buffer;
    Logger::write<const char*>("#-- get_slots(std::vector<bool>&) method test: ");
    printf("#-- get_slots(std::vector<bool>&) method test: ");
    b_vector_buffer.clear();
    subject->get_slots(b_vector_buffer);
    Tester::test<std::vector<bool> >(table._slots, b_vector_buffer);
    b_vector_buffer.clear();
    Logger::write<const char*>("#-- get_slots(bool&) method test: ");
    printf("#-- get_slots(bool&) method test:\n");
    for (size_t j = 0; j < table._slots.size(); ++j) {
      printf("#---- element number %d test: ", j);
      Logger::write<const char*>("#---- element number ");
      Logger::write<size_t>(j);
      Logger::write<const char*>(" test: ");    
      subject->get_slots(j, b_buffer);
      Tester::test<bool>(table._slots[j], b_buffer);
    }
    ItemTemplate save_table;
    Logger::write<const char*>("#-- get_save_data(ItemTemplate&) method test:\n");
    printf("#-- get_save_data(ItemTemplate&) method test:\n");
    subject->get_save_data(save_table);
    Logger::write<const char*>("#---- _own_id field test: ");
    printf("#---- _own id field test: ");
    Tester::test<size_t>(table._own_id, save_table._own_id);
    Logger::write<const char*>("#---- _name field test: ");
    printf("#---- _name field test: ");
    Tester::test<std::string>(table._name, save_table._name);
    Logger::write<const char*>("#---- _description field test: ");
    printf("#---- _description field test: ");
    Tester::test<std::string>(table._description, save_table._description);
    Logger::write<const char*>("#---- _level field test: ");
    printf("#---- _level field test: ");
    Tester::test<size_t>(table._level, save_table._level);
    Logger::write<const char*>("#---- _owner_id field test: ");
    printf("#---- _owner_id field test: ");
    Tester::test<size_t>(table._owner_id, save_table._owner_id);
    Logger::write<const char*>("#---- _rarity field test: ");
    printf("#---- _rarity field test: ");
    Tester::test<size_t>(table._rarity, save_table._rarity);
    Logger::write<const char*>("#---- _kind field test: ");
    printf("#---- _kind field test: ");
    Tester::test<size_t>(table._kind, save_table._kind);
    Logger::write<const char*>("#---- _price field test: ");
    printf("#---- _price field test: ");
    Tester::test<size_t>(table._price, save_table._price);
    Logger::write<const char*>("#---- _bonuses field test: ");
    printf("#---- _bonuses field test: ");
    Tester::test<std::vector<size_t> >(table._bonuses, save_table._bonuses);
    Logger::write<const char*>("#---- _slots field test: ");
    printf("#---- _slots field test: ");
    Tester::test<std::vector<bool> >(table._slots, save_table._slots);
    Tester::print_test_data();
    if (Tester::get_failed_count() > COUNTER_DEFAULT_VALUE) {
      ++fails_count;
    }
    delete subject;
    printf(TEST_BIG_SEPARATOR);
    Logger::write<const char*>(TEST_BIG_SEPARATOR);
  }
  size_t percentage;
  if (fails_count == COUNTER_DEFAULT_VALUE) {
    percentage = PERCENT_CAP;
  } else {
    percentage = PERCENT_CAP - PERCENT_CAP * rounds / fails_count;
  }
  printf("\ntests made: %d, successful: %d, failed: %d, success percentage: %d%%.\n", rounds, rounds - fails_count, fails_count, percentage);
  if (Logger::is_open()) {
    Logger::write<const char*>("\ntests made: ");
    Logger::write<size_t>(rounds);
    Logger::write<const char*>(", successful: ");
    Logger::write<size_t>(rounds - fails_count);
    Logger::write<const char*>(", failed: ");
    Logger::write<size_t>(fails_count);
    Logger::write<const char*>(", success percentage: ");
    Logger::write<size_t>(percentage);
    Logger::write<const char*>("%.\n");
  }
  return RC_OK;
}

ssize_t main() {
  Logger::open_log("item_class_test");
  test(PERCENT_CAP * 3 + roll_dice(PERCENT_CAP));
  Logger::close_log();
  return RC_OK;
}
