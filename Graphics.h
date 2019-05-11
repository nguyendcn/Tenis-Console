#pragma once

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <Windows.h>
#include <vector>

#include <ctime>

using namespace std;

#define WidthConsole            700
#define HeightConsole           500
#define WidthGame               50
#define HeightGame              25
#define MaxBarPlayer            5


void gotoxy(int x, int y);
void resizeConsole(int width, int height);
void AnConTro();
