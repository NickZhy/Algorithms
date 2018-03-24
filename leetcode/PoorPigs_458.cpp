class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // number of states is the key to solve the problem.
        // if one pig can have m states, n pigs can provide the m^n situations. 
        // if we efficiently encode the information, there always exist one way
        // to find out solution with ceil[log_states(bucket)] pigs
        
        int states = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(states));
    }
};