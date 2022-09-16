#include "Controller.h"

Joy Controller::joys[2] = {Joy(&Controller1.Axis4, &Controller1.Axis3),
                           Joy(&Controller1.Axis1, &Controller1.Axis2)};

Pad Controller::pads[2] = {Pad(&Controller1.ButtonUp, &Controller1.ButtonDown,
                               &Controller1.ButtonLeft,
                               &Controller1.ButtonRight),
                           Pad(&Controller1.ButtonX, &Controller1.ButtonB,
                               &Controller1.ButtonY, &Controller1.ButtonA)};
Trig Controller::trigs[2] = {
    Trig(&Controller1.ButtonL1, &Controller1.ButtonL2),
    Trig(&Controller1.ButtonR1, &Controller1.ButtonR2)};