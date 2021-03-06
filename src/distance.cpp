/*
 * distance.cpp
 *
 * Copyright 2018 Onalenna Junior Makhura
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifdef __cplusplus
#include "hdbscan/distance.h"
#include <stdlib.h>
namespace clustering {

Distance::Distance(){
	distance_init(this, _EUCLIDEAN, DATATYPE_DOUBLE);
}

Distance::Distance(calculator cal){
	distance_init(this, cal, DATATYPE_DOUBLE);
}

Distance::Distance(calculator cal, int32_t type){
	distance_init(this, cal, type);
}

Distance::~Distance(){
	distance_clean(this);
}

void Distance::getCoreDistances(int32_t numNeighbors){
	this->numNeighbors = numNeighbors;
	distance_get_core_distances(this);
}

void Distance::computeDistance(distance* dis, void* dataset, int rows, int cols, int numNeighbors)
{
	distance_compute(this, dataset, rows, cols, numNeighbors);
}
};
#endif

