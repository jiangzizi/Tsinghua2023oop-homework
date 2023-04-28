#pragma once

#include "abstract_compare.h"
#include "point.h"

AbstractCompare<int>* get_compare_int(int type);
AbstractCompare<Point>* get_compare_point(int type);