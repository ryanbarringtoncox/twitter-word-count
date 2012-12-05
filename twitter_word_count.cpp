#include <string>tweet_out_it
#include <iostream>tweets_by_count
#include <map>:
#include <fstream>
#include <vector>
using std::cout;
using std:: endl;
using namespace std;

int main(int argc, char** argv) {
	
	cout << "Args entered: " << argc << endl;
	
	if (argc!=2) {
			cout << "Please enter text file of tweets!" << endl;
			return 0;
	}
	
	ofstream output_file;
	output_file.open("output.txt");
	
	map <string, int> tweet_words;
	map <string, int>::iterator it;
	map <int, vector<string> > tweets_by_count;
	map <int, vector<string> >::iterator tweet_out_it;
	
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
	
	//make a new map of count keys and string vector values
	for (it = tweet_words.begin(); it != tweet_words.end(); it++) {
			cout << (*it).first << "\t" << (*it).second << endl;
			//tweets_by_count.insert(pair<int, string>((*it).second, (*it).first));

			//if int key exists get vector as temp, add to it, remove and then insert anew
			if (tweets_by_count.count((*it).second)) {
				
				//int local_key = (*it).second;
				
				//vector<string> temp_vector = tweets_by_count[local_key];
				//temp_vector.push_back("test");

				//((*it).second);
				//vector<string> curr_vector = (*it).first;
				
				//Must delete curent entry
						
			}
		
			else {
				//if int key doesn't exist, insert			
				vector<string> curr_vector;
				curr_vector.push_back((*it).first);
				tweets_by_count.insert(pair<int, vector<string> >((*it).second, curr_vector));	
			}
	}
		
	//pipe it
	for (tweet_out_it = tweets_by_count.begin(); tweet_out_it != tweets_by_count.end(); tweet_out_it++) {
			
			//output_file << (*tweet_out_it).first << "\t" << (*tweet_out_it).second << endl;
			output_file << (*tweet_out_it).first << " occurrences:" << endl;
			
			vector<string> temp_vector = (*tweet_out_it).second;
		
			for (unsigned i=0; i<temp_vector.size() ; i++)
				output_file << temp_vector[i] << " ";
			output_file << '\n';
		;
		
		
	}
	
	//write out map of vectors.  each line has int key followed by string of vectors
	
	cout << "Found: " << unique_counter << " unique words." << endl;	
	cout << "Found: " << overall_counter << " overall words." << endl;	
	
	return 0;
}
