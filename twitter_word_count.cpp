#include <string>
#include <iostream>
#include <map>:
#include <fstream>
using std::cout;
using std:: endl;
using namespace std;

int main(int argc, char** argv) {
	
	cout << "Args entered: " << argc << endl;
	
	ofstream output_file;
	output_file.open("output.txt");
	
	map <string, int> tweet_words;
	map <string, int>::iterator it;
	map <int, string> tweet_words_count;
	map <int, string>::iterator it_count;
	
	int overall_counter;
	int unique_counter;
	
	ifstream myfile;
	myfile.open(argv[1]);
	
	//make a map of word keys with count
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			overall_counter++;
			
			string curr_word;
			myfile >> curr_word;
						
			if (tweet_words.count(curr_word)) {
				int temp = tweet_words[curr_word];
				tweet_words.erase(curr_word);	
				tweet_words.insert(pair<string, int>(curr_word, ++temp));
			}
			else {
				tweet_words.insert(pair<string, int>(curr_word, 1));
				unique_counter++;
			}	
		}
	}
	
	//make a new map of counts with word keys
	for (it = tweet_words.begin(); it != tweet_words.end(); it++) {
			//cout << (*it).first << "\t" << (*it).second << endl;
			tweet_words_count.insert(pair<int, string>((*it).second, (*it).first));
	}
		
	for (it_count = tweet_words_count.end(); it_count != tweet_words_count.begin(); it_count--) {
			output_file << (*it_count).first << "\t" << (*it_count).second << endl;
			//output_file << (*it_count).first;
	}
	
	
	cout << "Found: " << unique_counter << " unique words." << endl;	
	cout << "Found: " << overall_counter-1 << " overall words." << endl;	
	
	return 0;
}
