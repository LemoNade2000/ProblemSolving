#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N, M;

struct Team{
    string name;
    int minPlace;
    int maxPlace;
    int points;
    Team(string name){
        this->name = name;
        minPlace = INT_MAX;
        maxPlace = INT_MIN;
        points = 0;
    }
};

unordered_map<string, Team*> teams;
vector<Team*> teamVector;
vector<Team*> ordered;

struct Match{
    Team* home;
    Team* away;
    int result; // 0 = home 1 = away 2 = draw 3 = undecided
    Match(Team* home, Team* away, int result){
        this->home = home;
        this->away = away;
        this->result = result;
    }
};

vector<Match*> matches;

bool comp(Team* a, Team* b){
    if(a->points > b->points){
        return true;
    }
    else return false;
}

int calcPlace(){
    sort(teamVector.begin(), teamVector.end(), comp);
    int lastPoint = INT_MAX;
    int rank = 0;
    int temp = 0;
    for(auto i : teamVector){
        if(i->points < lastPoint){
            rank += 1;
            temp = rank;
            lastPoint = i->points;
            i->maxPlace = max(i->maxPlace, temp);
            i->minPlace = min(i->minPlace, temp);
        }
        else if(i->points == lastPoint){
            rank += 1;
            i->maxPlace = max(i->maxPlace, temp);
            i->minPlace = min(i->minPlace, temp);
        }
    }
    return 0;
}

int dfs(int matchNum){
    if(matchNum == matches.size()){
        calcPlace();
        return 0;
    }
    matches[matchNum]->home->points += 3;
    dfs(matchNum + 1);
    matches[matchNum]->home->points -= 3;
    matches[matchNum]->away->points += 3;
    dfs(matchNum + 1);
    matches[matchNum]->away->points -= 3;
    matches[matchNum]->home->points += 1;
    matches[matchNum]->away->points += 1;
    dfs(matchNum + 1);
    matches[matchNum]->home->points -= 1;
    matches[matchNum]->away->points -= 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        cin >> N >> M;
        teams.clear(); teamVector.clear(); matches.clear(); ordered.clear();
        if(N == 0 && M == 0){
            return 0;
        }
        for(int i = 0; i < N; i++){
            string name;
            cin >> name;
            Team* a = new Team(name);
            teams.insert({name, a});
            teamVector.push_back(a);
            ordered.push_back(a);
        }
        for(int i = 0; i < M; i++){
            string home, away;
            int a, b;
            string vs;
            cin >> home >> vs >> away >> a >> b;
            away.pop_back();
            if(a == -1 && b == -1){
                Match* a = new Match(teams[home], teams[away], 3);
                matches.push_back(a);
            }
            else if(a > b){
                teams[home]->points += 3;
            }
            else if(b > a){
                teams[away]->points += 3;
            }
            else if(a == b){
                teams[home]->points += 1;
                teams[away]->points += 1;
            }
        }
        dfs(0);
        for(auto i : ordered){
            cout << "Team " << i->name << " can finish as high as ";
            if(i->minPlace == 1){
                cout << "1st ";
            }
            else if(i->minPlace == 2){
                cout << "2nd ";
            }
            else if(i->minPlace == 3){
                cout << "3rd ";
            }
            else{
                cout << i->minPlace << "th ";
            }
            cout << "place and as low as ";
            if(i->maxPlace == 1){
                cout << "1st ";
            }
            else if(i->maxPlace == 2){
                cout << "2nd ";
            }
            else if(i->maxPlace == 3){
                cout << "3rd ";
            }
            else{
                cout << i->maxPlace << "th ";
            }
            cout << "place.\n";
        }
        cout << "\n";
    }
    return 0;
}