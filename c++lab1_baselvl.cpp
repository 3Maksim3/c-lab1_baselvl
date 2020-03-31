#include <iostream>
#include <string.h>

using namespace std;

struct Students {
    char F[56];
    char Group[56];
    short physics;
    short compscience;
    short history;
};

struct Train {
    short number;
    char placearrival[40];
    char placedeparture[40];
    short houra;
    short hourd;
    short minutea;
    short minuted;
    short seconda;
    short secondd;
};

struct STUDENT {
    char Name[56];
    short Kurs;
    short SES[5];
};

int main()
{
    int var;
    cout << " Choose number task (1, 2, 3) " << endl;
    cin >> var;
    switch (var)
    {
        case 1:
        {
            const int N = 5;
            Students pupil[N];
            for (int i = 0; i < N; i++)
            {
                cout << " Input Username" << i + 1 << ": " << endl;
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
                    cout << " Sdudent which have average mark high 4: " << endl;
                    cout << " Username:" << pupil[i].F << endl;
                    cout << " Group:" << pupil[i].Group << endl;
                    cout << " Mark for physics: " << pupil[i].physics << endl;
                    cout << " Mark for compscience: " << pupil[i].compscience << endl;
                    cout << " Mark for history: " << pupil[i].history << endl;
                }
            }
            break;
        }
        case 2:
        {
            const int N = 3;
            Train train[N];
            for (int i = 0; i < N; i++)
            {
                cout << " Input number of Train: " << endl;
                cin >> train[i].number;

                cout << " Input place of departure: " << endl;
                cin.ignore(cin.rdbuf()->in_avail());
                cin.getline(train[i].placedeparture, 40);

                cout << " Input place of arrival: " << endl;
                cin.ignore(cin.rdbuf()->in_avail());
                cin.getline(train[i].placearrival, 40);

                do
                {
                    cout << " Input time of departure(hour/minute/second): " << endl;
                    cin >> train[i].hourd >> train[i].minuted >> train[i].secondd;
                } while (train[i].hourd < 0 || train[i].hourd > 24 || train[i].minuted < 0 || train[i].minuted > 60 || train[i].secondd < 0 || train[i].secondd > 60);

                do
                {
                    cout << " Input time of arrival(hour/minute/second): " << endl;
                    cin >> train[i].houra >> train[i].minutea >> train[i].seconda;
                } while (train[i].houra < 0 || train[i].houra > 24 || train[i].minutea < 0 || train[i].minutea > 60 || train[i].seconda < 0 || train[i].seconda > 60);
            }

            cout << endl << endl;

            for (int i = 0; i < N; i++)
            {
                if (abs(train[i].houra - train[i].hourd) > 6 && abs(train[i].minutea - train[i].minuted) > 19)
                {
                    cout << " The train that travels 7h 20m: " << endl;
                    cout << " Number: " << train[i].number << endl;
                    cout << " Place departure: " << train[i].placedeparture << endl;
                    cout << " Place arrival: " << train[i].placearrival << endl;
                    cout << " Time departure: " << train[i].hourd << "." << train[i].minuted << "." << train[i].secondd << endl;
                    cout << " Time arrival: " << train[i].houra << "." << train[i].minutea << "." << train[i].seconda << endl;
                }
            }
            break;
        }
        case 3:
        {
            const int N = 10;
            int average = 0, a, allaverage,avrg;
            int ALL[N];
            STUDENT STUD[N];
            for (int i = 0; i < 10; i++)
            {
                cout << i + 1 << ")Input Username and initials: " << endl;
                cin.ignore(cin.rdbuf()->in_avail());
                cin.getline(STUD[i].Name, 56);

                cout << " Input your kurs: " << endl;
                do
                {
                    cin >> STUD[i].Kurs;
                } while (STUD[i].Kurs > 7 || STUD[i].Kurs < 1);

                cout << " Input your academic performance(5 mark):  " << endl;
                for (int j = 0; j < N / 2; j++)
                {
                    do
                    {
                        cin >> STUD[i].SES[j];
                    } while (STUD[i].SES[j] > 5 || STUD[i].SES[j] < 1);
                    average = average + STUD[i].SES[j];
                }
                avrg = 0;
                for (int j = 0; j < N / 2; j++)
                    avrg = avrg + STUD[i].SES[j];
                ALL[i] = avrg / 5;
            }

            allaverage = average / 50;
            
            for (int i = 0; i < N; i++)
                if (ALL[i] > allaverage)
                {
                    cout << " NAME: " << STUD[i].Name << " ";
                    cout << " KURS: " << STUD[i].Kurs << " ";
                    for (int j = 0; j < N / 2; j++)
                        cout << " SES: " << STUD[i].SES[j] << " ";
                }
            break;
        }
        default:
        {
            cout << " Input again " << endl;
            break;
        }
    }
}

