#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <ctime>
#include <cstring>
#include <numeric>

using namespace std;

class Speaker; // 参赛者类前置声明

#if 0
class Speaker {
public:

	// 构造与析构
	Speaker(char *s = "") {
		m_name = new char[strlen(s) + 1];
		strcpy(m_name, s);
		score = 0;
	}
	Speaker(const Speaker &sp) {
		m_name = new char[strlen(sp.m_name) + 1];
		strcpy(m_name, sp.m_name);	
		score = 0;	
	}
	~Speaker() {
		if (m_name != NULL) {
			delete[] m_name;
			m_name = NULL;
		}
	}

	// 操作符重载
	Speaker& operator=(const Speaker &sp) {
		// 释放已有的
		if (m_name != NULL) {
			delete[] m_name;
			m_name = NULL;
		}
		// 拷贝传入的
		m_name = new char[strlen(sp.m_name) + 1];
		strcpy(m_name, sp.m_name);		
		score = sp.score;
		return *this;
	}
	// 友元
	friend ostream& operator<<(ostream &out, const Speaker &sp) {
		cout << sp.m_name << "  " << sp.score << endl;
		return out;
	}
public:
	// 可以用string的，不过这里就用char *吧
	// 这样做需要考虑拷贝构造、拷贝赋值和析构函数，巩固一下
	char *m_name; 
	int score;
};
#endif
class Speaker {
public:
	string m_name;
	int m_score[3]; // 最多三轮有三轮成绩
};

const int SPEEKER_NUM = 24;

int GenSpeaker(map<int, Speaker> &m, vector<int> &v) {
	string name;
	for (int i=0; i<SPEEKER_NUM; ++i) {
		name.push_back(i+'A');
	} 
	random_shuffle(name.begin(), name.end());
	for (int i=0; i<SPEEKER_NUM; ++i) {
		Speaker temp;
		temp.m_name = "Speaker ";
		temp.m_name += name[i];
		temp.m_score[0] = temp.m_score[1] = temp.m_score[2] = 0;
		m.insert(pair<int, Speaker>(100+i, temp));
	}
	for (int i=0; i<SPEEKER_NUM; ++i) { // 将选手参赛号加入到参赛列表
		v.push_back(100+i);
	}
	return 0;
}

int SpeakerDrawLots(vector<int> &v) {
	srand(time(NULL));
	random_shuffle(v.begin(), v.end());
	return 0;
}

int SpeackerCompetition(int times, vector<int> &v_pre, map<int, Speaker> &m, vector<int> &v_next) {
	deque<int> score_temp;
	multimap<int, int, greater<int>> rank_map; // 从大到小的多映射
	int flag = 0;
	int grounp = 0;
	for (int i=0; i<v_pre.size(); ++i) {	
		// 打分，评委数为10，共有10个分数
		// srand(time(NULL));
		for (int j=0; j<10; j++) {
			int mark = 70 + rand() % 30; // 随机产生一个70 - 99的分数
			score_temp.push_back(mark);
		}
		sort(score_temp.begin(), score_temp.end());
		// 去掉最高分与最低分
		score_temp.pop_front(); 
		score_temp.pop_back();
		m[v_pre[i]].m_score[times] = accumulate(score_temp.begin(), score_temp.end(), 0) / score_temp.size();
		score_temp.clear();
		rank_map.insert(pair<int,int>(m[v_pre[i]].m_score[times], v_pre[i]));
		if (++flag % 6 == 0) { // 将这一组的前三名加入下一轮名单
			multimap<int, int, greater<int>>::iterator it = rank_map.begin();
			cout << "====================================================" << endl;
			printf("\nThe group%d score:\n", ++grounp);
			for (; it!=rank_map.end(); ++it) {
				cout << it->second << "  " << m[it->second].m_name << "  " << m[it->second].m_score[times] << endl;
			}
			cout << "====================================================" << endl;
			it = rank_map.begin();
			int k = 3;
			while (k-- > 0) {
				v_next.push_back(it->second);
				++it;
			}
			rank_map.clear();
		}
	}
	return 0;
}

void PrintSpeaker(const int times, const vector<int> &v, map<int, Speaker> &m) {
	printf("\n\n================== Round %d promotion list ==================\n", times+1);
	int grounp = 1;
	for (int i=0; i<v.size(); i++) {
		if (i % 3 == 0) {
			printf("The group%d promotion list:\n", grounp++);
		}
		cout << v[i] << "  " << m[v[i]].m_name << "  " << m[v[i]].m_score[times] << endl;
	}
}
// 演讲比赛框架
void SpeechGame() {
	map<int, Speaker> speaker_map; // 选手参赛号与选手信息的映射
	vector<int> v1; // 第一轮名单
	vector<int> v2; // 第二轮名单
	vector<int> v3; // 第三轮名单
	vector<int> v4; // 第四轮名单

	srand(time(NULL));
	int times = 0; // 第一轮比赛
	GenSpeaker(speaker_map, v1); // 生成选手
	cout << "Press any key to start the game...";
	cin.get();
	SpeakerDrawLots(v1); // 选手抽签
	SpeackerCompetition(times, v1, speaker_map, v2);
	PrintSpeaker(times, v2, speaker_map);
	cout << "Press any key to enter the next round...";
	cin.get();
	++times; // 开始第二轮比赛
	SpeakerDrawLots(v2); // 选手抽签
	SpeackerCompetition(times, v2, speaker_map, v3);
	PrintSpeaker(times, v3, speaker_map);
	cout << "Press any key to enter the next round...";
	cin.get();
	++times; // 开始第三轮比赛
	SpeakerDrawLots(v3); // 选手抽签
	SpeackerCompetition(times, v3, speaker_map, v4);
	PrintSpeaker(times, v4, speaker_map);
}

int main() {
	SpeechGame();
	cout << "Finish..." << endl;
	return 0;
}

