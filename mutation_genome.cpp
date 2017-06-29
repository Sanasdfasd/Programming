#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <vector>
//#include <map>
#include <utility>
#include <algorithm>
//#include <unordered_map>

using namespace std;

/*
 * Complete the function below.
 */
int findMutationDistance(string starts, string ends, vector<string> bank) {
	
map<string,int> dp,dp1;
dp.insert(std::pair<string,int>(starts,0));  
map<string,int>::iterator it = dp.begin();
   int i,j,k;
    string str_vals = (it)->first;
    int str_compare=0;
    int int_vals = it->second;
    int str_com=0;
  int l=0,m=0;
    //Find end in the Bank.
  for(vector<string>::const_iterator itp = bank.begin(); itp != bank.end(); ++itp) { 
    if(ends.compare(*itp)==0)
       m=1;
}
    if( m==1) //Ensures End is present in the bank.
 {
    for(k=0;k<starts.length();k++) //compares between original start and end element
    {
        if(starts.at(k)!=ends.at(k))
            str_com++;
    }

  for(i=0;i<bank.size();i++) //find those strings that are 1 distance away from the start.
  { 
    int compare=0;
     for(k=0;k<starts.length();k++)
     {
         if(str_vals.at(k)!=bank[i].at(k))
            compare++;
     }
      if(compare==1)
          dp1.insert(std::pair<string,int>(bank[i],compare));
  }
        
        dp.clear();
        dp=dp1;
        dp1.clear();
        
    int counter=1;
   vector <vector<int>> indices; //list of vectors which store the indices of those bank strings that are at distance of 1 unit from bank[j] [where j varies from 0 to bank size].
        for(i=0;i<bank.size();i++)
         {
            vector <int>row;
            for(j=0;j<bank.size();j++)
            {   int compare=0;
                for(k=0;k<starts.length();k++)
                {
                   if(bank[i].at(k)!=(bank[j].at(k)))
                       compare++;
                }
                 if(compare==1)
                   row.push_back(j);
            }
           indices.push_back(row);
        }
        
    int orginal_compare[bank.size()+5]; // stores distance between Orginal start and rest all elements in Bank.
       for(i=0;i<bank.size();i++)
       {
           int cp=0;
         for(k=0;k<starts.length();k++)
             {
                 if(starts.at(k)!=(bank[i].at(k)))
                     cp++;
              }
           orginal_compare[i]=cp;
         }
                
     //Iteratively find the strings that are >=2 units away from start and are legal(present in the bank). 
    while(counter!=str_com) //Maximum number of iterations required. 
    {
        counter=counter+1;
     for(it=dp.begin(); it!=dp.end(); ++it)
     {
         string str_val = (it)->first;
         int int_val = it->second;
          vector<string>::iterator its=bank.begin();
          its=find(bank.begin(), bank.end(),str_val);
          int pos=(int)(its-(bank.begin())); //Find the postion of that string in the bank.
         
         for(vector<int>::const_iterator itu = indices[pos].begin(); itu != indices[pos].end(); ++itu)
        {
               int or_co=orginal_compare[(*itu)]; //Find the distance between this bank[index] and start.
             if((or_co==counter)) //Check if that distance is equal to current_distance i.e counter.
             {
                 std::map<string,int>::iterator it3; 
                   it3=dp1.find(bank[(*itu)]);
                      if(it3!=dp1.end()) // If state is already present in DP.
                      {
                          int some_val=dp1.find(bank[(*itu)])->second;
                          if((counter)<some_val)
                          { 
                          	dp1.find(str_val)->second=counter;
                          }
                      }
                      else      //otherwise
                       dp1.insert(std::pair<string,int>(bank[(*itu)],(counter)));
             }
        }
     }
        dp.clear();
        dp=dp1; 
        dp1.clear();
        if(dp.size()==0)
            break;
    }   
  }
map<string,int>::iterator it4;
int final_value=-1;
it4=dp.find(ends);
if(it4!=dp.end())
{ 
	final_value=dp.find(ends)->second;
}
cout<<"Final Value is :"<<final_value<<endl;
return final_value;

}
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    string _start;
    getline(cin, _start);
    
    string _end;
    getline(cin, _end);
    
    
    int _bank_size = 0;
    cin >> _bank_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _bank;
    string _bank_item;
    for(int _bank_i=0; _bank_i<_bank_size; _bank_i++) {
        getline(cin, _bank_item);
        _bank.push_back(_bank_item);
    }

    res = findMutationDistance(_start, _end, _bank);
    fout << res << endl;
    
    fout.close();
    return 0;
}

