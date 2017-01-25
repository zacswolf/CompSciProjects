#include <iostream>
#include <string>
#include <vector>
using namespace std;

int occurrences(string IN, string find){
	int start = 0;
	int occur=0;
	while (IN.find(find, start) != -1){
		start=IN.find(find, start) +find.length();
		occur++;
	}
	return occur;
}

int wordCount(string IN){
	int start=0;
	int occur=1;	
	while (IN.find(" ", start) != -1){
		if (!((int)IN.at(IN.find(" ", start)-1)>=48 && (int)IN.at(IN.find(" ", start)-1)<=57)){
			occur++;
		}
		start=IN.find(" ", start) + 1;
	}
	return occur;
}



int numSentences(string IN){
	int start = 0;
	int sen = 0;
	while (IN.find(".", start) != -1){
		sen++;
		start=IN.find(".", start) + 1;
	}
	return sen;
}

double avgNumWordsPerSen(string IN){
	return double(wordCount(IN))/ numSentences(IN);
}

double uniqueWords(string IN){
	vector<string> used;
	int start=0;
	int unique=1;
	string word;
	int wordcount=0;//stores the number of words including numbers
	IN+= " ";
	while (IN.find(" ", start) != -1){
		wordcount++;
		start=IN.find(" ", start) + 1;
	}
	//cout << wordcount << endl;
	
	start = 0;
	int skip =0;
	
	for (int j = 0; j < wordcount; j++){
		/*cout << IN.length() << " length \n";
		cout << start << " start \n";
		cout << IN.find(" ", start) << " next space \n";*/
		int p =IN.at(IN.find(" ", start)-1);
		if((int)IN.at(IN.find(" ", start)-1)>=48&& (int)IN.at(IN.find(" ", start)-1)<=57){
			word = "";
			skip = 1;
		}
		else{
			word = IN.substr(start, IN.find(" ",start)-start);
			skip = 0;
			//cout << word << endl;
		}
		//cout << word << endl;
		
		
		if(skip == 1){
			//cout << "skiped\n";
		}
		else if(j==0){
			used.push_back(word);
			//cout << "pushed back first word: " << word << endl;
		}
		else{
			int skiped =0;
			for(int k=0;k<used.size();k++){
				if(word == used[k]){
					skiped =1;
					k++;
				}
			}
			if (skiped == 0){
				used.push_back(word);
				//cout << "pushed back: " << word << endl;
				unique++;
			}
		}
		start=IN.find(" ", start) + 1;
	}
	return unique;
}

double lex(string IN){
	return double(uniqueWords(IN))/wordCount(IN) *100;
}


int main(){
	string in = "I was born in Lousiana down on the ol bayou raised on shrimps and catfish mamas good gumbo. I got the ramblin fever. Said goodbye to ma and pa. Crossed that ol red river and this is what I saw. I saw miles and miles of Texas 1000 stars up in the sky. I saw miles and miles of Texas gonna live here till I die.";
	
	cout << "Occurrences of the word \"is\": " << occurrences(in, "is") << endl;
	cout << "Number of actual words: " << wordCount(in) << endl;
	cout << "Number of sentences: " <<numSentences(in) << endl;
	cout << "Average number of words per sentence: " << avgNumWordsPerSen(in) << endl;
	cout << "Number of unique words: " << uniqueWords(in) << endl;
	cout << "Lexical Density: " << lex(in) << endl;
	
	return 0;
	
}