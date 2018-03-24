class Solution {
    int up, down, left, right;
    void dfs(char[][] image, boolean[][] visited, int x, int y) {
        if(x < 0 || x >= image.length || y < 0 || y >= image[0].length) return;
        if(image[x][y] != '1' || visited[x][y]) return;
        visited[x][y] = true;
        up = Math.min(up, x);
        down = Math.max(down, x);
        left = Math.min(left, y);
        right = Math.max(right, y);
        dfs(image, visited, x - 1, y);
        dfs(image, visited, x, y - 1);
        dfs(image, visited, x + 1, y);
        dfs(image, visited, x, y + 1);
    }
    public int minArea(char[][] image, int x, int y) {
        up = left = Integer.MAX_VALUE;
        down = right = Integer.MIN_VALUE;
        boolean[][] visited = new boolean[image.length][];
        for(int i = 0; i < image.length; ++i)
            visited[i] = new boolean[image[i].length];
        dfs(image, visited, x, y);
        return (down - up + 1) * (right - left + 1);
    }
}