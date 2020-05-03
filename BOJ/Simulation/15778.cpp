#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define INF 987654321

int N;
int MAP[31][6] =
{
{0,1,2,3,4,5}, //0
{1,2,3,4,5,12}, //1
{2,3,4,5,12,13}, //2
{3,4,5,12,13,14}, // 3
{4,5,12,13,14,15}, //4
{5,6,7,8,28,29}, //5
{6,7,8,28,29,23}, //6
{7,8,28,29,23,24}, //7
{8,9,10,11,30,30}, //8
{9,10,11,30,30,30}, //9
{10,11,30,30,30,30}, //10
{11,30,30,30,30,30}, //11
{12,13,14,15,16,19}, //12
{13,14,15,16,19,20}, //13
{14,15,16,19,20,21}, //14 
{15,16,19,20,21,22},//15
{16,17,18,8,9,10},//16
{17,18,8,9,10,11}, //17
{18,8,9,10,11,30}, //18
{19,20,21,22,23,24}, //19
{20,21,22,23,24,25}, //20
{21,22,23,24,25,26}, //21
{22,23,24,25,26,27}, //22
{23,24,25,26,27,11}, //23
{24,25,26,27,11,30},//24
{25,26,27,11,30,30},//25
{26,27,11,30,30,30},//26
{27,11,30,30,30,30},//27
{28,29,23,24,25,26},//28
{29,23,24,25,26,27},//29
{30,30,30,30,30,30}//30
};
int horses[8];

void move(int x, int y) {
	//x번말을 y만큼 전진시킨다.

	queue<int> q;
	q.push(x);
	if (x < 4) {
		for (int i = 0; i < 4; i++) {
			if (horses[x] == horses[i] && x!=i && horses[i]!=0) q.push(i);
		}
	}
	else {
		for (int i = 4; i < 8; i++) {
			if (horses[x] == horses[i] && x!=i &&horses[i]!=0) q.push(i);
		}
	}
	//같이 움직일 놈들을 찾는다
	while (!q.empty()) {
		horses[q.front()] = MAP[horses[q.front()]][y];
		q.pop();
	}
	if (x < 4) {
		for (int i = 4; i < 8; i++) {
			//잡아먹는경우
			if (horses[i] == horses[x])
				horses[i] = 0;
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (horses[i] == horses[x])
				horses[i] = 0;
		}
	}
}

void printAB(int t) {
	if (horses[0] == t) cout << 'A';
	else if (horses[4] == t) cout << 'a';
	else cout << '.';
	if (horses[1] == t) cout << 'B';
	else if (horses[5] == t) cout << 'b';
	else cout << '.';
}

void printCD(int t) {
	if (horses[2] ==t)	cout << 'C';
	else if (horses[6] ==t)  cout << 'c';
	else cout << '.';
	if (horses[3] == t) cout << 'D';
	else if (horses[7] == t) cout << 'd';
	else cout << '.';
}

void print() {
	for (int i = 16; i >= 12; i--) {
		printAB(i);
		cout << "----";
	}
	printAB(5);
	cout << '\n';
	for (int i = 16; i >= 12; i--) {
		printCD(i);
		cout << "    ";
	}
	printCD(5);
	cout << '\n';
	cout << "| \\                          / |\n";
	cout << "|  \\                        /  |\n";
	cout << "|   \\                      /   |\n|    ";
	printAB(17);
	cout << "                  ";
	printAB(6);
	cout << "    |\n";

	printAB(19);
	cout << "   ";
	printCD(17);
	cout << "                  ";
	printCD(6);
	cout << "   ";
	printAB(4);
	cout << endl;
	printCD(19);
	
	cout << "     \\                /     ";
	printCD(4);
	cout << '\n';
	cout << "|       \\              /       |\n|        \\            /        |\n";
	cout << "|         ";
	printAB(18);
	cout << "        ";
	printAB(7);
	cout << "         |\n|         ";
	printCD(18);
	cout << "        ";
	printCD(7);
	cout << "         |\n";
	printAB(20);
	cout << "          \\      /          ";
	printAB(3);
	cout << '\n';
	printCD(20);
	cout << "           \\    /           ";
	printCD(3);
	cout << "\n|             \\  /             |\n|              ";
	printAB(8);
	cout << "              |\n|              ";
	printCD(8);
	cout << "              |\n|             /  \\             |\n";
	printAB(21);
	cout << "           /    \\           ";
	printAB(2);
	cout << '\n';
	printCD(21);
	cout << "          /      \\          ";
	printCD(2);
	cout << "\n|         ";
	printAB(28);
	cout << "        ";
	printAB(9);
	cout << "         |\n";
	cout << "|         ";
	printCD(28);
	cout << "        ";
	printCD(9);
	cout << "         |\n";
	cout<<"|        /            \\        |\n|       /              \\       |\n";
	printAB(22);
	cout << "     /                \\     ";
	printAB(1);
	cout << '\n';
	printCD(22);
	cout << "   ";
	printAB(29);
	cout << "                  ";
	printAB(10);
	cout << "   ";
	printCD(1);
	cout << endl<<"|    ";
	printCD(29);
	cout << "                  ";
	printCD(10);
	cout << "    |\n";
	cout << "|   /                      \\   |\n";
	cout << "|  /                        \\  |\n";
	cout << "| /                          \\ |\n";
	for (int i = 23; i <= 27; i++) {
		printAB(i);
		cout << "    ";
	}
	printAB(11);
	cout << "\n";
	for (int i = 23; i <= 27; i++) {
		printCD(i);
		cout << "----";
	}
	printCD(11);
	cout << "\n";

}
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		char horse;
		string yut;
		cin >> horse >> yut;
		int front = 0;
		for (int i = 0; i < 4; i++)
			if (yut[i] == 'F') front++;
		
		if (front == 0) {
			front = 5;
		}
		if (horse == 'A') {
			move(0, front);
		}
		else if (horse == 'B') {
			move(1, front);
		}
		else if (horse == 'C') {
			move(2, front);
		}
		else if (horse == 'D') {
			move(3, front);
		}
		else if (horse == 'a') {
			move(4, front);
		}
		else if (horse == 'b') {
			move(5, front);
		}
		else if (horse == 'c') {
			move(6, front);
		}
		else if (horse == 'd') {
			move(7, front);
		}
	//	print();
	}
	print();
}
int main() {
	PREPROCESS;
	input();
	return 0;
}