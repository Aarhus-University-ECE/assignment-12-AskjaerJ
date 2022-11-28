#include "duration.hpp"
#include "assert.h"
#include "iostream"

using std::cout;

int duration::getDuration(){
    return time; /* Returns time. */
}
duration::duration(){
    time = 0; /* 0 when alarm is not set. For both time and alarm. */
    alarm = 0;
    alarmHasBeenSet = false; /* Standard is false. */
}
duration::duration(int t){
    assert(t >= 0); /* Cannot be a negative time value. */
    time = t; /* Sets the time equal to input t. */
    alarm = 0;
    alarmHasBeenSet = false; /* Makes sure start alarm state is still false. */
}
bool duration::check_and_update_time() {
    if(time > alarm && alarmHasBeenSet){ /* Check to see if the alarm has gone off. */
        return true; 
        alarmHasBeenSet = false; /* Reset. */
    }
    else
        return false; 
}
bool duration::tick() {
    time++; /* Add one to time. */
    return check_and_update_time(); /* Return function. */
}
bool duration::tick(int dt) { /* Adds input to time. */
    assert(dt >= 0);
    time = time + dt;
    return check_and_update_time();
}
void duration::setAlarm(int t) {
    if(t > time) {
        alarmHasBeenSet = true; /* Sets the alarm if the input is greater than time. */
        alarm = t;
    }
    else {
        cout << "Time travel is not possible."; /* Cannot have negative time. */
        return;
    }
}