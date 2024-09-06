class Solution {
public:
    int getLucky(string s, int k) {
        int total = 0;
        for (int i = 0; i < s.size(); ++i) {
       
            int convert = (s[i] - 'a');
           
            convert = convert + 1;
            
            while (convert) {
                int res = convert % 10;
                convert /= 10;
                total += res;
            }
        }
        
        
        while (k > 1) {
            int dummy_total = total;
            total = 0;

            while (dummy_total) {
                int res = dummy_total % 10;
                dummy_total /= 10;
                total += res;
            }
            
            k--;
        }
        return total;
    }
};