#include<iostream>
#include<string>
#include <ctime>
#include <cstdlib>
using namespace std;
int p1;
int p2;
int scorep1;
int scorep2;
string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};


int drawCard(){
    int	p1 = rand()%13+1;
    return p1;
}




int drawCard2(){
    int	p2 = rand()%13+1;
    return p2;
}

int calScore(int x,int y,int z)
{
    int score = 0;
    if(x>9)
    {
        x=0;
    }
    if(y>9)
    {
        y=0;
    }
    if(z>9)
    {
        z=0;
    }
    score = x+y+z;
    if(score>9)
    {
        score=score%10;
    }
    return score;
}

int findYugiAction(int s){	
	if(s == 9) return 2; 
	else if(s < 6) return 1;
	else
	{
	    int x =rand()%100+1;
	    if(x>31)
	    {
		return 1;
		}
		else{ 
		return 2;
		}
	}
}

void checkWinner(int p, int y){
 
	// Write condition for cout in this function
	cout << "\n---------------------------------\n";
	if(p==y){
	cout <<   "|             Draw!!!           |"; // when p is equal to y
	}
	if(p>y){
	cout <<   "|         Player wins!!!        |"; // when p is greater than y
	}
	if(p<y){
	cout <<   "|          Yugi wins!!!         |"; // when p is less than y
	}
	cout << "\n---------------------------------\n";
}


int main(){	
    srand(time(0));
    int drawcardp1 ;
    int drawcardp2 ;
	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3]= {drawCard2(), drawCard2(), 0};
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction!=1 && playerAction!=2); //This line of code is not completed. You need to set the condition to do loop if user's input is not 1 or 2. 
	if(playerAction == 1){
		drawcardp1=drawCard();
		
		cout << "Player draws the 3rd card!!!" << "\n";
		
		cout << "Your 3rd card: " ;
		cout << cardNames[drawcardp1]<<"\n";
		cout << "Your new score: " ;
		playerCards[2]=drawcardp1;
		playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
		cout<<playerScore<<"\n";
	}
	cout << "------------ Turn end -------------------\n\n";
	
	
	
	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " <<cardNames[yugiCards[0]] << " " << cardNames[ yugiCards[1]] << "\n";
	yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiAction = findYugiAction(yugiScore);
	if(yugiAction == 1){
	    drawcardp2=drawCard();
		cout << "Yugi draws the 3rd card!!!\n";
		yugiCards[2]=drawcardp2;
		cout << "Yugi's 3rd card: "<< cardNames[yugiCards[2]]<<"\n";
		yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
		cout << "Yugi's new score: " << yugiScore<<"\n" ;
	
	}
	cout << "------------ Turn end -------------------\n";
	
	
	checkWinner(playerScore,yugiScore);
}

