class Solution {
public:
   
 void solve(int c, vector < string > & mat, vector < vector < string >> & ans, vector < int > & lr, vector < int > & ud, vector < int > & ld, int n)
 {
      if (c == n)
      {
        ans.push_back(mat);
        return;
      }
      for (int row = 0; row < n; row++)
      {
        if (lr[row] == 0 && ld[row + c] == 0 && ud[n - 1 + c - row] == 0) {
          mat[row][c] = 'Q';
          lr[row] = 1;
          ld[row + c] = 1;
          ud[n - 1 + c - row] = 1;
          solve(c + 1, mat, ans, lr, ud, ld, n);
          mat[row][c] = '.';
          lr[row] = 0;
          ld[row + c] = 0;
          ud[n - 1 + c - row] = 0;
        }
      }
    }

  public:
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > mat(n);
      string s(n, '.');
      for (int i = 0; i < n; i++)
      {
        mat[i] = s;
      }
      vector < int > lr(n, 0), ud(2 * n - 1, 0), ld(2 * n - 1, 0);
      solve(0, mat, ans, lr, ud, ld, n);
      return ans;
    }
};