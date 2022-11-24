
class duration
{
private:
    /* data */
    int time;
    int alarm;
    bool alarmHasBeenSet;
    bool check_and_update_time();
public:
    int getDuration();
    duration();
    bool tick();
    bool tick(int dt);
    void setAlarm(int t);

    duration(int t);
};


