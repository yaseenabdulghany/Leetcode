class Solution {
public:
    long long coloredCells(int n) {
        long long steps = n;
        long long mainLines = steps * steps;
        long long secondaryLines = (steps - 1) * (steps - 1);
        return mainLines + secondaryLines;
    }
};