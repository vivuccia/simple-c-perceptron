#ifndef SETTINGS_H
#define SETTINGS_H

extern double target;
extern double learnRate;
extern int maxIterations;

void loadSettings(const char *settingsFile);

#endif
