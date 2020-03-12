#include <iostream>

using namespace std;

struct Students {
    char F[56];
    char Group[56];
    short physics;
    short compscience;
    short history;
};

int main()
{
    const int N = 5;
    Students pupil[N];
    for (int i = 0; i < N; i++)
    {
        cout << " Input Username" << i+1 << ": " << endl;
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(pupil[i].F, 56);

        cout << " Input Group: " << endl;
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(pupil[i].Group, 56);

        do
        {
            cout << " Input mark for physics, compscience, histoty: " << endl;
            cin >> pupil[i].physics >> pupil[i].compscience >> pupil[i].history;
        } while (pupil[i].physics < 1 || pupil[i].physics > 5 || pupil[i].compscience < 1 || pupil[i].compscience > 5 || pupil[i].history < 1 || pupil[i].history > 5);
    }
    
    cout << endl << endl;

    for (int i = 0; i < N; i++)
    {
        if ((pupil[i].physics + pupil[i].compscience + pupil[i].history) / 3 == 5)
        {
            cout << " Sdudent which have average mark high 4: "  << endl;
            cout << " Username:" << pupil[i].F << endl;
            cout << " Group:" << pupil[i].Group << endl;
            cout << " Mark for physics: " << pupil[i].physics << endl;
            cout << " Mark for compscience: " << pupil[i].compscience << endl;
            cout << " Mark for history: " << pupil[i].history << endl;
        }
    }
}

