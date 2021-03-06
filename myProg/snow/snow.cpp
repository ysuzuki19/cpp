#include <iostream>
#include <vector>
#include <thread>
#include <random>
using namespace std;
#include <color.hpp>

int snowwing(vector<vector<char> >&);
int displaySnow(vector<vector<char> >&);

int main(int argv, char **argc)j
  const int R = 100;
  const int C = 50;
  const int sleepTime = 10;
  vector<vector<char> > snow (C, vector<char>(R,  ' '));

  while(1){
    snowwing(snow);
    system("clear");
    displaySnow(snow);
    this_thread::sleep_for(chrono::milliseconds(sleepTime));
  }
  return 0;
}


int snowwing(vector<vector<char> > &snow){
  for(int i=1; i<snow.size(); i++){
      snow[snow.size()-i] = snow[snow.size()-i-1];
  }
  for(int i=0; i<snow.front().size(); i++){
    if(rand()%20 == 0){
      snow[0][i] = '*';
    }else{
      snow[0][i] = ' ';
    }
  }
  return 0;
}


int displaySnow(vector<vector<char> > &snow){
  for(int i=0; i<snow.size(); i++){
    for(int j=0; j<snow.front().size(); j++){
      cout << CYAN << snow[i][j] << RESET;
    }
    cout << endl;
  }
  return 0;
}
