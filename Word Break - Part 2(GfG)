//This code is in language C++
//The link to the problem is - https://practice.geeksforgeeks.org/problems/word-break-part-23249/1
//Code - 
vector<string> wordBreak(int n, vector<string>& dict, string s) {
  unordered_set<string> dictSet(dict.begin(), dict.end());
  vector<vector<string>> memo(s.length() + 1, vector<string>());
  
  memo[0].push_back("");
  
  for (int i = 1; i <= s.length(); i++) {
      for (int j = 0; j < i; j++) {
          string word = s.substr(j, i - j);
          if (dictSet.count(word)) {
              for (string prev : memo[j]) {
                  memo[i].push_back(prev + (prev.empty() ? "" : " ") + word);
              }
          }
      }
  }
  
  return memo[s.length()];
}
