class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!denominator) return "";
        if(!numerator) return "0";
        
        long nume = numerator;
        long deno = denominator;
        nume = abs(nume);
        deno = abs(deno);
        
        string sign = (numerator > 0 != denominator > 0) ? "-": "";
        
        string intPart = to_string(nume / deno);
        
        string deciPart = "";
        map<long, int> mp;
        
        nume %= deno;
        nume *= 10;

        while(nume) {
            mp[nume] = deciPart.size();
            if(nume < deno) {
                deciPart += "0";
            } else {
                deciPart += to_string(nume/deno);
                nume %= deno;
            }
            nume *= 10;
            if(mp.find(nume) != mp.end()) {
                int idx = mp[nume];
                deciPart = deciPart.substr(0, idx) + "(" + deciPart.substr(idx) + ")";
                break;
            }
        }
        if(deciPart.size())
            return sign + intPart + "." + deciPart;
        return sign + intPart;
    }
};
