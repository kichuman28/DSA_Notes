class Solution {
public:

    void findDFS(vector<vector<int>>& image, int sr, int sc, int color, int defaultColor){
        int n = image.size();
        int m = image[0].size();
        image[sr][sc] = color;

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++){
            int nRow = sr + dRow[i];
            int nCol = sc + dCol[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == defaultColor){
                findDFS(image, nRow, nCol, color, defaultColor);
            }
        }
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int defaultColor = image[sr][sc];
        if(defaultColor == color) return image; //if the given color and the color to be changed are same then no change just return the same image.
        int n = image.size();
        int m = image.size();
        findDFS(image, sr, sc, color, defaultColor);
        return image;
    }
};

//Approach:
//1) We just need to do a dfs traversal of the given node (sr, sc).
//2) Edge Cases to handle : When the given color and default color and same. 


//Time complexity: O(NxM). At max it covers the whole matrix.
//Space complexity: O(NxM) + O(NxM). One if for storing the answer, other is for the recursive stack space.