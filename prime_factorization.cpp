#include <iostream>
#include <cmath>	//for sqrt, can make calculations so much faster
#include <vector>	//for prime list and factors for a number
using namespace std;


bool isPrime (long long int num, vector<int> &primes);

void primeFactorization (long long int num, vector<int> &primes, vector<int> current_factorization);


int main (void)
{

	//using vectors so I don't have to have a theoretical max it can go over. Plus I like vectors
	vector<int> primes;
	vector<int> current_factorization;

	long long int input = 0;


	cout << "What number greater than 1 to check, enter -1 to quit: ";
	cin >> input;
	while (input != -1)
	{
		if (input <=1)
		{
			cout << "There exists no prime factorization for a number less than 2\n";
			cout << "Enter a number greater than 1 to check, enter -1 to quit: ";
			cin >> input;
		}
		else
		{
			primeFactorization(input, primes, current_factorization);
			cout << "Enter another number greater than 1 to check, enter -1 to quit: ";
			cin >> input;
		}
	}

	return 0;
}




bool isPrime (long long int num, vector<int> &primes)
{

	long long int max_possible_prime = sqrt(num); //max possible prime of x is root(x)

	for (long long int check_num : primes)	//checks to see if the current number is already in list of primes
	{
		if (check_num == num)	//if the current number is already in the list of primes we don't need to do any calculations and can immedietly return true
		{
			return true;
		}
	}



	if (num <= 1)	//min prime is 2
	{
		return false;
	}


	
	if (num == 2) //special case for 2 as it's only even prime
	{
		primes.push_back(num);
		return true;
	}
	
	
	for (long long int i = 2; i <= max_possible_prime; i++) //this works by checking if num is divisible by any number other then 1
	{
		if (num % i == 0) //if a factor other then 1 exists then we know the number isn't a prime number
		{
			return false;
		}
	}


	primes.push_back(num);	//if we got here we know the number is a prime number so we add it to the prime vector
	return true;

}



void primeFactorization (long long int num, vector<int> &primes, vector<int> current_factorization)
{
	long long int original_num = num;

	for (long long int i = 2; i <= num; i++)
	{
		//while number we're factorizing is divisible by i
		while (num % i == 0) //while instead of if as we can have multiple of same factors
		{
			if (isPrime(i, primes)) //checks if i is prime or not
			{
				current_factorization.push_back(i); //if a number is prime we push it onto the factorization vector
			}

			num /= i;	//divides num by i as we know i is a factor.
		}
	}

	
	
	//show the factors
	cout << "Prime Factors for " << original_num << ": ";
	for (long long int counter : current_factorization)
	{
		cout << counter << " ";
	}
	cout << "\n";
	
	return;
}

