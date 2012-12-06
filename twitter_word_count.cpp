#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <vector>
using std::cout;
using std:: endl;
using namespace std;

int main(int argc, char** argv) {
		
	if (argc!=2) {
		cout << "Please enter text file of tweets!" << endl;
		return 0;
	}

	//open output file	
	ofstream output_file;
	output_file.open("output.txt");
	
	//open input file
	ifstream myfile;
	myfile.open(argv[1]);
	
	map <string, int> tweet_words;
	map <string, int>::iterator it;
	map <int, vector<string>* > tweets_by_count;
	
	int overall_counter = 0;
	int unique_counter = 0;
	double lexical_diversity;
	
	//make a map of word keys with their count
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
	
	//populate map of int counter keys, values of strings
	for (it = tweet_words.begin(); it != tweet_words.end(); it++) {

		//if int key exists get vector add to it
		if (tweets_by_count.count((*it).second)) {
			vector<string>* temp_vector_pointer = (tweets_by_count[(*it).second]);
			(*temp_vector_pointer).push_back((*it).first);
		}
		
		//if int key doesn't exist, insert new vector	
		else {
			vector<string>* curr_vector_pointer = new vector<string>;
			curr_vector_pointer->push_back((*it).first);
			tweets_by_count.insert(pair<int, vector<string>* >((*it).second, curr_vector_pointer));	
		}
	}
	
	//pipe meta to output.txt file
	output_file << "Args entered: " << argc << endl;
	output_file << "Found: " << unique_counter << " unique words." << endl;	
	output_file << "Found: " << overall_counter << " overall words." << endl;	
	lexical_diversity = ((double)overall_counter)/unique_counter;
	output_file << "Lexical Diversity: " <<  lexical_diversity << endl;
	
	//reverse iterator
	map <int, vector<string>* >::reverse_iterator rit;
		
	//pipe word count reversively
	for (rit = tweets_by_count.rbegin(); rit != tweets_by_count.rend(); rit++) {
			
			vector<string>* temp_vector = (*rit).second;
			for (unsigned i=0; i<(*temp_vector).size() ; i++)
				output_file << (*rit).first << "\t" << (*temp_vector)[i] << endl;
	}
	
	return 0;
}
