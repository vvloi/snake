#ifndef STATS_H
#define STATS_H

#include "types.h"
#include <windows.h>

#define TOP_BORDER_OFFSET 2

void display_stats(void);
void set_default_stats(Stats *, int);

int get_hiscore(void);
void save_hiscore(Stats *);

void update_hiscore(Stats *);
void update_lives(Stats *, int);
void update_score(Stats *, Eats *);

void display_modifier(Eats *);
void hide_modifier(void);
void wait_for_key_press(HANDLE);

#endif /* STATS_H */