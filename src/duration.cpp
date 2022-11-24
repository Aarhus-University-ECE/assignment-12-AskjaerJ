#include "duration.hpp"
#include "assert.h"
#include "iostream"

using std::cout;

int duration::getDuration(){
    return time;
}
duration::duration(){
    time = 0;
    alarm = 0;
    alarmHasBeenSet = false;
}
duration::duration(int t){
    assert(t >= 0);
    time = t;
    alarm = 0;
    alarmHasBeenSet = false;
}
bool duration::check_and_update_time() {
    if(time > alarm && alarmHasBeenSet){
        return true;
        alarmHasBeenSet = false;
    }
    else
        return false;
}
bool duration::tick() {
    time++;
    return check_and_update_time();
}
bool duration::tick(int dt) {
    assert(dt >= 0);
    time = time + dt;
    return check_and_update_time();
}
void duration::setAlarm(int t) {
    if(t > time) {
        alarmHasBeenSet = true;
        alarm = t;
    }
    else {
        cout << "Time travel is not possible.";
        return;
    }
}