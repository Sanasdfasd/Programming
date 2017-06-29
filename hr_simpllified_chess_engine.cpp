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
#include <algorithm>

using namespace std;
void  recursive_moves(int moves,char white[][4],char black[][4],bool res);

int w,b,m;
bool global_fal=true;
void copy_correct(char white[][4],char black[][4],char new_white[][4],char new_black[][4])
{
 int i,j;
 for(i=0;i<4;i++)
 {
  for(j=0;j<4;j++)
  {
    white[i][j]=new_white[i][j];
  }
 }
 for(i=0;i<4;i++)
 {
  for(j=0;j<4;j++)
  {
    black[i][j]=new_black[i][j];
  }
 }

}
void white_position_to_change(int moves,char white[][4],char black[][4],bool res,char vals,int xloc,int yloc ,int newx,int newy)
{
char temp,temp1;
     temp=white[newx][newy];
     temp1=black[newx][newy];
     if(temp=='0')
     {
      white[newx][newy]=vals;
      white[xloc][yloc]='0';
      black[newx][newy]='0';
      if(temp1=='Q')
        res=true;
       recursive_moves(moves+1,white,black,res);

     }

}
void  black_position_to_change(int moves,char white[][4],char black[][4],bool res,char vals,int xloc,int yloc ,int newx,int newy)
{
  char temp,temp1;
     temp=black[newx][newy];
     temp1=white[newx][newy];
     if(temp=='0')
     {
      black[newx][newy]=vals;
      black[xloc][yloc]='0';
      white[newx][newy]='0';
       recursive_moves(moves+1,white,black,res);
     }
}


void pawn_moves1(int moves,char white[][4],char black[][4],bool res,int xloc,int yloc,char vals)
{
    char temp_white[4][4];
  char temp_black[4][4];
  int i,j;
  for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {
      temp_white[i][j]=white[i][j];
    }
  }
    for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {
      temp_black[i][j]=black[i][j];
    }
  }
 
  if(moves%2==0)
  {
  //possible moves are
  if((xloc-1)>=0)
  {
    //promoting bishop or rook 
      if((xloc-1)==0)
       {
          //find a Bishop 
          int i,j,l;
          for(i=0;i<4;i++)
          { l=0;
            for(j=0;j<4;j++)
            {
               if(white[i][j]=='B')
               {l=1;
                 break;
               }
            }
            if(l==1)
            {
              break;
            }
          }
          if(l==1)
          {
            white[xloc][yloc]='B';
            white[i][j]='0';
            recursive_moves(moves+1,white,black,res);
            white[i][j]='B';
            white[xloc][yloc]='P';
            copy_correct(white,black,temp_white,temp_black);
          }
          
          //find a Rook
          for(i=0;i<4;i++)
          { l=0;
            for(j=0;j<4;j++)
            {
               if(white[i][j]=='R')
               {l=1;
                 break;
               }
            }
            if(l==1)
            {
              break;
            }
          }
          if(l==1)
          {
            white[xloc][yloc]='R';
            white[i][j]='0';
            recursive_moves(moves+1,white,black,res);
            white[i][j]='R';
            white[xloc][yloc]='P';
            copy_correct(white,black,temp_white,temp_black);
          }
       }
      else
      {
        white_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc-1,yloc);
        copy_correct(white,black,temp_white,temp_black);
       if((yloc-1)>=0 && black[xloc-1][yloc-1]!='0')
       {
         white_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc-1,yloc-1);
         copy_correct(white,black,temp_white,temp_black);
       }  

      }
  }
} 
  else
  {
  if((xloc+1)<=3)
   {
    //promoting bishop rook or queen for black
      if((xloc+1)==3)
       {

          //find a Bishop 
          int i,j,l;
          for(i=0;i<4;i++)
          { l=0;
            for(j=0;j<4;j++)
            {
               if(black[i][j]=='B')
               {l=1;
                 break;
               }
            }
            if(l==1)
            {
              break;
            }
          }
          if(l==1)
          {
            black[xloc][yloc]='B';
            black[i][j]='0';
            recursive_moves(moves+1,white,black,res);
            black[i][j]='B';
            black[xloc][yloc]='P';
            copy_correct(white,black,temp_white,temp_black);
          }
          
          //find a Rook
          for(i=0;i<4;i++)
          { l=0;
            for(j=0;j<4;j++)
            {
               if(black[i][j]=='R')
               {l=1;
                 break;
               }
            }
            if(l==1)
            {
              break;
            }
          }
          if(l==1)
          {
            black[xloc][yloc]='R';
            black[i][j]='0';
            recursive_moves(moves+1,white,black,res);
            black[i][j]='R';
            black[xloc][yloc]='P';
            copy_correct(white,black,temp_white,temp_black);
          }

       }
      else
      {
       white_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc+1,yloc);
       copy_correct(white,black,temp_white,temp_black);
       if((yloc+1)<=3 && white[xloc+1][yloc+1]!='0')
       {
        white_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc+1,yloc+1);
        copy_correct(white,black,temp_white,temp_black);
       }           
      }
    }
  }
 

}


void rooks_moves(int moves,char white[][4],char black[][4],bool res,int xloc,int yloc,char vals)
{
  char temp_white[4][4];
  char temp_black[4][4];
  int i,j;
  for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {
      temp_white[i][j]=white[i][j];
    }
  }
    for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {
      temp_black[i][j]=black[i][j];
    }
  }
 
 if(moves%2==0)
 {
  int i,j;
  //row wise moves 
  for(i=0;i<=3;i++)
  {
     white_position_to_change(moves,white,black,res,vals,xloc,yloc,i,yloc);
     copy_correct(white,black,temp_white,temp_black);
  }
  //column wise moves  
  for(i=0;i<=3;i++)
  {
    white_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc,i);
    copy_correct(white,black,temp_white,temp_black);
  }

 }
else
 {
  int i,j;
  //row wise moves 
  for(i=0;i<=3;i++)
  {
     black_position_to_change(moves,white,black,res,vals,xloc,yloc,i,yloc);
     copy_correct(white,black,temp_white,temp_black);
  }
  //column wise moves  
  for(i=0;i<=3;i++)
  {
    black_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc,i);
    copy_correct(white,black,temp_white,temp_black);
  }
 }

}
void bishops_moves(int moves,char white[][4],char black[][4],bool res,int xloc,int yloc,char vals)
{
      char temp_white[4][4];
  char temp_black[4][4];
  int i,j;
  for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {
      temp_white[i][j]=white[i][j];
    }
  }
    for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {
      temp_black[i][j]=black[i][j];
    }
  }
if(moves%2==0)
{
   // Along this  \ cross direction 
 int i,j;
 for(i=1;i<4;i++)
 {
     if((xloc-i)>=0 && (yloc-i)>=0)
     {
      white_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc-i,yloc-i);
       copy_correct(white,black,temp_white,temp_black);
     }
     else
      break;
 }
   // Along this  \ cross direction 

 for(i=1;i<4;i++)
 {
       if((xloc+i)<=3 && (yloc+i)<=3)
     {
        white_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc+i,yloc+i);
         copy_correct(white,black,temp_white,temp_black);
     }
     else
      break;
 }

 //Along this / cross direction
 for(i=1;i<4;i++)
 {
  
     if((xloc-i)>=0 && (yloc+i)<=3)
     {
      white_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc-i,yloc+i);
       copy_correct(white,black,temp_white,temp_black);
     }
     else
      break;
 }
 //Along this / cross direction
 for(i=1;i<4;i++)
 {
       if((xloc+i)<=3 && (yloc-i)>=0)
     {
      white_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc+i,yloc-i);
       copy_correct(white,black,temp_white,temp_black);
     }
     else
      break;
 }

}
else
{
   // Along this  \ cross direction 
 int i,j;
 for(i=1;i<4;i++)
 {
     if((xloc-i)>=0 && (yloc-i)>=0)
     {
        black_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc-i,yloc-i);
         copy_correct(white,black,temp_white,temp_black);
     }
     else
      break;
 }
   // Along this  \ cross direction 

 for(i=1;i<4;i++)
 {
       if((xloc+i)<=3 && (yloc+i)<=3)
     {
      black_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc+i,yloc+i);
       copy_correct(white,black,temp_white,temp_black);
     }
     else
      break;
 }

 //Along this / cross direction
 for(i=1;i<4;i++)
 {
  
     if((xloc-i)>=0 && (yloc+i)<=3)
     {
       black_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc-i,yloc+i);
        copy_correct(white,black,temp_white,temp_black);
     }
     else
      break;
 }
 //Along this / cross direction
 for(i=1;i<4;i++)
 {
       if((xloc+i)<=3 && (yloc-i)>=0)
     {
      black_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc+i,yloc-i);
       copy_correct(white,black,temp_white,temp_black);
     }
     else
      break;
 }

}


}


void knights_moves(int moves,char white[][4],char black[][4],bool res,int xloc,int yloc,char vals)
{
  char temp_white[4][4];
  char temp_black[4][4];
  int i,j;
  for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {
      temp_white[i][j]=white[i][j];
    }
  }
    for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {
      temp_black[i][j]=black[i][j];
    }
  }
if(moves%2==0)
{
  //left top 
if((xloc-2)>=0 && (yloc-1)>=0)
{
 white_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc-2,yloc-1);
 copy_correct(white,black,temp_white,temp_black);
}
  //right top
if((xloc-2)>=0 && (yloc+1)<=3)
{
 white_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc-2,yloc+1); 
 copy_correct(white,black,temp_white,temp_black); 
}
  //left bottom
if((xloc+2)<=3 && (yloc-1)>=0)
{
 white_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc+2,yloc-1);  
 copy_correct(white,black,temp_white,temp_black);
}
  //right top
if((xloc+2)<=3 && (yloc+1)<=3)
{
white_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc+2,yloc+1);    
copy_correct(white,black,temp_white,temp_black);
}

}
else
{
  
if((xloc-2)>=0 && (yloc-1)>=0)
{
 black_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc-2,yloc-1);
 copy_correct(white,black,temp_white,temp_black);
}
  //right top
if((xloc-2)>=0 && (yloc+1)<=3)
{
  black_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc-2,yloc+1); 
  copy_correct(white,black,temp_white,temp_black);
}
  //left bottom
if((xloc+2)<=3 && (yloc-1)>=0)
{
  black_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc+2,yloc-1); 
  copy_correct(white,black,temp_white,temp_black);
}
  //right top
if((xloc+2)<=3 && (yloc+1)<=3)
{
  black_position_to_change(moves,white,black,res,vals,xloc,yloc,xloc+2,yloc+1); 
 copy_correct(white,black,temp_white,temp_black);
}

}

}

void queens_moves(int moves,char white[][4],char black[][4],bool res,int xloc,int yloc,char vals)
{
    char temp_white[4][4];
  char temp_black[4][4];
  int i,j;
  for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {
      temp_white[i][j]=white[i][j];
    }
  }
    for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {
      temp_black[i][j]=black[i][j];
    }
  }

  //move like a rook
 // cout<<"iam working here "<<endl;
   rooks_moves(moves,white,black,res,xloc,yloc,vals);
   copy_correct(white,black,temp_white,temp_black);
  //move like a bishop
   bishops_moves(moves,white,black,res,xloc,yloc,vals);
   copy_correct(white,black,temp_white,temp_black);
}

void  recursive_moves(int moves,char white[][4],char black[][4],bool res)
{

  int i,j;
  
   char temp_white[4][4];
  char temp_black[4][4];

  for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {
      temp_white[i][j]=white[i][j];
    }
  }
    for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {
      temp_black[i][j]=black[i][j];
    }
  }

  if(moves==m)
  {
    if(res==false)
        global_fal=false;
  }
  else if(moves>m || global_fal==false)
  {
    return ;
  }
 else
 {
        int i,j;
  //Whites moves 
   if(moves%2==0)
   {
    //All Pawn's movement 
     for(i=0;i<4;i++)
     {
      for(j=0;j<4;j++)
      {
        if(white[i][j]=='P')
         {
           pawn_moves1(moves,white,black,res,i,j,'P');
           copy_correct(white,black,temp_white,temp_black);
         }
       }

     }

    //All rooks movement 
    for(i=0;i<4;i++)
     {
      for(j=0;j<4;j++)
      {
        if(white[i][j]=='R')
         {
           rooks_moves(moves,white,black,res,i,j,white[i][j]);
           copy_correct(white,black,temp_white,temp_black);
         }
       }

     }

    //All bishops movement
    for(i=0;i<4;i++)
     {
      for(j=0;j<4;j++)
      {
        if(white[i][j]=='B')
         {
           bishops_moves(moves,white,black,res,i,j,'B');
           copy_correct(white,black,temp_white,temp_black);
         }
       }

     }

   //All  knights movement 
      for(i=0;i<4;i++)
     {
      for(j=0;j<4;j++)
      {
        if(white[i][j]=='N')
         {
           knights_moves(moves,white,black,res,i,j,'N');
           copy_correct(white,black,temp_white,temp_black);
         }
       }

     }

   //Queen's movements
      for(i=0;i<4;i++)
     {
      for(j=0;j<4;j++)
      {
        if(white[i][j]=='Q')
         {
           queens_moves(moves,white,black,res,i,j,'Q');
           copy_correct(white,black,temp_white,temp_black);
         }
       }
     }


   }
   else  //Black pecies moves
   {
      //All Pawn's movement 
     for(i=0;i<4;i++)
     {
      for(j=0;j<4;j++)
      {
        if(black[i][j]=='P')
         {
            pawn_moves1(moves,white,black,res,i,j,'P');
            copy_correct(white,black,temp_white,temp_black);
         }
       }

     }

    //All rooks movement 
    for(i=0;i<4;i++)
     {
      for(j=0;j<4;j++)
      {
        if(black[i][j]=='R')
         {
           rooks_moves(moves,white,black,res,i,j,white[i][j]);
           copy_correct(white,black,temp_white,temp_black);
         }
       }

     }

    //All bishops movement
    for(i=0;i<4;i++)
     {
      for(j=0;j<4;j++)
      {
        if(black[i][j]=='B')
         {
          bishops_moves(moves,white,black,res,i,j,'B');
          copy_correct(white,black,temp_white,temp_black);
         }
       }

     }

   //All  knights movement 
      for(i=0;i<4;i++)
     {
      for(j=0;j<4;j++)
      {
        if(black[i][j]=='N')
         {
           knights_moves(moves,white,black,res,i,j,'N');
           copy_correct(white,black,temp_white,temp_black);
         }
       }

     }

   //Queen's movements
      for(i=0;i<4;i++)
     {
      for(j=0;j<4;j++)
      {
        if(black[i][j]=='Q')
         {
           queens_moves(moves,white,black,res,i,j,'Q');
           copy_correct(white,black,temp_white,temp_black);
         }
       }
     }
   }
 }

}


int main(){
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
       global_fal=true;
        cin >> w >> b >> m;
        char black[4][4];
        char white[4][4];
        char peice,col;
        int row,i,j;
        memset(black,'0',sizeof(black));
        memset(white,'0',sizeof(white));
   for(i=0;i<w;i++)
   {  
      cin>>peice;
      cin>>col;
      cin>>row;
      int som=int((col)-'A');
      white[4-row][som]=peice;
   }
    for(i=0;i<b;i++)
   {  
      cin>>peice;
      cin>>col;
      cin>>row;
      int som=int((col)-'A');
      black[4-row][som]=peice;
   }
   /*cout<<"white peices are "<<endl;
        for(i=0;i<4;i++)
         {
            for(j=0;j<4;j++)
            {
                cout<<white[i][j]<<" ";
            }
            cout<<endl;
        }
         cout<<"black peices are "<<endl;
        for(i=0;i<4;i++)
         {
            for(j=0;j<4;j++)
            {
                cout<<black[i][j]<<" ";
            }
            cout<<endl;
        }*/
     bool res=false;
     recursive_moves(0,white,black,res);
    if(global_fal==true)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
    }
    return 0;
}
