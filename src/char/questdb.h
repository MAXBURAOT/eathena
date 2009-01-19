// Copyright (c) Athena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#ifndef _QUESTDB_H_
#define _QUESTDB_H_

#include "../common/mmo.h" // struct quest, MAX_QUEST

typedef struct QuestDB QuestDB;
typedef struct quest questlog[MAX_QUEST];


struct QuestDB
{
	bool (*init)(QuestDB* self);
	void (*destroy)(QuestDB* self);

	bool (*sync)(QuestDB* self);

	bool (*remove)(QuestDB* self, const int char_id);

	bool (*add)(QuestDB* self, const struct quest* qd, const int char_id);
	bool (*del)(QuestDB* self, const int char_id, const int quest_id);
	bool (*load)(QuestDB* self, questlog* log, int char_id, int* const count);
};


#endif /* _QUESTDB_H_ */
