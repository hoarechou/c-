#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

bool isPrime(int x)
{
    for(int i = 2; i*i <= x; ++i){
        if(x % i == 0)
            return 0;
    }
    return 1;
}
vector<int> create_prime_table(int n)
{
    vector<int> vec;
    for(int x = 2; x <= n; ++x){
        if(isPrime(x))
            vec.push_back(x);
    }
    return vec;
}
void print_ans(vector<int>& ans,int n)
{
    vector<int>::iterator it;
    int count = 0;

    cout<<setw(3)<<n<<"!"<<" "<<"=";
    for(it = ans.begin(); it != ans.end(); ++it){
         cout<<setw(3)<<*it;
         count++;
         if(count%15 == 0 && count < ans.size())
            cout<<endl<<setw(6)<<" ";
    }
    cout<<endl;
}
vector<int> factorize_factorial(vector<int> p_table, int n)
{
    int prime_factor_count = 0;
    int d = 0;
    vector<int>::iterator it;
    vector<int> ans;
    for(it = p_table.begin(); it != p_table.end()&& *it <= n; ++it){
        d = *it;
        while(d <= n){
            prime_factor_count += n/d;
            d *= *it;
        }
        ans.push_back(prime_factor_count);
        prime_factor_count = 0;
    }
    return ans;
}
int main()
{

    vector<int> p_table= create_prime_table(200);
    vector<int> ans;
    int n = 0;
    while(cin>>n){
        if(n==0)
            break;
        ans = factorize_factorial(p_table, n);
        print_ans(ans,n);

    }
    return 0;
}
