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

const size_t PAIR_ARR_SIZE = 2;

const size_t POINTS_PER_LEVEL = 10;
const size_t FIRST_LEVELUP_CAP = 100;
const size_t EXP_RAISE_PER_LEVEL = 110;
const size_t MONEY_RAISE_PER_LEVEL = 110;
const size_t STAT_POINTS_PER_LEVEL = 5;

const size_t START_LEVEL = 1;
const size_t START_CASH = 1000;

const size_t MAX_HEROES_PER_QUEST = 5;
const size_t MAX_ENEMIES_PER_QUEST = 10;

const size_t NAMES_PER_KIND = 5;

const size_t MAX_LOOT_ITEMS = 10;

const size_t START_HEROES_CAP = 50;

const size_t QUEST_LIFE_TIME = 108000; // quest lifetime assumed from 60 updates per second (108 000 = 30 minutes)
const size_t QUEST_LIFE_TIME_TURNS = 30; // quest lifetime for turn-based mode

const size_t ITEMS_PER_SLOT = 5;

const size_t MAX_FACTIONS_NUMBER = 6;

enum ResponseCodes { RC_OK, RC_EMPTY_STRING, RC_EMPTY_VECTOR, RC_BAD_INDEX, RC_BAD_SIZE, RC_BAD_INPUT, RC_NOT_FOUND, RC_NO_OBSERVERS, RC_ALREADY_BUSY, RC_ALREADY_HIRED, RC_GUILD_IS_FULL, RC_NO_STORAGE, RC_GAME_IN_PROCESS, RC_SIZE };

enum ItemRarity { IR_TRASH, IR_COMMON, IR_GOOD, IR_RARE, IR_EPIC, IR_LEGENDARY, IR_SIZE };
enum ItemKinds { IK_SWORD, IK_DAGGER, IK_AXE, IK_HAMMER, IK_BOW, IK_CROSSBOW, IK_SHIELD, IK_PLATE, IK_CHAIN, IK_LEATHER, IK_CLOTH, IK_NECK, IK_RING, IK_SIZE };

enum InventorySlots { IS_HEAD, IS_ARMOUR, IS_GLOVES, IS_BOOTS, IS_MAIN_HAND, IS_OFFHAND, IS_NECK, IS_RING1, IS_RING2, IS_SIZE };

enum StatIndices { SI_ENDURANCE, SI_STRENGTH, SI_AGILITY, SI_INTELLIGENCE, SI_SIZE };
enum RecruitmentStats { RS_GREED, RS_CAUTION, RS_INVENTIVE, RS_ACCURACY, RS_EDUCABILITY, RS_SIZE };
enum HeroHistory { HH_QUESTS_COMPLETED, HH_QUESTS_FAILED, HH_MONEY_EARNED, HH_ENEMIES_KILLED, HH_SIZE };
enum HeroAnswers { HA_OK, HA_TOO_BIG_RISK, HA_WANT_MORE_MONEY, HA_SIZE };

enum PlayerHistory { PH_MONEY_EARNED, PH_DAYS_PLAYED, PH_QUESTS_COMPLETED, PH_QUESTS_REFUSED, PH_QUESTS_FAILED, PH_SIZE };

enum CharacterHealth { CH_DEAD, CH_GRAVELY_WOUNDED, CH_WOUNDED, CH_LIGHT_WOUNDED, CH_HEALTHY, CH_STRONG, CH_MIGHTY, CH_GODLIKE, CH_SIZE };

enum ClassArchetypes { CA_WARRIOR, CA_WIZARD, CA_ROGUE, CA_RANGER, CA_SIZE };

enum RewardIndices { RI_MONEY, RI_EXPERIENCE, RI_SIZE };

enum QuestPhase { QP_PENDING, QP_RECRUITING, QP_IN_PROGRESS, QP_SUCCESS_TOTAL, QP_SUCCESS_REL_DMG, QP_FAILED, QP_EXPIRED, QP_SIZE };

enum LocationStats { LS_COVERS, LS_VISIBILITY, LS_SIZE };

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
