#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;

extern int totalLinesOfCode;
void totalLines(string pathOfFile);
void totalLineInPython(string pathOfFile);
void totalLineInHTML(string pathOfFile);
void listDir(string pathOfFile);
