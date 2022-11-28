
class duration
{
private: /* Private variables in class duration */
    /* data */
    int time;
    int alarm;
    bool alarmHasBeenSet;
    bool check_and_update_time();
public: /* Public variables in class duration */
    int getDuration();
    duration();
    bool tick();
    bool tick(int dt);
    void setAlarm(int t);

    duration(int t);
};


