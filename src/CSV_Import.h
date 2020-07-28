#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>
#include "DrugData.h"
#include "DrugData.cpp"
using namespace std;

vector<DrugData> csvToDrugData(string filename);