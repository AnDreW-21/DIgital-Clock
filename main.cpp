#include <iostream>
using namespace std;
void DigitalClockIntToStr(int seconds, char time[11]) {
    if (seconds >= 86400 || seconds < 0) {
        string s = "Invalid";
        for (int i = 0; i < 11; i++) time[i] = s[i];
    } else {
        int hour = 0, min = 0, sec = 0, HourTemp;
        char h1, h2, m1, m2, s1, s2;
        char t[11] = {'1', '2', ':', '0', '0', ':', '0', '0', 'a', 'm'};
        hour = seconds / 3600;
        seconds = seconds % 3600;
        min = seconds / 60;
        seconds = seconds % 60;
        sec = seconds;
        HourTemp = hour;
        s1 = '0' + sec % 10;
        sec /= 10;
        s2 = '0' + sec;
        m1 = min % 10 + '0';
        min /= 10;
        m2 = min + '0';
        h1 = hour % 10 + '0';
        hour /= 10;
        h2 = hour + '0';
        t[7] = s1;
        t[6] = s2;
        t[4] = m1;
        t[3] = m2;
        if (HourTemp < 10 && HourTemp > 0) {
            t[0] = '0';
            t[1] = h1;
        } else if (HourTemp >= 10 && HourTemp < 12) {
            t[0] = h2;
            t[1] = h1;
        } else if (HourTemp >= 12) {
            t[8] = 'p';
            if (HourTemp > 12) {
                HourTemp -= 12;
                h1 = HourTemp % 10 + '0';
                HourTemp /= 10;
                h2 = HourTemp + '0';
                t[0] = h2;
                t[1] = h1;
            }
        }
        for (int i = 0; i < 10; i++) time[i] = t[i];
    }
}
int DigitalClockStrToInt(const char time[11]) {
    char t[11];
    for (int i = 0; i < 10; i++) t[i] = time[i];
    int h1 = 0, h2 = 0, m1 = 0, m2 = 0, s1 = 0, s2 = 0, sec = 0, min = 0, hour = 0,
            seconds = 0;
    s2 = t[7] - '0';
    s1 = t[6] - '0';
    sec = s2 + s1 * 10;
    m2 = t[4] - '0';
    m1 = t[3] - '0';
    min = m1 * 10 + m2;
    min *= 60;
    if (t[8] == 'a') {
        if (t[0] == '1' && t[1] == '2') {
            h1 = 0;
            h2 = 0;
        } else {
            h2 = t[1] - '0';
            h1 = t[0] - '0';
            hour = h2 + h1 * 10;
            hour *= 3600;
        }
    } else if (t[8] == 'p') {
        h2 = t[1] - '0';
        h1 = t[0] - '0';
        if (t[0] == '1' && t[1] == '2') {
            hour = h2 + h1 * 10;
            hour *= 3600;
        } else {
            hour = h2 + h1 * 10 + 12;
            hour *= 3600;
        }
    }
    seconds = hour + min + sec;
    return seconds;
}
int main() {
    char time[11];
    DigitalClockIntToStr (0, time);
    cout << time << endl;
    DigitalClockIntToStr (1, time);
    cout << time << endl;
    DigitalClockIntToStr (2, time);
    cout << time << endl;
    DigitalClockIntToStr (59, time);
    cout << time << endl;
    DigitalClockIntToStr (60, time);
    cout << time << endl;
    DigitalClockIntToStr (61, time);
    cout << time << endl;
    DigitalClockIntToStr (120, time);
    cout << time << endl;
    DigitalClockIntToStr (125, time);
    cout << time << endl;
    DigitalClockIntToStr (160, time);
    cout << time << endl;
    DigitalClockIntToStr (3600, time);
    cout << time << endl;
    DigitalClockIntToStr (3666, time);
    cout << time << endl;
    DigitalClockIntToStr (43199, time);
    cout << time << endl;
    DigitalClockIntToStr (43200, time);
    cout << time << endl;
    DigitalClockIntToStr (86399, time);
    cout << time << endl;
    DigitalClockIntToStr (86400, time);
    cout << time << endl;
    cout << DigitalClockStrToInt ("12:00:00am") << endl;
    cout << DigitalClockStrToInt ("12:00:01am") << endl;
    cout << DigitalClockStrToInt ("12:00:02am") << endl;
    cout << DigitalClockStrToInt ("12:00:59am") << endl;
    cout << DigitalClockStrToInt ("12:01:00am") << endl;
    cout << DigitalClockStrToInt ("12:01:01am") << endl;
    cout << DigitalClockStrToInt ("12:02:00am") << endl;
    cout << DigitalClockStrToInt ("12:02:05am") << endl;
    cout << DigitalClockStrToInt ("12:02:40am") << endl;
    cout << DigitalClockStrToInt ("01:00:00am") << endl;
    cout << DigitalClockStrToInt ("01:01:06am") << endl;
    cout << DigitalClockStrToInt ("11:59:59am") << endl;
    cout << DigitalClockStrToInt ("12:00:00pm") << endl;
    cout << DigitalClockStrToInt ("11:59:59pm") << endl;
}