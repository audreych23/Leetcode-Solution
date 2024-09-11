class Solution {
public:
    int minBitFlips(int start, int goal) {
        if (start < goal) {
            swap(start, goal);
        }
        int count = 0;
        // goal will always be smaller
        while (start) {
            if ((start & 1) != (goal & 1)) {
                count++;
            } 
            start >>= 1;
            goal >>= 1;
        }
        return count;
    }
};