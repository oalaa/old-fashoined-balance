#include <iostream>
#include <vector>

using namespace std;

// Function is measurable that return true or false true if target and weights are equal
bool IsboolMeasurable(int target , vector <int>& weights ,int currentWeight )
{
    if (target == 0)
        return true ; // base case of function

    if (currentWeight >= weights.size())
        return false ; // base case of this function

    return (IsboolMeasurable(target + weights[currentWeight],weights , currentWeight+1 ) || IsboolMeasurable(target , weights , currentWeight+1)
                                 ||IsboolMeasurable(target-weights[currentWeight],weights , currentWeight+1) );
}

// function that return another function
bool IsMeasurable(int target,vector <int>& weights )
{
    return IsboolMeasurable(target, weights, 0);
}



int main()
{
    vector <int> weights;
    weights.push_back(1);
    weights.push_back(4);
    cout << IsMeasurable(2,weights);
    return 0;
}
