#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <algorithm>
#include "DrugData.h"
using namespace std;

vector<DrugData> csvToDrugData(string filename);
