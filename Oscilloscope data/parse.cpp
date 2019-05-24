// parse files

/* Sarah Skinner 5-21-2019
========================================
This program takes data files that have a certain
form of output. In this particular case the 
oscilloscope created an output with two header 
lines:

x-axis, 2
second, Volt

proceeded by 1000 data points of the oscilloscope readings

then two more header lines:

x-axis, MATH
Hertz, dBV

proceeded by 1000 data points of the FFT. The program
takes however many of these data files you want to put
together and puts them in one csv file of the form

second,Volt,Hertz,dBV, second,Volt...
(data file 1           data file 2...)

proceeded by 1000 data points with the oscilloscope data
and the FFT side by side.*/


using namespace std;
#include <iostream>
#include <fstream>
#include <string.h>

void writefile( int n ){
  //cout << "hello worls" << endl;
  ifstream fin, fin2;
  ofstream fout, fout2;
  char doors[7] = "woors_";
  char doors2[8] = "woors2_";
  char csv[5] = ".csv";
  char end2[7] = ".csv";
  char filename1[25] = "";
  char filename2[25] = "";
  string temp;
  temp = to_string( n );
    
  strcat( filename1, doors ); 
  strcat( filename2, doors2 ); 
  if (n<10) {
    strcat( filename1, "0" );
    strcat( filename2, "0" );
  }
  strcat( filename1, temp.c_str() );
  strcat( filename2, temp.c_str() );
  strcat( filename1, csv );
  strcat( filename2, end2 );
  
  
  //cout<< filename1 << endl << filename2 <<endl;
  //return;
  
  fin.open(filename1);
  fout2.open(filename2);
  char start_line[60], line[1000][60], newline[30];

  fin >> line[0];
  fin >> start_line;
  //cout << start_line << endl << line[0] << endl;
  
  for( int i = 0; i<1000; i++){
    fin >> line[i];
  };
  
  fin >> newline;
  fin >> newline;
  //cout << newline <<endl;
  strcat( start_line, ",");
  strcat( start_line, newline);
  fout2 << start_line << endl;
  
  for( int i = 0; i<1000; i++){
    fin >> newline;
    strcat( line[i] , ",");
    strcat( line[i] , newline);
    fout2 << line[i] <<endl;
  };
  
  
  cout << "file "<< n <<endl;
  
  fin.close();
  fout2.close();
  return;
}

void onefile( int n, int m ){
  
  //cout << "hello worls" << endl;
  ifstream fin, fin2;
  ofstream fout, fout2;
  char name[30] = "";
  char doors[30] = "_";
  char doors2[30] = "_all";
  char csv[5] = ".csv";
  char end2[7] = ".csv";
  char filename1[25] = "";
  char filename2[25] = "";
  string temp;
  bool zero = false;
  
  cout<<"Name of file: ";
  cin >> name;
  cout<<"Extra Zero? (true,1/false,0): ";
  cin>>zero;
  
  strcat( filename2, name );
  strcat( filename2, doors2 ); 
  strcat( filename2, end2 );
  
  
  //cout<< filename1 << endl << filename2 <<endl;
  //return;
  
  fout2.open(filename2);
  char start_line[60], line[1000][60], newline[30], all_line[1001][1500];
  for( int i = 0; i<=1000; i++) all_line[i][0] = '\0';

  for( int k = m; k <=n; k++){
    filename1[0] = '\0';
    strcat( filename1, name);
    strcat( filename1, doors );
    temp = to_string( k );
    if ( (k<10) && zero ) {
      strcat( filename1, "0" );
    }
    strcat( filename1, temp.c_str() );
    strcat( filename1, csv );
    fin.open(filename1);
    
    
    start_line[0] = '\0';
    for ( int i = 0; i<1000; i++) line[i][0] = '\0';
    

    fin >> start_line;
    fin >> start_line;
    //cout << start_line << endl << line[0] << endl;
    
    for( int i = 0; i<1000; i++) fin >> line[i];
    
    fin >> newline;
    fin >> newline;
    //cout << newline <<endl;
    strcat( start_line, ",");
    strcat( start_line, newline);
    //strcat( start_line, ",dBV");
    strcat( start_line, ",");
    strcat( all_line[0], start_line );
    
    for( int i = 0; i<1000; i++){
      fin >> newline;
      strcat( line[i] , ",");
      strcat( line[i] , newline);
      strcat( line[i] , ",");
      strcat( all_line[i+1], line[i]);
    };
    
    cout << "file "<< k <<endl;
       
    fin.close();
  };
    
  for( int i = 0; i<=1000; i++) fout2 << all_line[i] <<endl;
    
  fout2.close();
  return;
}
  

int main()
{
  
  //int m = 0;
  int max;
  int min;
  int i;
  
  cout<<"How many data sets?: ";
  cin >> i;
  
  
  for ( int j=0; j<i; j++){
    cout<< "No of files: ";
    cin >> max;
    cout<< "Minimum: ";
    cin>>min;
  /*   for( int i = 1; i<=max; i++){
      writefile(i);
    } */
    
    onefile(max, min);
  }
  
  return 0;
  
}

