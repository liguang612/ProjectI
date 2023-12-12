#include <iostream>
#include <map>

using namespace std;

int Point;
string user_id, problem_id, _time, status;

struct problem{
    int a[25] = {};
};

map<string, int> map_error;
map<string, problem> map_point;
int error[1000005] = {};
int point[1000005][20] = {};
int total_number_submissions = 0, number_error_submission = 0;
int submission[100005] = {};

int convert(string t) {
    return ((t[0] - '0') * 10 + t[1] - '0') * 3600 + ((t[3] - '0') * 10 + t[4] - '0') * 60 + ((t[6] - '0') * 10 + t[7] - '0');
}

int change(string uid){
    int n = uid.length();
    int id = 0;
    for (int i = 1; i < n; i++) {
        id = id * 10 + uid[i] - '0';
    }

    return id;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    while (cin >> user_id) {
        if (user_id == "#") {
            break;
        }

        cin >> problem_id >> _time >> status >> Point;

        int tmp = (status == "ERR");
        
        total_number_submissions++;
        number_error_submission += tmp;

        if (user_id.length() > 6) {
            map_error[user_id] += tmp;
            map_point[user_id].a[(problem_id[1] - '0') * 10 + problem_id[2] - '0'] = max(Point, map_point[user_id].a[(problem_id[1] - '0') * 10 + problem_id[2] - '0']);
        }
        else{
            int id = change(user_id);

            error[id] += tmp;
            point[id][(problem_id[1] - '0') * 10 + problem_id[2] - '0'] = max(Point, point[id][(problem_id[1] - '0') * 10 + problem_id[2] - '0']);
        }
        submission[convert(_time)]++;
    }

    for(int i = 1; i <= 100000; i++) {
        submission[i] += submission[i - 1];
    }

    string req;
    while (cin >> req) {
        if (req == "#") {
            break;
        }
        else if (req == "?total_number_submissions") {
            cout << total_number_submissions << '\n';
        }
        else if (req == "?number_error_submision") {
            cout << number_error_submission << '\n';
        }
        else if (req=="?number_error_submision_of_user") {
            cin >> user_id;
            
            if (user_id.length() > 6) {
                cout << map_error[user_id] << '\n';
            } else {
                cout << error[change(user_id)] << '\n';
            }
        }
        else if (req == "?total_point_of_user") {
            cin >> user_id;
            
            int total_point_of_user = 0;
            
            if (user_id.length() > 6) {
                for(int i = 0; i <= 19; i++) {
                    total_point_of_user += map_point[user_id].a[i];
                }
            } else {
                int id = change(user_id);
                for (int i = 0; i <= 19; i++) {
                    total_point_of_user+=point[id][i];
                }
            }
            cout << total_point_of_user << '\n';
        }
        else if (req == "?number_submission_period") {
            string start_time, end_time;
            
            cin >> start_time >> end_time;
            
            cout << submission[convert(end_time)] - submission[convert(start_time) - 1] << '\n';
        }
    }

    return 0;
}