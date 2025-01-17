class Solution {
 public:
  bool checkValidString(const string& s) {
    int low = 0,high = 0; 
    for (const char c : s) {
      switch (c) {
        case '(':
          ++low;
          ++high;
          break;
        case ')':
          low = max(0, --low);
          --high;
          break;
        case '*':
          low = max(0, --low);
          ++high;
          break;
      }
      if (high < 0)
        return false;
    }
    return low == 0;
  }
};