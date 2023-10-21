#ifndef PROJECTFUNC_H
#define PROJECTFUNC_H

#include "../Base/Project.h"

void inputProjectsInfo(std::vector<Project *>* projects);
void submitProject(std::vector<Project*>* projects);

Project* inputProjectInfo();

#endif