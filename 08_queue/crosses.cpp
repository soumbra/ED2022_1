#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

void show(queue<char> &f){
	for (auto it = f.front(); it != f.back(); it++){
        cout << it << ' ';
    }
    cout << f.back() << ' ';
}

void copa(queue<char> &clubs, int gol1, int gol2) {
    if (gol1 > gol2) {
        auto it = clubs.front();
        clubs.push(it);
        clubs.pop();
        clubs.pop();
    } else {
        clubs.pop();
        auto time = clubs.front();
        clubs.push(time);
        clubs.pop();
    }
}

int main ()
{
    queue<char> times;

	for (char i = 'A'; i < 'Q'; i++) {
		times.push(i);
    }

    while (times.size() != 1) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << "\n";
        stringstream ss(line);
        int gol1{0}, gol2{0};
        ss >> gol1 >> gol2;
        copa(times, gol1, gol2);       
    }

    show(times);
    return 0;
}