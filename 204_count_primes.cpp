/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
// for some reason this method is broken, time limit exceeded..
// maybe the checking is too slow
// ok yeah it is slower because of the constant (reference): https://codeforces.com/blog/entry/61700
class Solution {
public:
    int countPrimes(int n) {
    // store the list of primes
    vector<int> list_prime;
    // the ith element of this vector is to indicate if the number i is a prime
    // initialize as all true
    // don't use int here, heap overflow
    vector<bool> is_prime(n, true);
    // the ith element of this vector is the lowest prime factor of the number i
    vector<int> lowest_prime_factor(n);
        int cnt_prime = 0;
        for (int i = 2; i < n; ++i) {
            if (is_prime[i]) {
                list_prime.push_back(i);
                // the lowest prime factor of a prime number is itself
                lowest_prime_factor[i] = i;
                cnt_prime++;
            }
            int prime_sz = list_prime.size();
            for (int j = 0;
                j < prime_sz && 
                i * list_prime[j] < n && 
                list_prime[j] <= lowest_prime_factor[i]; ++j) {
                    is_prime[i * list_prime[j]] = false;
                    lowest_prime_factor[i * list_prime[j]] = list_prime[j];
            }
        }
        return cnt_prime;
    }
};

/**
 * Time Complexity: O(nlglgn)
 * Space Complexity: O(n)
 */
// why O(nlglgn)?
// the amount of loop iterated is 
// n/2 + n/3 + n/5 .......+ p
// n (1/2 + 1/3 + .....)
// 1/2 + 1/3 + ..... = lg lg n
// so O(n lg lg n)
class Solution {
public:
    int countPrimes(int n) {
        // the ith element of this vector is to indicate if the number i is a prime
        // initialize as all true
        // don't use int here, heap overflow
        vector<bool> is_prime(n, true); 
        // the ith element of this vector is the lowest prime factor of the number i
        vector<int> lowest_prime_factor(n);
        int cnt_prime = 0;
        for (int p = 2; p * p < n; ++p) {
            if (is_prime[p]) {
                for (int j = p * p; j < n; j+=p) {
                    is_prime[j] = false;
                }
            }
        }

        for (int i = 2; i < n; ++i) {
            if (is_prime[i]) cnt_prime++;
        }
        return cnt_prime;
    }
};