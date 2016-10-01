#ifndef MISCELLANEOUS_H
#define MISCELLANEOUS_H

#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <sstream>

const size_t SIZE_T_DEFAULT_VALUE = 0;
const ssize_t SSIZE_T_DEFAULT_VALUE = -1;
const bool BOOL_DEFAULT_VALUE = false;

const bool MALE_GENDER = true;
const bool FEMALE_GENDER = false;

const size_t FREE_ID = 0;

const size_t PERCENT_CAP = 100;

const size_t POINTS_PER_LEVEL = 10;
const size_t FIRST_LEVELUP_CAP = 100;
const size_t EXP_RAISE_PER_LEVEL = 110;

const size_t START_LEVEL = 1;

enum ResponseCodes { RC_OK, RC_EMPTY_STRING, RC_BAD_INDEX, RC_BAD_SIZE, RC_BAD_INPUT, RC_NOT_FOUND, RC_NO_OBSERVERS, RC_SIZE };

enum ItemRarity { IR_TRASH, IR_COMMON, IR_GOOD, IR_RARE, IR_EPIC, IR_LEGENDARY, IR_SIZE };
enum ItemKinds { IK_CQB, IK_MELEE, IK_RANGED, IK_HEAVY, IK_EXPLOSIVES, IK_GEAR, IK_SIZE };

enum InventorySlots { IS_HEAD, IS_ARMOUR, IS_GLOVES, IS_BOOTS, IS_PRIMARY_WEAPON, IS_SECONDARY_WEAPON, IS_SIZE };

enum StatIndices { SI_POWER, SI_MELEE, SI_STEALTH, SI_RANGE, SI_AGILITY, SI_ENDURANCE, SI_SIZE };
enum RecruitmentStats { RS_GREED, RS_CAUTION, RS_INVENTIVE, RS_ACCURACY, RS_EDUCABILITY, RS_SIZE };
enum MercHistory { MH_TASKS_COMPLETED, MH_TASKS_FAILED, MH_CASH_EARNED, MH_ENEMIES_KILLED, MH_SIZE };
enum MercAnswer { MA_OK, MA_TOO_BIG_RISK, MA_WANT_MORE_MONEY, MA_SIZE };

size_t roll_dice(const size_t& dice = PERCENT_CAP);

template<class T>
size_t convert_to_string(const T& value, std::string& result) {
  std::ostringstream into(result);
  into << value;
  return RC_OK;
}

template<class T>
size_t convert_from_string(const std::string& from, T& result) {
  std::istringstream out(from);
  out >> result;
  return RC_OK;
}


#endif
