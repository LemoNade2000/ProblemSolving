#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define MOD 1000000007
#define MAX 2100000000000

struct Node;
struct Edge;

struct Node {
    ll idx;
    ll leftTurn;
    ll rightTurn;
    vector<Edge*> edges;
    bool leftVisit;
    bool rightVisit;
    ll inCnt;
    Node(ll idx){
        this->idx = idx;
        this->leftTurn = 0;
        this->rightTurn = MAX;
        leftVisit = false;
        rightVisit = false;
        this->inCnt = 0;
    }
};

struct Edge{
    Node* start;
    Node* end;
    ll time;
    Edge(Node* start, Node* end, ll time){
        this->start = start;
        this->end = end;
        this->time = time;
    }
};

ll N, T, origin, dest;
vector<Node*> balls;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> T >> origin >> dest;
    priority_queue<pair<ll, Node*>> rightpq;
    priority_queue<pair<ll, Node*>> leftpq;
    for(ll i = 0; i < N; i++){
        Node* node = new Node(i);
        balls.push_back(node);
        if(i == dest){
            node->leftTurn = node->rightTurn = 0;
        }
        else{
            rightpq.push({-MAX, node});
        }
    }
    for(ll i = 0; i < T; i++){
        ll s, e, t;
        cin >> s >> e >> t;
        Edge* edge = new Edge(balls[e], balls[s], t);
        balls[e]->edges.push_back(edge);
        balls[s]->inCnt++;
    }
    leftpq.push({0, balls[dest]});
    rightpq.push({0, balls[dest]});
    while(!leftpq.empty() || !rightpq.empty()){
        if(!leftpq.empty()){ // slow half first, if possible 
            while(!leftpq.empty()){ // slow half
                Node* currNode = leftpq.top().second;
                ll currDist = -leftpq.top().first;
                leftpq.pop();
                for(ll i = 0; i < currNode->edges.size(); i++){
                    Edge* edge = currNode->edges[i];
                    rightpq.push({-currDist - edge->time, edge->end});
                }
                break;
            }
            continue;
        }
        while(!rightpq.empty()){ // fast half
            Node* currNode = rightpq.top().second;
            ll currDist = -rightpq.top().first;
            rightpq.pop();
            if(currNode->rightVisit == true){
                continue;
            }
            currNode->rightVisit = true;
            currNode->rightTurn = currDist;
            for(ll i = 0; i < currNode->edges.size(); i++){
                Edge* edge = currNode->edges[i];
                edge->end->leftTurn = max(edge->end->leftTurn, currDist + edge->time);
                edge->end->inCnt--;
                if(edge->end->inCnt == 0){
                    leftpq.push({-edge->end->leftTurn, edge->end});
                }
            }
            break;
        }
    }
    if(balls[origin]->leftTurn < 0 || balls[origin]->leftTurn >= MAX){
        cout << "infinity";
        return 0;
    }
    cout << balls[origin]->leftTurn;
    // for(ll i = 0; i < N; i++){
    //     cout << balls[i]->leftTurn << " " << balls[i]->rightTurn << "\n";
    // }
    return 0;
}