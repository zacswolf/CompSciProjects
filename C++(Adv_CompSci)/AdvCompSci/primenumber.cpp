#include <iostream>
#include <vector>

using namespace std;

vector<int> primeNumbers(int high){
	vector<int> primes;
	primes.push_back(2);
	//cout << primes[0]<< endl;//couting
	bool isPrime;
	//int n = 1;//couting primes
	for (int i =3; i < high; i+=2){
		isPrime=true;
		for (int j=0; j<primes.size(); j++){
			if(i%primes[j] == 0){
				isPrime = false;
				continue;
			}
		}
		if(isPrime){
			primes.push_back(i);
			
			//cout << primes[n]<< endl;//couting
			//n++;
		}
	}
	return primes;
}

vector<int> primeFactors(int num){
	int numcopy = num;
	vector<int> primesUnder = primeNumbers(num);
	vector<int> primesF;
	for (int i =0; i<primesUnder.size(); i++){
		if (num%primesUnder[i] ==0){
			primesF.push_back(primesUnder[i]);
			num = num / primesUnder[i];
			i--;
		}
	}
	if(primesF.size()==0){
		primesF.push_back(numcopy);
	}
	return primesF;
}


vector<int> fastPrimeFactors(int num){//no number theory formulas
	vector<int> primesF;
	vector<int> primes;
	primes.push_back(2);
	//cout << primes[0]<< endl;//couting
	bool isPrime;
	bool skip = false;
	//int n = 1;//couting primes
	
	int fits=num;
	
	for (int i =2; i<=2; i++){
		if (fits%2 ==0){
			primesF.push_back(2);
			fits/=2;
			i--;
		}
	}
	
	
	for (int i =3; i <= fits; i+=2){
		//cout << i << " is first i"<< endl;
		isPrime=true;
		if (skip == true){
			isPrime = true;
			//cout<<"skip\n";
		}
		else{
			for (int j=0; j<primes.size(); j++){
			
				if(i%primes[j] == 0){
					isPrime = false;
					continue;
				}
			
			}
		}
		
		if(isPrime){
			//cout<<"isPrime\n";
			if (skip){
				skip = false;
			}
			else{
				primes.push_back(i);
			}
			if(fits%i==0){
				fits/=i;
				primesF.push_back(i);
				i-=2;
				skip =true;
			}
			
		}

	}
	
	return primesF;
}


int main(){
	vector<int> primes;
	//primes = primeNumbers(946984498);
	primes = fastPrimeFactors(1);
	//cout << primes.size() << " is size\n";
	//cout <<primes[primes.size()-1];
	for (int i =0; i < primes.size(); i++){
		cout << primes[i]<< endl;
	}
	return 0;
}