//========================================================================
// Name                 : asgn1.cpp
// Author               : Connor Roche
// Version              : 1
// Description          : opens a file given, reads each line, outputs all
//                        words that are of the max length of words in the
//                        file and the length of the lonest line
//========================================================================


#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <vector>
using namespace std;

//funciton declarations
void print_file_name (string const& str);

vector<int> max_line_length (ifstream& infile);
void print_max_line_length (vector<int> a);
void print_max_line_length_c (vector<int> a);
vector<int> max_line_length_b (ifstream& infile);

map<string, int> max_words_length (ifstream& infile);
void print_words (map<string, int> m);
void print_words_c (map<string, int> m);
void print_words_m (map<string, int> m);
void print_words_cm (map<string, int> m);

int main (int argc, char *argv[]) {

  // exit if no arguments are provided
  if (argc < 2) {
    cerr << "NO FILES" << endl;
    return 1;
  }
  
  //declare file and booleans for flags
  ifstream infile;
  bool c = false;
  bool m = false;
  bool b = false;
  

  // check for flags
  for (int i = 1; i < argc; i++) {
    string test = argv[i];
    if (test.find("-") != string::npos) {
      if (strcmp(argv[i], "-c") == 0) 
	c = true;
      else if (strcmp(argv[i], "-m") == 0)
	m = true;
      else if (strcmp(argv[i], "-b") == 0)
	b = true;
      else {
	cout << test << " UNRECOGNIZED FLAG" << endl;
	return 1;
      }
    }
  }

  if (c && !m && !b) {
    /* run through arguments, check if they are files, if thy are then
     run appropiate functions  */
    for (int i = 1; i < argc; i++) {
      // check if the argument is not a flag
      string test = argv[i];
      if (test.find("-") == string::npos) {
      
	// try to open file
	infile.open(argv[i]);
    
	/* check if file opened, if yes then preform functions based on 
	   arguments else report not found   */
	if (infile.is_open()) {
	  print_file_name(argv[i]);
	  print_words_c(max_words_length(infile));
	  infile.clear();
	  infile.seekg(0, ios::beg);
	  print_max_line_length_c(max_line_length(infile));
	}
	else
	  cout << argv[i] << " FILE NOT FOUND" << endl;

	infile.close();
      }
    }
  }

  else if (m && !c && !b) {
    /* run through arguments, check if they are files, if thy are then
     run appropiate functions  */
    for (int i = 1; i < argc; i++) {
      // check if the argument is not a flag
      string test = argv[i];
      if (test.find("-") == string::npos) {
      
	// try to open file
	infile.open(argv[i]);
    
	/* check if file opened, if yes then preform functions based on 
	   arguments else report not found   */
	if (infile.is_open()) {
	  print_file_name(argv[i]);
	  print_words_m(max_words_length(infile));
	  infile.clear();
	  infile.seekg(0, ios::beg);
	  print_max_line_length(max_line_length(infile));
	}
	else
	  cout << argv[i] << " FILE NOT FOUND" << endl;

	infile.close();
      }
    }
  }

  else if (b && !c && !m) {
    /* run through arguments, check if they are files, if thy are then
     run appropiate functions  */
    for (int i = 1; i < argc; i++) {
      // check if the argument is not a flag
      string test = argv[i];
      if (test.find("-") == string::npos) {
      
	// try to open file
	infile.open(argv[i]);
    
	/* check if file opened, if yes then preform functions based on 
	   arguments else report not found   */
	if (infile.is_open()) {
	  print_file_name(argv[i]);
	  print_words(max_words_length(infile));
	  infile.clear();
	  infile.seekg(0, ios::beg);
	  print_max_line_length(max_line_length_b(infile));
	}
	else
	  cout << argv[i] << " FILE NOT FOUND" << endl;

	infile.close();
      }
    }
  }

  else if (c && m && !b) {
    /* run through arguments, check if they are files, if thy are then
     run appropiate functions  */
    for (int i = 1; i < argc; i++) {
      // check if the argument is not a flag
      string test = argv[i];
      if (test.find("-") == string::npos) {
      
	// try to open file
	infile.open(argv[i]);
    
	/* check if file opened, if yes then preform functions based on 
	   arguments else report not found   */
	if (infile.is_open()) {
	  print_file_name(argv[i]);
	  print_words_cm(max_words_length(infile));
	  infile.clear();
	  infile.seekg(0, ios::beg);
	  print_max_line_length_c(max_line_length(infile));
	}
	else
	  cout << argv[i] << " FILE NOT FOUND" << endl;

	infile.close();
      }
    }
  }

   else if (c && b && !m) {
    /* run through arguments, check if they are files, if thy are then
     run appropiate functions  */
    for (int i = 1; i < argc; i++) {
      // check if the argument is not a flag
      string test = argv[i];
      if (test.find("-") == string::npos) {
      
	// try to open file
	infile.open(argv[i]);
    
	/* check if file opened, if yes then preform functions based on 
	   arguments else report not found   */
	if (infile.is_open()) {
	  print_file_name(argv[i]);
	  print_words_c(max_words_length(infile));
	  infile.clear();
	  infile.seekg(0, ios::beg);
	  print_max_line_length_c(max_line_length_b(infile));
	}
	else
	  cout << argv[i] << " FILE NOT FOUND" << endl;

	infile.close();
      }
    }
  }

   else if (c && m && b) {
    /* run through arguments, check if they are files, if thy are then
     run appropiate functions  */
    for (int i = 1; i < argc; i++) {
      // check if the argument is not a flag
      string test = argv[i];
      if (test.find("-") == string::npos) {
      
	// try to open file
	infile.open(argv[i]);
    
	/* check if file opened, if yes then preform functions based on 
	   arguments else report not found   */
	if (infile.is_open()) {
	  print_file_name(argv[i]);
	  print_words_cm(max_words_length(infile));
	  infile.clear();
	  infile.seekg(0, ios::beg);
	  print_max_line_length_c(max_line_length_b(infile));
	}
	else
	  cout << argv[i] << " FILE NOT FOUND" << endl;

	infile.close();
      }
    }
  }

   else if (b && m && !c) {
    /* run through arguments, check if they are files, if thy are then
     run appropiate functions  */
    for (int i = 1; i < argc; i++) {
      // check if the argument is not a flag
      string test = argv[i];
      if (test.find("-") == string::npos) {
      
	// try to open file
	infile.open(argv[i]);
    
	/* check if file opened, if yes then preform functions based on 
	   arguments else report not found   */
	if (infile.is_open()) {
	  print_file_name(argv[i]);
	  print_words_m(max_words_length(infile));
	  infile.clear();
	  infile.seekg(0, ios::beg);
	  print_max_line_length(max_line_length_b(infile));
	}
	else
	  cout << argv[i] << " FILE NOT FOUND" << endl;

	infile.close();
      }
    }
  }

  else {
    for (int i = 1; i < argc; i++) {
      // try to open file
      infile.open(argv[i]);
    
      /* check if file opened, if yes then preform functions based on arguments
	 else report not found   */
      if (infile.is_open()) {
	print_file_name(argv[i]);
	print_words(max_words_length(infile));
	infile.clear();
	infile.seekg(0, ios::beg);
	print_max_line_length(max_line_length(infile));
      }
      else
	cout << argv[i] << " FILE NOT FOUND" << endl;

      infile.close();
    }
  }

  return 0;
}

      
/* find the line with the max length and returns a array:
   [line length, # of occurences]  */
vector<int> max_line_length (ifstream& infile) {
  
  //declare variables for line and max length
  string line;
  size_t max = 0;
  vector<int> result(2, 0);

  //get each line and find the largest line
  while (getline (infile, line)) {
    if (line.length() > max) {
      max = line.length();
      result[0] = max;
      result[1] = 1;
    }
    else if (line.length() == max)
      result[1] += 1;
  }

  return result;
}

/* find the line with the max length (ignoring whitespace composed of multiple
   space characters and returns a array:
   [line length, # of occurences]  */
vector<int> max_line_length_b (ifstream& infile) {
  
  //declare variables for line and max length
  string line;
  size_t max = 0;
  size_t counter = 0;
  string prev_char;
  string current_char;
  vector<int> result(2, 0);

  //get each line and find the largest line
  while (getline (infile, line)) {
    for (size_t i = 0; i < line.length(); i++) {
      current_char = line[i];
      if (counter == 0) {
	if (current_char == " ")
	  prev_char = line[i];
	else {
	  prev_char = line[i];
	  counter = 1;
	}
      }
      else {
	if (prev_char == " " && current_char == " ") 
	  prev_char = line[i];
	else {
       if ((i == (line.length() - 1)) && (current_char == " "))
	     prev_char = line[i];
       else {
         prev_char = line[i]; 
	     counter++;
       }
	}
      }
    }
    if (counter > max) {
      max = counter;
      result[0] = max;
      result[1] = 1;
    }
    else if (counter == max)
      result[1] += 1;
     
     counter = 0;
  }

  return result;
}

/* find the words that are of the longest word length and stores them
   in a map where keys -> words & values -> # of occurences */ 
map<string, int> max_words_length (ifstream& infile) {

  // declare variables for max length, output map, word
  // map -> (word, #number of occurences)
  map<string, int> output;
  size_t max = 0;
  string word;
  map<string, int>::iterator it;

  /* reads in each word in the file, then do the following:
     - if word length is more than current max then set new max
       and set output to be just that word w/ one occurence
     - if word length is max, and word is not already in output then 
       add it to output string, if it is in then increment the key's
       occurence by 1
     - if word length is smaller than max, skip it          */
  while (infile >> word) {
    if (word.length() > max) {
      max = word.length();
      output.clear();
      output.insert(pair<string, int>(word, 1));
    }
    else if (word.length() == max) {
      it = output.find(word);
      if (it != output.end())    // word is already in map
	output[word] += 1;
      else
	output.insert(pair<string, int>(word, 1));
    }
  }

  return output;
  
}

// will get the name of file from argument (i.e text.txt -> text)
void print_file_name (string const& str) {

  // decalre the char where the substring stops
  string delim = ".";

  // prints out the name of the file
  string output;
  output = str.substr(0, str.find(delim));
  cout << output << ":" << endl;
}

// prints out just the words in the map with commas separating
void print_words (map<string, int> m) {

  // declare variables
  map<string, int>::iterator it;

  //run through list, store string to result in order to trim last comma 
  for (it = m.begin(); it != m.end(); it++)
    if (it != --m.end())
      cout << it->first << ", ";
    else
      cout << it->first << endl;

}

// print out the length of the longest line
void print_max_line_length (vector<int> a) {
  cout << a.at(0) << endl;
}

// prints out the length of the longest line with c flag
void print_max_line_length_c (vector<int> a) {
  cout << a.at(0) << "(" << a.at(1) << ")" << endl;
}

// prints out all words in the map with the number of occurences
void print_words_c (map<string, int> m) {

  // declare variables
  map<string, int>::iterator it;

   //run through list, store string to result in order to trim last comma 
  for (it = m.begin(); it != m.end(); it++) {
    if (it != --m.end())
      cout << it->first << "(" << it->second << "), ";
    else
      cout << it->first << "(" << it->second << ")" << endl;
  }

}

void print_words_m (map<string, int> m) {

  //decalre variables
  int max = 0;
  map<string, int>::iterator it;
  map<string, int> result;
  
  //run through the list and find the max # of occurences 
  for (it = m.begin(); it != m.end(); it++) {
    if (it->second > max)
      max = it->second;
  }

  //add words that have the max occurences to result map
  for (it = m.begin(); it != m.end(); it++) {
    if (it->second == max){
      result.insert(pair<string, int>(it->first, it->second));
    }
  }

  //run through list, store string to result in order to trim last comma 
  for (it = result.begin(); it != result.end(); it++) {
    if (it != --result.end())
      cout << it->first << ", ";
    else
      cout << it->first << endl;
  }
}

void print_words_cm (map<string, int> m) {

  //decalre variables
  int max = 0;
  map<string, int>::iterator it;
  map<string, int> result;
  
  //run through the list and find the max # of occurences 
  for (it = m.begin(); it != m.end(); it++) {
    if (it->second > max)
      max = it->second;
  }

  //add words that have the max occurences to result map
  for (it = m.begin(); it != m.end(); it++) {
    if (it->second == max){
      result.insert(pair<string, int>(it->first, it->second));
    }
  }

  //run through list, store string to result in order to trim last comma 
  for (it = result.begin(); it != result.end(); it++) {
    if (it != --result.end())
      cout << it->first << "(" << it->second << ")" << ", ";
    else
      cout << it->first << "(" << it->second << ")" << endl;
  }
}
