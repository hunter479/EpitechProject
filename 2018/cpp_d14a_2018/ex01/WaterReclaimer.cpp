
#include <iostream>
#include "Errors.hpp"
#include "WaterReclaimer.hpp"

WaterReclaimer::WaterReclaimer() : _water(0), _started(false)
{
}

void WaterReclaimer::start()
{
    MissionCriticalError err("Not enough water to achieve the mission.", "WaterReclaimer");

    if (_water <= 0)
        throw err;
    _started = true;
}

void WaterReclaimer::useWater(int water)
{
    LifeCriticalError err1("Cannot use water, not enough in the reclaimer.", "WaterReclaimer");
    UserError err2("Water use should be positif.", "WaterReclaimer");
    UserError err3("Cannot use water if the reclaimer hasn't started.", "WaterReclaimer");

    if (_started == false)
        throw err3;
    if (water < 0)
        throw err2;
    if (_water - water < 10)
        throw err1;
    _water -= water;
}

void WaterReclaimer::generateWater()
{
    NasaError err("Cannot generate water, reclaimer already full.", "WaterReclaimer");

    if (_water > 90)
        throw err;
    _water += 10;
}
