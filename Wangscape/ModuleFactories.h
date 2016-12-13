#pragma once
#include "ModuleGroup.h"
#include "CornerCombinerBase.h"

// Makes a ModuleGroup with values 1-|x| or 1-|y|.
ModulePtr makePeak(bool x);

//ModuleGroup::ModulePtr makeQuadrantSelector(bool x,  bool y)

// Makes a CornerCombiner scaled and clamped to the interval [0., 1.].
ModulePtr makeCornerCombiner(bool x_positive, bool y_positive, double power = 2.);

// Makes a NormLPQ clamped to the interval [0., 1.].
ModulePtr makeEdgeFavouringMask(double p, double q=1., double min=0.);