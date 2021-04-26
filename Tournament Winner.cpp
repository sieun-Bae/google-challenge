#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

bool cmp(const pair<string, int>& o1, const pair<string, int>& o2)
{
	if (o1.second == o2.second)
		return o1.first < o2.first;
	return o1.second > o2.second;
}
string tournamentWinner(vector< vector<string> > competitions,
                        vector<int> results) {
  int len = results.size();
	map<string, int> score;
	
	string team = "";
	for (int i=0;i<len;i++) {
		if (results[i] == 0) { //away team won
			team = competitions[i][1];
			//score[team] += 3;
		} else {
			team = competitions[i][0];
			//score[team] += 3;
		}
		score[team] += 3;
	}

	vector<pair <string, int> > vec(score.begin(), score.end());
	sort(vec.begin(), vec.end(), cmp);

	string answer = vec[0].first;
	return answer;
}

//2. Unordered map, variables, clean code
//O(N) time | O(K) space

#include <vector>
#include <unordered_map>
#define HOME_TEAM_WON = 1

void updateScores(string team, int points, unordered_map<string, int>& scores);
string tournamentWinner2(vector< vector<string> > competitions, vector<int> results)
{
	string currentBestTeam = "";
	unordered_map<string, int> scores = {{currentBestTeam, 0}};

	for (int idx=0; idx<competitions.size(); idx++) {
		auto result = results[idx];
		auto competition = competitions[idx];
		auto homeTeam = competition[0];
		auto awayTeam = competition[1];
		auto winningTeam = result==HOME_TEAM_WON? homeTeam : awayTeam;

		updateScores(winningTeam, 3, scores);

		if (scores[winningTeam] > scores[currentBestTeam])
			currentBestTeam = winningTeam;
	}
	return currentBestTeam;
}

void updateScores(string team, int points, unordered_map<string, int>& scores)
{
	if(scores.find(team) == scores.end()) {
		scores[team] = 0;
	}
	scores[team] += points;
}

int main()
{
	vector< vector<string> > competitions;
	vector<int> results;
	results.push_back(0);
	results.push_back(0);
	results.push_back(1);

	vector<string> tmp;
	tmp.push_back("HTML");
	tmp.push_back("C#");
	
	competitions.push_back(tmp);

	tmp.clear();
	tmp.push_back("C#");
	tmp.push_back("Python");
	
	competitions.push_back(tmp);

	tmp.clear();
	tmp.push_back("Python");
	tmp.push_back("HTML");
	
	competitions.push_back(tmp);

	printf("%s ", tournamentWinner(competitions, results).c_str());

}